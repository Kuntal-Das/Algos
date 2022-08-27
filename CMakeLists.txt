cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ALGOS VERSION 1.0)

add_library(HelpersLib STATIC lib/Helpers/Helpers.c)
add_library(ArrayLib STATIC lib/Array/Array.c)

add_library(MultilplicationsLib STATIC lib/Multilplications/Larusa.c lib/Multilplications/Karatsuba.c)
target_link_libraries(MultilplicationsLib PUBLIC HelpersLib)

add_library(LcmGcdLib STATIC lib/LcmGcd/Gcd.c)

add_library(MatrixLib STATIC lib/MatrixOp/Matrix.c)
target_link_libraries(MatrixLib PUBLIC HelpersLib)

add_library(SortingLib STATIC lib/Sorting/BubbleSort.c)

add_executable(ALGOS src/main.c)
target_link_libraries(ALGOS 
PUBLIC ArrayLib HelpersLib MultilplicationsLib LcmGcdLib MatrixLib SortingLib 
PRIVATE m)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
