#include "StorageService.h"
#include "ArduinoJson.h"
#ifdef ARDUINO
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif
#include <algorithm>
#define JSON_BUFFER_SIZE 1024

#define VALUE_TO_DOC(type)\
do{\
    type value = 0;\
    size_t size = iter->size > sizeof(value) ? sizeof(value) : iter->size;\
    memcpy(&value, iter->value, size);\
    doc[iter->key] = value;\
}while(0)

#define DOC_TO_VALUE(type)\
do{\
    type value = doc[iter->key];\
    size_t size = iter->size < sizeof(value) ? iter->size : sizeof(value);\
    memcpy(iter->value, &value, size);\
}while(0)

class FileWrapper
{
public:
    FileWrapper(const char* path, lv_fs_mode_t mode)
    {
        memset(&file, 0, sizeof(file));
        fs_res = lv_fs_open(&file, path, mode);
    }

    ~FileWrapper()
    {
        lv_fs_close(&file);
    }

    uint8_t read()
    {
        uint8_t data;
        readBytes(&data, 1);
        return data;
    }

    size_t readBytes(void* buffer, size_t length)
    {
        uint32_t br;
        lv_fs_read(&file, buffer, length, &br);
        return br;
    }

    size_t write(uint8_t c)
    {
        return write(&c, 1);
    }

    size_t write(const uint8_t* s, size_t n)
    {
        uint32_t bw;
        lv_fs_write(&file, s, n, &bw);
        return bw;
    }

    operator bool()
    {
        return fs_res == LV_FS_RES_OK;
    };

private:
    lv_fs_res_t fs_res;
    lv_fs_file_t file;
};

StorageService::StorageService(const char* filepath)
{
    FilePath = filepath;
}

StorageService::~StorageService()
{

}

bool StorageService::Add(const char* key, void* value, uint16_t size, DataType_t type)
{
    Node_t* findNode = SearchNode(key);
    if (findNode != nullptr)
    {
        return false;
    }

    Node_t* node = new Node_t;
    node->key = key;
    node->value = value;
    node->size = size;
    node->type = type;

    NodePool.push_back(node);

    return true;
}

bool StorageService::Remove(const char* key)
{
    Node_t* node = SearchNode(key);

    if (node == nullptr)
    {
        return false;
    }

    auto iter = std::find(NodePool.begin(), NodePool.end(), node);

    if (iter == NodePool.end())
    {
        return false;
    }

    NodePool.erase(iter);
    delete node;

    return true;
}

bool StorageService::LoadFile()
{
    FileWrapper file(FilePath, LV_FS_MODE_RD);

    if (!file)
    {
        LV_LOG_USER("Failed to open file: %s", FilePath);
        return false;
    }

    StaticJsonDocument<JSON_BUFFER_SIZE> doc;

    // Deserialize the JSON document
    DeserializationError error = deserializeJson(doc, file);
    if (error)
    {
        LV_LOG_USER("Failed to read file: %s", FilePath);
        return false;
    }

    // Copy values from the JsonDocument to the Config
    for (auto iter : NodePool)
    {
        if (!doc.containsKey(iter->key))
        {
            LV_LOG_USER("NOT contains key: %s, use default value", iter->key);
            continue;
        }

        switch (iter->type)
        {
        case TYPE_INT:
        {
            DOC_TO_VALUE(int);
            break;
        }
        case TYPE_FLOAT:
        {
            DOC_TO_VALUE(float);
            break;
        }
        case TYPE_DOUBLE:
        {
            DOC_TO_VALUE(double);
            break;
        }
        case TYPE_STRING:
        {
            const char* str = doc[iter->key];
            if (str)
            {
                strncpy((char*)iter->value, str, iter->size);
            }
            break;
        }
        default:
            break;
        }
    }

    return true;
}

bool StorageService::SaveFile()
{
    // Open file for writing
    FileWrapper file(FilePath, LV_FS_MODE_WR | LV_FS_MODE_RD);
    if (!file)
    {
        LV_LOG_USER("Failed to open file");
        return false;
    }

    // Allocate a temporary JsonDocument
    // Don't forget to change the capacity to match your requirements.
    // Use https://arduinojson.org/assistant to compute the capacity.
    StaticJsonDocument<JSON_BUFFER_SIZE> doc;

    // Set the values in the document
    for (auto iter : NodePool)
    {
        switch (iter->type)
        {
        case TYPE_INT:
        {
            VALUE_TO_DOC(int);
            break;
        }
        case TYPE_FLOAT:
        {
            VALUE_TO_DOC(float);
            break;
        }
        case TYPE_DOUBLE:
        {
            VALUE_TO_DOC(double);
            break;
        }
        case TYPE_STRING:
        {
            doc[iter->key] = (const char*)iter->value;
            break;
        }
        default:
            break;
        }
    }

    // Serialize JSON to file
    if (serializeJsonPretty(doc, file) == 0)
    {
        LV_LOG_USER("Failed to write to file");
        return false;
    }

    return true;
}

StorageService::Node_t* StorageService::SearchNode(const char* key)
{
    for (auto iter : NodePool)
    {
        if (strcmp(key, iter->key) == 0)
        {
            return iter;
        }
    }
    return nullptr;
}
