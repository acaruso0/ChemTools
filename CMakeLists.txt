cmake_minimum_required(VERSION 3.10)

project(ChemTools VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -Werror")

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

configure_file(ChemToolsConfig.h.in ChemToolsConfig.h)

set(SOURCES src/main.cc
            src/display.cc)
qt_add_executable(ChemTools ${SOURCES})

list(APPEND PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

target_include_directories(ChemTools PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_INCLUDE_DIR}"
                           "${EXTRA_INCLUDES}")

target_link_libraries(ChemTools PRIVATE Qt6::Widgets)
target_link_libraries(ChemTools PRIVATE glfw)

#add_subdirectory("${PROJECT_SOURCE_DIR}/src")
#target_link_libraries(ChemTools PUBLIC libs/logger)
