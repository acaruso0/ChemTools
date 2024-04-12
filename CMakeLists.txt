cmake_minimum_required(VERSION 3.10)

project(ChemTools VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(ChemToolsConfig.h.in ChemToolsConfig.h)

#add_subdirectory("${PROJECT_SOURCE_DIR}/src")

add_executable(ChemTools src/main.cpp)
target_include_directories(ChemTools PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           include)
                         #"${PROJECT_SOURCE_DIR}/include")
#target_link_libraries(ChemTools PUBLIC libs/logger)

