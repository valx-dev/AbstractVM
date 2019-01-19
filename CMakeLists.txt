cmake_minimum_required(VERSION 3.1)
include(CMakeDependentOption)

project(AbstractVM LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 14)

#option(COVERAGE OFF "Generate coverage report")
CMAKE_DEPENDENT_OPTION(COVERAGE "Generate coverage report" ON
                "${CMAKE_BUILD_TYPE} MATCHES Debug;${COVERAGE} MATCHES ON" OFF)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(PROJECT_SRC)
# TODO: specify exact files
file(GLOB PROJECT_SRC sources/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

include_directories(includes)

# Setup testing
enable_testing()

# TODO: add tests
#add_subdirectory(tests)
