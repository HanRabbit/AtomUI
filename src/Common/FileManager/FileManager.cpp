#include "FileManager.h"
#include "Common/Log/Log.h"

FileManager File_Manager;

String FileManager::f_read(file_str_t f_path) {
    if (lv_fs_is_ready(LV_FS_FATFS_LETTER)) {
        lv_fs_file_t file;
        lv_fs_res_t res;
        uint32_t bytes;
        String buffer;

        /* 打开文件，准备读取 */
        res = lv_fs_open(&file, f_path, LV_FS_MODE_RD);

        if (res != LV_FS_RES_OK) {
            USB_log.out("File open for reading failed");

            USB_log.LOG_USE_FS = false;

            lv_fs_close(&file);
            return "";
        }

        res = lv_fs_read(&file, &buffer, sizeof(buffer) - 1, &bytes);

        buffer[bytes] = '\0';

        if (res != LV_FS_RES_OK || bytes == 0) {
            USB_log.out("Failed to read file");

            USB_log.LOG_USE_FS = false;

            lv_fs_close(&file);
            return "";
        }

        USB_log.out("Read bytes from file");

        lv_fs_close(&file);
        return buffer.c_str();
    } else {
        return "";
    }
}

bool FileManager::f_write(file_str_t f_path, file_str_t data, bool is_append) {
    if (lv_fs_is_ready(LV_FS_FATFS_LETTER)) {
        lv_fs_file_t file;
        lv_fs_res_t res;
        uint32_t byte_written = 0;

        /* 打开（创建）文件，准备写入数据 */
        USB_log.out("Attempting to open file");
        res = lv_fs_open(&file, f_path, LV_FS_MODE_WR);

        if (res != LV_FS_RES_OK) {
            /* 打开文件失败 */
            USB_log.out("File open for writing failed");

            USB_log.LOG_USE_FS = false;

            /* 关闭文件 */
            lv_fs_close(&file);
            return false;
        }

        if (is_append) {
            res = lv_fs_seek(&file, 0, LV_FS_SEEK_END);

            if (res != LV_FS_RES_OK) {
                USB_log.out("Failed to seek to end of file");
                lv_fs_close(&file);
                return false;
            }
        }

        USB_log.out("Writing data to file");
        res = lv_fs_write(&file, data, strlen(data), &byte_written);

        if (res != LV_FS_RES_OK || byte_written != strlen(data)) {
            /* 文件写入失败 */
            USB_log.out("Failed wrote");

            /* 关闭文件 */
            lv_fs_close(&file);
            return false;
        } else {
            /* 写入文件成功 */
            USB_log.out("Successfully wrote");

            /* 关闭文件 */
            lv_fs_close(&file);
            return true;
        }
    }

    return false;
}

/**
 * @brief 日志文件输出
 * @param log_data 日志内容
 */
void FileManager::log(file_str_t log_data) {
    f_write(FILE_LOG_PATH, log_data, true);
}

/**
 * @brief 输出 .cfg 配置文件，格式为 JSON
 * @param json JsonDocument 对象
 * @param cfg_path .cfg 配置文件路径
 * @return
 */
bool FileManager::cfg_write(const ArduinoJson::JsonDocument& json, file_str_t cfg_path) {
    char buf[measureJson(json) + 1];
    /* 将 JSON 序列化 */
    serializeJson(json, buf, measureJson(json) + 1);

    /* 输出到文件 */
    if (f_write(cfg_path, buf, false))  return true;
    else return false;
}

JsonDocument FileManager::cfg_read(file_str_t cfg_path) {
    JsonDocument json;
    String json_str = f_read(FILE_CONFIG_WIFI_PATH);

    /* 将 JSON 反序列化 */
    deserializeJson(json, json_str);

    USBSerial.println(json_str);

    return json;
}
