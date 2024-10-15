cmake_minimum_required(VERSION 3.18)
project(GameEngine)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(SDL2 CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

enable_testing()
option(ENABLE_PROFILING "Enable Tracy Profiling" OFF)


if(ENABLE_PROFILING)
     find_package(Tracy CONFIG REQUIRED)
endif(ENABLE_PROFILING)

add_subdirectory(core/)
add_subdirectory(api/)
target_link_libraries(api PRIVATE core)
add_executable(main main.cc)
target_link_libraries(main PRIVATE core api)
target_link_libraries(main PRIVATE SDL2::SDL2)
target_link_libraries(main PRIVATE SDL2::SDL2main)
target_link_libraries(main PRIVATE imgui::imgui)

if(ENABLE_PROFILING)
    target_link_libraries(main PUBLIC Tracy::TracyClient)
    target_compile_definitions(main PUBLIC TRACE_ENABLE=1)
endif(ENABLE_PROFILING)

