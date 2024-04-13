cmake_minimum_required(VERSION 3.10)

project(ChemTools VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -s")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -pedantic -Wextra -Werror -g")

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

configure_file(ChemToolsConfig.h.in ChemToolsConfig.h)

#add_subdirectory("${PROJECT_SOURCE_DIR}/src")

#add_executable(ChemTools src/main.cpp)
qt_add_executable(ChemTools src/main.cpp)
target_include_directories(ChemTools PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           include)
                         #"${PROJECT_SOURCE_DIR}/include")
#target_link_libraries(ChemTools PUBLIC libs/logger)
target_link_libraries(ChemTools PRIVATE Qt6::Widgets)

