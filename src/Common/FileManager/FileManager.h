#ifndef ATOM_UI_LV9_FILE_MANAGER_H
#define ATOM_UI_LV9_FILE_MANAGER_H

#include <Arduino.h>
#include <lvgl.h>
#include <SD_MMC.h>
#include <ArduinoJson.h>

typedef const char *file_str_t;

/*
 * H:
 *   Atom
 *     | Config                                 配置文件
 *     |   | Wi-Fi.cfg
 *     |
 *     | Res                                    资源文件
 *     |   | UI
 *     |   |  | rottie
 *     |   |  | img
 *     |   |  | gif
 *     |
 *     | Log                                    日志文件
 *     |   | atom.log
 * 
 * */

class FileManager {
public:
    file_str_t FILE_ROOT_PATH = "H:/Atom";     /* 文件系统根目录 */

    file_str_t FILE_LOG_PATH = "H:/Atom/Log/atom.log";         /* 日志文件路径 */
    file_str_t FILE_CONFIG_WIFI_PATH = "H:/Atom/Config/Wi-Fi.cfg";

    /* 基础文件操作 */
    String f_read(file_str_t f_path);
    bool f_write(file_str_t f_path, file_str_t data, bool is_append);

    /* 日志文件输出 */
    void log(file_str_t log_data);

    /* 配置文件操作 */
    bool cfg_write(const JsonDocument& json, file_str_t cfg_path);
    JsonDocument cfg_read(file_str_t cfg_path);
};

extern FileManager File_Manager;

#endif // ATOM_UI_LV9_FILE_MANAGER_H
