#include "pointcloud.h"

#include <cassert>
#include <cstdlib>
#include <system_error>

#include "logger.h"

void PointCloud::Allocate(const unsigned int& _nframes, const unsigned int& _npoints) {
  assert(_nframes > 0 and _npoints > 0);
  if (!x and !y and !z) {
    nframes = _nframes;
    npoints = _npoints;
    x = new double[nframes*npoints];
    y = new double[nframes*npoints];
    z = new double[nframes*npoints];
  }
  if (!x or !y or !z) {
    ERROR(std::make_error_code(std::errc::not_enough_memory).message());
    std::abort();
  }
}

PointCloud::~PointCloud() {
  delete[] x;
  delete[] y;
  delete[] z;
}

