file(GLOB_RECURSE SRC_FILES src/*.cc)
file(GLOB_RECURSE HEADER_FILES include/*.h)


add_library(api ${SRC_FILES} ${HEADER_FILES}
        include/Graphics.h
        src/square.cc
        include/Shape.h
        src/square.cc
        src/solarsystem.cc
        include/solarsystem.h
        ../core/include/Constants.h
        src/Circle.cc
        include/Circle.h
        src/FPSCounter.cc
        include/FPSCounter.h
        src/imgui.cc
        include/imgui.h
        src/Body.cc
        include/Body.h
        src/Random.cc
        include/Random.h
        src/Collider.cc
        include/Collider.h
        src/collider_systeme.cc
        include/collider_systeme.h
        src/collider_solary_syteme.cc
        include/collider_solary_syteme.h
        src/collider_solary_syteme.cc
        src/quadtree.cc
        include/quadtree.h
        src/collider_quadtree_systeme.cc
        include/collider_quadtree_systeme.h
        src/triger_systeme.cc
        include/triger_systeme.h
        src/collider_static_systeme.cc
        include/collider_static_systeme.h)
target_include_directories(api PUBLIC include/)

if(ENABLE_PROFILING)
  target_link_libraries(api PRIVATE Tracy::TracyClient)
  target_compile_definitions(api PUBLIC TRACY_ENABLE=1)
endif(ENABLE_PROFILING)

target_link_libraries(api PRIVATE SDL2::SDL2)
target_link_libraries(api PRIVATE SDL2::SDL2main)