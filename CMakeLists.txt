cmake_minimum_required(VERSION 3.10)

project(ChemTools VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s -march=native")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Wpedantic -Werror -fno-exceptions")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Wpedantic -Werror")

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

configure_file(ChemToolsConfig.h.in ChemToolsConfig.h)

set(SOURCES src/cli.cc
            src/gui.cc
            src/display.cc
            src/parser.cc
            src/io.cc
            src/pointcloud.cc)

qt_add_executable(ChemTools ${SOURCES})

list(APPEND PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

target_include_directories(ChemTools PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_INCLUDE_DIR}"
                           "${EXTRA_INCLUDES}")

target_link_libraries(ChemTools PRIVATE Qt6::Widgets)
target_link_libraries(ChemTools PRIVATE glfw)
target_link_libraries(ChemTools PRIVATE vulkan)

