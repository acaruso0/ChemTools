/* Copyright 2024 Alessandro Caruso */

#ifndef POINTCLOUD_H
#define POINTCLOUD_H

struct PointCloud;

namespace io {
  PointCloud* read_xyz_from_file(const char *filename, PointCloud *data);
}

struct PointCloud {
  friend PointCloud* io::read_xyz_from_file(const char *filename, PointCloud *data);
 public:
  PointCloud()                                   = default;
  ~PointCloud();

 private:
  unsigned int nframes{0};
  unsigned int npoints{0};

  double* x{nullptr};
  double* y{nullptr};
  double* z{nullptr};

  void allocate();

  PointCloud(const PointCloud& other)            = delete;
  PointCloud& operator=(const PointCloud& other) = delete;
  PointCloud(PointCloud&& other)                 = delete;
  PointCloud& operator=(PointCloud&& other)      = delete;
};

#endif // POINTCLOUD_H
