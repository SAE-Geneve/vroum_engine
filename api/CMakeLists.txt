file(GLOB_RECURSE SRC_FILES src/*.cc)
file(GLOB_RECURSE HEADER_FILES include/*.h)



add_library(api ${SRC_FILES} ${HEADER_FILES}
        include/Graphics.h
        include/solar_system.h
        include/circle.h
)
target_include_directories(api PUBLIC include/)

if(ENABLE_PROFILING)
  target_link_libraries(api PRIVATE Tracy::TracyClient)
  target_compile_definitions(api PUBLIC TRACY_ENABLE=1)
endif(ENABLE_PROFILING)

target_link_libraries(api PRIVATE SDL2::SDL2)
target_link_libraries(api PRIVATE SDL2::SDL2main)