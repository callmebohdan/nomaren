if (WIN32)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.7.2/msvc2019_64/lib/cmake")
endif()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia MultimediaWidgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(ASSET_FILES ../assets/icon/nomaren.rc)
set(HEADER_FILES mainwindow.hpp)
set(SOURCE_FILES main.cpp mainwindow.cpp)

set(UIS mainwindow.ui)

qt6_wrap_ui(UI_HEADERS ${UIS})

add_executable(nomaren ${SOURCE_FILES} ${HEADER_FILES} ${UI_HEADERS} ${ASSET_FILES})

target_link_libraries(nomaren PRIVATE Qt6::Core Qt6::Gui Qt6::Multimedia Qt6::Widgets Qt6::MultimediaWidgets)

if (WIN32)
    set_target_properties(nomaren PROPERTIES WIN64_EXECUTABLE ON LINK_FLAGS "-mwindows")
endif()
