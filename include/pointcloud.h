/* Copyright 2024 Alessandro Caruso */

#ifndef CHEMTOOLS_POINTCLOUD_H
#define CHEMTOOLS_POINTCLOUD_H

#include <cstdint>
#include <stdfloat>


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
  std::uint32_t nframes{0};
  std::uint16_t npoints{0};

  std::float32_t* x{nullptr};
  std::float32_t* y{nullptr};
  std::float32_t* z{nullptr};

  void allocate();

  PointCloud(const PointCloud& other)            = delete;
  PointCloud& operator=(const PointCloud& other) = delete;
  PointCloud(PointCloud&& other)                 = delete;
  PointCloud& operator=(PointCloud&& other)      = delete;
};

#endif // CHEMTOOLS_POINTCLOUD_H
