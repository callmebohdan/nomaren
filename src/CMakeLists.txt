find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia MultimediaWidgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(ASSET_FILES ../assets/icon/nomaren.rc)
set(HEADER_FILES nomaren.hpp)
set(SOURCE_FILES main.cpp nomaren.cpp)
set(UI_FILES nomaren.ui)

qt6_wrap_ui(UI_HEADERS ${UI_FILES})

if (WIN32)
    qt_add_executable(nomaren WIN32 ${SOURCE_FILES} ${HEADER_FILES} ${UI_HEADERS} ${ASSET_FILES})
else()
    qt_add_executable(nomaren ${SOURCE_FILES} ${HEADER_FILES} ${UI_HEADERS} ${ASSET_FILES})
endif()

target_link_libraries(nomaren PRIVATE Qt6::Core Qt6::Gui Qt6::Multimedia Qt6::Widgets Qt6::MultimediaWidgets)
