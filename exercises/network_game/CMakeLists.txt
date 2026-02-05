cmake_minimum_required(VERSION 3.20)

project(network_game)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_BUILD_TYPE Debug)

include(FetchContent)

FetchContent_Declare(
  network
  GIT_REPOSITORY https://git.hailey.house/richard.hailey/network.git
  GIT_TAG main
)

FetchContent_MakeAvailable(network)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    src/main.c
    src/game.c
    src/level1.c
    src/level2.c
    src/level3.c
    src/level4.c
    src/level5.c
    src/level6.c
    src/level7.c
    src/level8.c
    src/level9.c
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    network
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    include
)
