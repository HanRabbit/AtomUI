# !!! WARNING !!! AUTO-GENERATED FILE, PLEASE DO NOT MODIFY IT AND USE
# https://docs.platformio.org/page/projectconf/section_env_build.html#build-flags
#
# If you need to override existing CMake configuration or add extra,
# please create `CMakeListsUser.txt` in the root of project.
# The `CMakeListsUser.txt` will not be overwritten by PlatformIO.

cmake_minimum_required(VERSION 3.13)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

project("Atom_UI" C CXX)

include(CMakeListsPrivate.txt)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeListsUser.txt)
include(CMakeListsUser.txt)
endif()

add_custom_target(
    Production ALL
    COMMAND platformio -c clion run "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    Debug ALL
    COMMAND platformio -c clion debug "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(Z_DUMMY_TARGET ${SRC_LIST} src/ui/pages/_template/_template.cpp src/ui/pages/_template/_template.h src/ui/res/rp/rp.cpp src/ui/res/rp/rp.h src/ui/pages/home/home.cpp src/ui/pages/home/home.h src/ui/res/ui_img_battery_png.c src/indev/battery/battery.cpp src/indev/battery/battery.h src/common/esp_sleep/esp_sleep.cpp src/common/esp_sleep/esp_sleep.h src/ui/pages/_test/_test.cpp src/common/log/log.cpp src/ui/pages/error/error.h src/indev/self_check/self_check.cpp src/indev/self_check/self_check.h src/indev/sd/sd.cpp src/indev/sd/sd.h src/indev/io_map/io_map.h src/common/log/error_codes.h src/indev/wifi/wifi.cpp src/common/time/time.cpp src/common/time/time.h src/common/time/time.cpp src/common/time/time.h src/ui/pages/home/home_events.cpp)
