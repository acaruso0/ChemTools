/* Copyright 2024 Alessandro Caruso */

#ifndef POINTCLOUD_H
#define POINTCLOUD_H

struct PointCloud {
 public:
  double* x{nullptr};
  double* y{nullptr};
  double* z{nullptr};

  PointCloud(const int&);
  ~PointCloud();

 private:
  PointCloud(const PointCloud&)            = delete;
  PointCloud& operator=(const PointCloud&) = delete;
  PointCloud(PointCloud&&)                 = delete;
  PointCloud& operator=(PointCloud&&)      = delete;
};

#endif // POINTCLOUD_H
