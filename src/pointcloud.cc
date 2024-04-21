#include "pointcloud.h"

void PointCloud::Allocate(const unsigned int& _nframes, const unsigned int& _npoints) {
  if (!x and !y and !z) {
    nframes = _nframes;
    npoints = _npoints;
    x = new double[nframes*npoints];
    y = new double[nframes*npoints];
    z = new double[nframes*npoints];
  }
}

PointCloud::~PointCloud() {
  delete[] x;
  delete[] y;
  delete[] z;
}

