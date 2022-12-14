cmake_minimum_required(VERSION 3.14)
project(lab1)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(TreeTest
        treeTest.cpp tree.cpp
        )

add_executable(TreeMain
        main.cpp tree.cpp
        )

target_link_libraries(
        TreeTest
        GTest::gtest_main
)

include(GoogleTest)
