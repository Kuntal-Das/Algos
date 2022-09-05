cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ALGOS VERSION 1.0)

file(GLOB_RECURSE CDS_FILES lib/DS/*/*.c)
file(GLOB_RECURSE HDS_FILES lib/DS/*/*.h)
add_library(ArrayLib STATIC ${HDS_FILES} ${CDS_FILES})

file(GLOB_RECURSE LCMGCD_FILES lib/LcmGcd/*.c)
add_library(LcmGcdLib STATIC lib/LcmGcd/LcmGcd.h ${LCMGCD_FILES})

file(GLOB_RECURSE OTHERS_FILES lib/Others/*.c)
add_library(OthersLib STATIC lib/Others/Others.h ${OTHERS_FILES})

file(GLOB_RECURSE HELPERS_FILES lib/Helpers/*.c)
add_library(HelpersLib STATIC lib/Helpers/Helpers.h ${HELPERS_FILES})
target_link_libraries(HelpersLib PRIVATE m)

file(GLOB_RECURSE MULT_FILES lib/Multiplications/*.c)
add_library(MultiplicationsLib STATIC lib/Multiplications/Multilplication.h ${MULT_FILES})
target_link_libraries(MultiplicationsLib PUBLIC HelpersLib PRIVATE m)

file(GLOB_RECURSE MATRIX_FILES lib/MatrixOp/*.c)
add_library(MatrixLib STATIC lib/MatrixOp/Matrix.h ${MATRIX_FILES})
target_link_libraries(MatrixLib PUBLIC HelpersLib)

file(GLOB_RECURSE SORT_FILES lib/Sorting/*.c)
add_library(SortingLib STATIC lib/Sorting/Sorting.h ${SORT_FILES})
target_link_libraries(SortingLib PUBLIC HelpersLib ArrayLib)

add_executable(ALGOS src/main.c)
target_link_libraries(ALGOS 
PUBLIC ArrayLib HelpersLib MultiplicationsLib LcmGcdLib MatrixLib SortingLib OthersLib)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
