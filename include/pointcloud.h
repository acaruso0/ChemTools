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
  PointCloud(const PointCloud& other)            = delete;
  PointCloud& operator=(const PointCloud& other) = delete;
  PointCloud(PointCloud&& other)                 = delete;
  PointCloud& operator=(PointCloud&& other)      = delete;
};

#endif // POINTCLOUD_H
