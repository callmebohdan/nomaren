set(CLI_HEADER_FILES nomaren.hpp)
set(CLI_SOURCE_FILES main.cpp nomaren.cpp)

add_executable(nomaren ${CLI_SOURCE_FILES} ${CLI_HEADER_FILES})

target_link_libraries(nomaren PRIVATE Qt6::Gui)