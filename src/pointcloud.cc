#include "pointcloud.h"

#include "logger.h"

PointCloudArray::PointCloudArray(const unsigned int& n_frames, const unsigned int& n_points):
  n_frames(n_frames), n_points(n_points) {
  x = new double[n_frames*n_points];
  y = new double[n_frames*n_points];
  z = new double[n_frames*n_points];
}

PointCloudArray::~PointCloudArray() {
  delete[] x;
  delete[] y;
  delete[] z;
}

PointCloud::PointCloud(const unsigned int& n_points): n_points(n_points) {
  x = new double[n_points];
  y = new double[n_points];
  z = new double[n_points];
}

PointCloud::~PointCloud() {
  delete[] x;
  delete[] y;
  delete[] z;
}

