#include "pointcloud.h"

#include "logger.h"

PointCloud::PointCloud(const int& size) {
  x = new double[size];
  y = new double[size];
  z = new double[size];
}

PointCloud::~PointCloud() {
  delete[] x;
  delete[] y;
  delete[] z;
}

