cmake_minimum_required(VERSION 3.1)
include(CMakeDependentOption)

project(AbstractVM LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 14)

option(WITH_TESTS ON "Build tests")
CMAKE_DEPENDENT_OPTION(COVERAGE "Generate coverage report" ON
                "${CMAKE_BUILD_TYPE} MATCHES Debug;${COVERAGE} MATCHES ON" OFF)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(PROJECT_SRC)
# TODO: specify exact files
file(GLOB PROJECT_SRC sources/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

include_directories(includes)

if (WITH_TESTS MATCHES ON)
    # Setup testing
    enable_testing()

    add_subdirectory(tests)
endif ()
