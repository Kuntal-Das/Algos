cmake_minimum_required(VERSION 3.0.0)
project(algos VERSION 0.1.0)

# include(CTest)
# enable_testing()

add_executable(algos 
Helpers/Helpers.c
LcmGcd/Gcd.c
MatrixOp/Matrix.c 
Multilplications/Karatsuba.c 
Multilplications/Larusa.c 
Sorting/BubbleSort.c
Array/Array.c
main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
