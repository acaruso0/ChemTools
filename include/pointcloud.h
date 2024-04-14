/* Copyright 2024 Alessandro Caruso */

#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include "parser.h"

struct PointCloud {
 public:
  int n_frames{0};
  int n_points{0};

  uint* labels{nullptr};
  double* coordinates{nullptr};

  void BuildPointCloud();

  PointCloud()                                   = default;
  ~PointCloud();

 private:
  void AllocateMemory();

  PointCloud(const PointCloud& other)            = delete;
  PointCloud& operator=(const PointCloud& other) = delete;
  PointCloud(PointCloud&& other)                 = delete;
  PointCloud& operator=(PointCloud&& other)      = delete;
};

#endif // POINTCLOUD_H
