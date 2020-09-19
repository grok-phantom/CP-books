cmake_minimum_required(VERSION 3.17)
project(CP_books
    LANGUAGES CXX
    VERSION 0.1
    )

set(CMAKE_CXX_STANDARD 17)

option(USE_OPENMP "flag to use OpenMP for multithreading")
if (USE_OPENMP)
  find_package(OPENMP 3.0 COMPONENTS CXX)
  if (OPENMP_CXX_FOUND)
    message(STATUS "Building with OpenMP Multithreading.")
  else ()
    message(STATUS "No OpenMP found, no multithreading.")
  endif ()
endif ()

add_subdirectory("2. Graph algorithms")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)