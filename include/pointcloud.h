/* Copyright 2024 Alessandro Caruso */

#ifndef POINTCLOUD_H
#define POINTCLOUD_H

class PointCloudArray {
 public:
  PointCloudArray(const unsigned int&, const unsigned int&);
  ~PointCloudArray();

 private:
  unsigned int n_frames{0};
  unsigned int n_points{0};
  
  double* x{nullptr};
  double* y{nullptr};
  double* z{nullptr};

  PointCloudArray(const PointCloudArray&)            = delete;
  PointCloudArray& operator=(const PointCloudArray&) = delete;
  PointCloudArray(PointCloudArray&&)                 = delete;
  PointCloudArray& operator=(PointCloudArray&&)      = delete;
};

struct PointCloud {
 public:
  PointCloud(const unsigned int&);
  ~PointCloud();

 private:
  unsigned int n_points{0};

  double* x{nullptr};
  double* y{nullptr};
  double* z{nullptr};

  PointCloud(const PointCloud&)            = delete;
  PointCloud& operator=(const PointCloud&) = delete;
  PointCloud(PointCloud&&)                 = delete;
  PointCloud& operator=(PointCloud&&)      = delete;
};

#endif // POINTCLOUD_H
