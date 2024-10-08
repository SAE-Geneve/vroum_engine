file(GLOB_RECURSE SRC_FILES src/*.cc)
file(GLOB_RECURSE HEADER_FILES include/*.h)

add_library(core ${SRC_FILES} ${HEADER_FILES}
        include/Vector2.h
        include/Vector3.h
        include/Vector4.h
        include/Matrice2x2.h
        include/Matrice3x3.h
        include/Matrice4x4.h)
target_include_directories(core PUBLIC include/)

add_executable(core_test test/test_vec2.cc
        test/test_vec3.cc
        test/test_vec4.cc
        test/test_matrice2x2.cc
        test/test_matrice3x3.cc
        test/test_matrice4x4.cc)

target_link_libraries(core_test PRIVATE core GTest::gtest GTest::gtest_main)

if(ENABLE_PROFILING)
  target_link_libraries(core PRIVATE Tracy::TracyClient)
  target_compile_definitions(core PUBLIC TRACY_ENABLE=1)
endif(ENABLE_PROFILING)

add_test(Core core_test)