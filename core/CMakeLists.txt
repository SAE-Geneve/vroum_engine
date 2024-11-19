cmake_minimum_required(VERSION 3.18)
project(GameEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




# Option de test
enable_testing()
option(ENABLE_PROFILING "Enable Tracy Profiling" OFF)

# Trouver Google Test
find_package(GTest CONFIG REQUIRED)

# Récupérer tous les fichiers source et d'en-tête
file(GLOB_RECURSE SRC_FILES src/*.cc)
file(GLOB_RECURSE HEADER_FILES include/*.h)

# Créer la bibliothèque core
add_library(core ${SRC_FILES} ${HEADER_FILES}
        include/vec2.h
        include/vec3.h
        include/vec4.h
        include/matrice2.h
        include/matrice3.h
        include/matrice4.h
        include/Constants.h
        include/Trigo.h
        include/Quaternion.h
        include/Fourvec2.h
        include/Fourvec3.h
        include/Fourvec4.h
        src/Fourvec2.cc
        include/Commun.h
)

target_include_directories(core PUBLIC include/)

# Créer l'exécutable de test
add_executable(core_test test/testvec2.cc
        test/testvec3.cc
        test/testvec4.cc
        "test/testmatrice2 .cc"
        test/testmatrice3.cc
        test/testmatrice4.cc
        include/Constants.h
        test/TestQuaternion.cc
        test/TestFourvec2.cc
        test/TestFourvec3.cc
        test/TestFourvec4.cc)


# Lier la bibliothèque core et Google Test à core_test
target_link_libraries(core_test PRIVATE core GTest::gtest GTest::gtest_main)

# Lier Tracy si l'option est activée
if(ENABLE_PROFILING)
  target_link_libraries(core PRIVATE Tracy::TracyClient)
  target_compile_definitions(core PUBLIC TRACY_ENABLE=1)
endif(ENABLE_PROFILING)

# Ajouter un test CMake
add_test(Core core_test)
