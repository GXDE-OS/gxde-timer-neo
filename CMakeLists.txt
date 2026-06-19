cmake_minimum_required(VERSION 3.10)
project(gxde-timer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 翻译工具
find_package(Qt6LinguistTools)

add_subdirectory(src)

# ====== 翻译 ======
set(TS_FILES translations/gxde-timer_zh_CN.ts)

set(UPDATE_SOURCES
    src/main.cpp
    src/widget.cpp src/widget.h src/widget.ui
    src/countdown.cpp src/countdown.h
    src/toptime.cpp src/toptime.h
)

qt6_create_translation(QM_FILES ${UPDATE_SOURCES} ${TS_FILES}
    OPTIONS -no-obsolete
)

add_custom_target(translations ALL DEPENDS ${QM_FILES})

install(FILES ${QM_FILES}
    DESTINATION share/gxde-timer/translations
)

# ====== 附加文件安装 ======
install(FILES assets/gxde-timer.desktop
    DESTINATION share/GXDE/gxde-system-assistant/tool-extensions
)
install(FILES assets/icon/gxde-timer.svg
    DESTINATION share/icons
)