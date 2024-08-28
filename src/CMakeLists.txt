find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Multimedia)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(ASSET_FILES ../assets/icon/nomaren.rc)
set(HEADER_FILES mainwindow.hpp)
set(SOURCE_FILES main.cpp mainwindow.cpp)
set(UI_FILES mainwindow.ui)

qt_add_executable(nomaren ${SOURCE_FILES} ${HEADER_FILES} ${UI_FILES} ${ASSET_FILES})

target_link_libraries(nomaren PRIVATE Qt6::Gui Qt6::Widgets Qt6::Multimedia)

set_target_properties(nomaren PROPERTIES WIN64_EXECUTABLE ON LINK_FLAGS "-mwindows")
