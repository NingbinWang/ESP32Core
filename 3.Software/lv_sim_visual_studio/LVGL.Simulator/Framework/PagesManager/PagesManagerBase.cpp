﻿#include "PagesManager.h"
#include "PM_Log.h"
#include <algorithm>

#define PM_EMPTY_PAGE_NAME "EMPTY_PAGE"

/**
  * @brief  Page manager constructor
  * @param  factory: Pointer to the page factory
  * @retval None
  */
PagesManager::PagesManager(PageFactory* factory)
    : Factory(factory)
    , PagePrev(nullptr)
    , PageCurrent(nullptr)
{
    memset(&AnimState, 0, sizeof(AnimState));

    SetGlobalLoadAnimType();
}

/**
  * @brief  Page manager destructor
  * @param  None
  * @retval None
  */
PagesManager::~PagesManager()
{
}

/**
  * @brief  Search pages in the page pool
  * @param  name: Page name
  * @retval A pointer to the base class of the page, or nullptr if not found
  */
PageBase* PagesManager::FindPageInPool(const char* name)
{
    for (auto iter : PagePool)
    {
        if (strcmp(name, iter->Name) == 0)
        {
            return iter;
        }
    }
    return nullptr;
}

/**
  * @brief  Search pages in the page stack
  * @param  name: Page name
  * @retval A pointer to the base class of the page, or nullptr if not found
  */
PageBase* PagesManager::FindPageInStack(const char* name)
{
    decltype(PageStack) stk = PageStack;
    while (!stk.empty())
    {
        PageBase* base = stk.top();

        if (strcmp(name, base->Name) == 0)
        {
            return base;
        }

        stk.pop();
    }

    return nullptr;
}

/**
  * @brief  Install the page, and register the page to the page pool
  * @param  className: The class name of the page
  * @param  appName: Page application name, no duplicates allowed
  * @retval A pointer to the base class of the page, or nullptr if wrong
  */
PageBase* PagesManager::Install(const char* className, const char* appName)
{
    if (Factory == nullptr)
    {
        PM_LOG_ERROR("Factory is not regsite, can't install page");
        return nullptr;
    }

    PageBase* base = Factory->CreatePage(className);
    if (base == nullptr)
    {
        PM_LOG_ERROR("Factory has not %s", className);
        return nullptr;
    }

    base->root = nullptr;
    base->ID = 0;
    base->Manager = nullptr;
    base->UserData = nullptr;
    memset(&base->priv, 0, sizeof(base->priv));

    base->onCustomAttrConfig();

    if (appName == nullptr)
    {
        PM_LOG_WARN("appName has not set");
        appName = className;
    }

    PM_LOG_INFO("Install Page[class = %s, name = %s]", className, appName);
    Register(base, appName);

    return base;
}

/**
  * @brief  Uninstall page
  * @param  appName: Page application name, no duplicates allowed
  * @retval Return true if the uninstallation is successful
  */
bool PagesManager::Uninstall(const char* appName)
{
    PM_LOG_INFO("Page(%s) uninstall...", appName);

    PageBase* base = FindPageInPool(appName);
    if (base == nullptr)
    {
        PM_LOG_ERROR("Page(%s) was not found", appName);
        return false;
    }

    if (!Unregister(appName))
    {
        PM_LOG_ERROR("Page(%s) unregister failed", appName);
        return false;
    }

    if (base->priv.IsCached)
    {
        PM_LOG_WARN("Page(%s) has cached, unloading...", appName);
        base->priv.State = PageBase::PAGE_STATE_UNLOAD;
        StateUpdate(base);
    }
    else
    {
        PM_LOG_INFO("Page(%s) has not cache", appName);
    }

    delete base;
    PM_LOG_INFO("Uninstall OK");
    return true;
}

/**
  * @brief  Register the page to the page pool
  * @param  name: Page application name, duplicate registration is not allowed
  * @retval Return true if the registration is successful
  */
bool PagesManager::Register(PageBase* base, const char* name)
{
    if (FindPageInPool(name) != nullptr)
    {
        PM_LOG_ERROR("Page(%s) was multi registered", name);
        return false;
    }

    base->Manager = this;
    base->Name = name;

    PagePool.push_back(base);

    return true;
}

/**
  * @brief  Log out the page from the page pool
  * @param  name: Page application name
  * @retval Return true if the logout is successful
  */
bool PagesManager::Unregister(const char* name)
{
    PM_LOG_INFO("Page(%s) unregister...", name);

    PageBase* base = FindPageInStack(name);

    if (base != nullptr)
    {
        PM_LOG_ERROR("Page(%s) was in stack", name);
        return false;
    }

    base = FindPageInPool(name);
    if (base == nullptr)
    {
        PM_LOG_ERROR("Page(%s) was not found", name);
        return false;
    }

    auto iter = std::find(PagePool.begin(), PagePool.end(), base);

    if (iter == PagePool.end())
    {
        PM_LOG_ERROR("Page(%s) was not found in PagePool", name);
        return false;
    }

    PagePool.erase(iter);

    PM_LOG_INFO("Unregister OK");
    return true;
}

/**
  * @brief  Get the top page of the page stack
  * @param  None
  * @retval A pointer to the base class of the page
  */
PageBase* PagesManager::GetStackTop()
{
    return PageStack.empty() ? nullptr : PageStack.top();
}

/**
  * @brief  Get the page below the top of the page stack
  * @param  None
  * @retval A pointer to the base class of the page
  */
PageBase* PagesManager::GetStackTopAfter()
{
    PageBase* top = GetStackTop();

    if (top == nullptr)
    {
        return nullptr;
    }

    PageStack.pop();

    PageBase* topAfter = GetStackTop();

    PageStack.push(top);

    return topAfter;
}

/**
  * @brief  Clear the page stack and end the life cycle of all pages in the page stack
  * @param  keepBottom: Whether to keep the bottom page of the stack
  * @retval None
  */
void PagesManager::SetStackClear(bool keepBottom)
{
    while (1)
    {
        PageBase* top = GetStackTop();

        if (top == nullptr)
        {
            PM_LOG_INFO("Page stack is empty, breaking...");
            break;
        }

        PageBase* topAfter = GetStackTopAfter();

        if (topAfter == nullptr)
        {
            if (keepBottom)
            {
                PagePrev = top;
                PM_LOG_INFO("Keep page stack bottom(%s), breaking...", top->Name);
                break;
            }
            else
            {
                PagePrev = nullptr;
            }
        }

        FourceUnload(top);

        PageStack.pop();
    }
    PM_LOG_INFO("Stack clear done");
}

/**
  * @brief  Get the name of the previous page
  * @param  None
  * @retval The name of the previous page, if it does not exist, return PM_EMPTY_PAGE_NAME
  */
const char* PagesManager::GetPagePrevName()
{
    return PagePrev ? PagePrev->Name : PM_EMPTY_PAGE_NAME;
}

