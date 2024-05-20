/* Copyright 2024 Alessandro Caruso */

#ifndef CHEMTOOLS_IO_H
#define CHEMTOOLS_IO_H

#include "pointcloud.h"

#include <string>


namespace io {
  void load_xyz(const std::string &filename, PointCloud &data);
  void dump_xyz(const std::string &filename, PointCloud &data);
}

#endif // CHEMTOOLS_IO_H
