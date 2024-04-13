#!/bin/bash

BUILD_TYPE='Release'
if [[ $# > 0 && $1 == '--debug' ]]
then
  BUILD_TYPE='Debug'
fi

rm -rf build
mkdir build
cd build

echo Compiling in ${BUILD_TYPE,} mode...
cmake -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
      -DCMAKE_CXX_COMPILER=g++           \
      ..
cmake --build .
cd ..

rm -rf bin
mkdir bin
cp build/ChemTools bin

