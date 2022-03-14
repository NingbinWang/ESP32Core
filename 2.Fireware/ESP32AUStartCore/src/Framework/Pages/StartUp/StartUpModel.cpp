#include "StartupModel.h"
#include "Framework/Notification/SystemNotify/SystemNotify.h"


using namespace Page;

void StartupModel::Init()
{
    account = new Notification("StartupModel", SystemNotify::Broker(), 0, this);
    //account->Subscribe("MusicPlayer");
}

void StartupModel::DeInit()
{
    if (account)
    {
        delete account;
        account = nullptr;
    }
}

void StartupModel::PlayMusic(const char* music)
{
   // DataProc::MusicPlayer_Info_t info;
   // info.music = music;
   // account->Notify("MusicPlayer", &info, sizeof(info));
}
