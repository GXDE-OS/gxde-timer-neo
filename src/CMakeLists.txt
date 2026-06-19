# 查找 Qt6 组件
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia MultimediaWidgets)
find_package(Dtk6Core REQUIRED)

# 启用自动 moc、uic、rcc 处理
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 查找 dtkwidget (通过 pkg-config)
find_package(PkgConfig REQUIRED)
pkg_check_modules(DTKWidget REQUIRED dtkwidget)

# 源文件
set(SOURCES
    main.cpp
    widget.cpp
    countdown.cpp
    toptime.cpp
)

# 头文件（用于 MOC）
set(HEADERS
    widget.h
    countdown.h
    toptime.h
)

# UI 表单
set(FORMS
    widget.ui
)

# 资源文件 (注意路径相对于本 CMakeLists.txt)
set(RESOURCES
    ../assets/assets.qrc
)

# 可执行文件
add_executable(gxde-timer
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
    ${RESOURCES}
)

# 链接库
target_link_libraries(gxde-timer
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::MultimediaWidgets
    dtk2widget
    Dtk6::Core
)

# 头文件包含路径
target_include_directories(gxde-timer PRIVATE
    /usr/include/dtk2/DWidget
)

# 安装可执行文件到 /usr/bin
install(TARGETS gxde-timer
    RUNTIME DESTINATION bin
)