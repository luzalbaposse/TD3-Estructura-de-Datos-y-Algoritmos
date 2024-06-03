cmake_minimum_required(VERSION 3.0)

project(clase1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

include (CTest)

add_executable(main main.cpp)
add_executable(test_parte1 test_parte1.cpp)
add_executable(test_parte2 test_parte2.cpp)
add_executable(test_parte3 test_parte3.cpp)
add_executable(test_parte4 test_parte4.cpp)
add_executable(test_parte5 test_parte5.cpp)

target_link_libraries(
  test_parte1
  gtest_main
)

target_link_libraries(
  test_parte2
  gtest_main
)

target_link_libraries(
  test_parte3
  gtest_main
)

target_link_libraries(
  test_parte4
  gtest_main
)

target_link_libraries(
  test_parte5
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_parte1)
gtest_discover_tests(test_parte2)
gtest_discover_tests(test_parte3)
gtest_discover_tests(test_parte4)
gtest_discover_tests(test_parte5)
