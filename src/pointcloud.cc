#include "pointcloud.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <system_error>
#include <stdfloat>


void PointCloud::allocate() {
  assert(nframes > 0 and npoints > 0);
  if (!x and !y and !z) {
    x = new std::float32_t[nframes*npoints];
    y = new std::float32_t[nframes*npoints];
    z = new std::float32_t[nframes*npoints];
  }
  if (!x or !y or !z) {
    std::cerr << std::make_error_code(std::errc::not_enough_memory).message()
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

PointCloud::~PointCloud() {
  delete[] x;
  delete[] y;
  delete[] z;
}

