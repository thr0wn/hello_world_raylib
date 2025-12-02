cmake_minimum_required(VERSION 3.22.0)
project(hello_world)

include(FetchContent)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependency: raylib
set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS
)
FetchContent_MakeAvailable(raylib)

# Dependency: raygui (no root CMakeList.txt)
set(RAYGUI_VERSION 4.0)
FetchContent_Declare(
    raygui
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raygui/archive/refs/tags/${RAYGUI_VERSION}.tar.gz
    FIND_PACKAGE_ARGS
)
FetchContent_MakeAvailable(raygui)
add_subdirectory("${raygui_SOURCE_DIR}/projects/CMake")
# raygui has a lot of warnings of -Wenum-compare
add_compile_options(-Wno-enum-compare)

# default executable
set(EXECUTABLE_NAME exe)
add_executable(${EXECUTABLE_NAME}
  "src/hello_world.cpp"
)
target_link_libraries(${EXECUTABLE_NAME} raylib raygui)
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set_property(TARGET ${EXECUTABLE_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
