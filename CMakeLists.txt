cmake_minimum_required(VERSION 3.10)
project(gxde-timer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

set(TS_FILE ${CMAKE_SOURCE_DIR}/translations/gxde-timer_zh_CN.ts)
set(QM_FILE ${CMAKE_SOURCE_DIR}/translations/gxde-timer_zh_CN.qm)

add_custom_target(translations ALL
    COMMAND ${CMAKE_SOURCE_DIR}/translate_generation.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS ${TS_FILE}                      # 仅当 .ts 变化时才重新生成
    BYPRODUCTS ${QM_FILE}                   # 声明此文件由命令生成
    COMMENT "Generating .qm translation file using translate_generation.sh"
)

install(FILES ${QM_FILE}
    DESTINATION share/gxde-timer/translations)

# ====== 附加文件安装 ======
install(FILES assets/gxde-timer.desktop
    DESTINATION share/GXDE/gxde-system-assistant/tool-extensions
)
install(FILES assets/icon/gxde-timer.svg
    DESTINATION share/icons
)