set(CLI_HEADER_FILES nomaren.hpp)
set(CLI_SOURCE_FILES mainCLI.cpp nomaren.cpp)

add_executable(nomarenCLI ${CLI_SOURCE_FILES} ${CLI_HEADER_FILES})
