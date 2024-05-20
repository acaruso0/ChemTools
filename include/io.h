/* Copyright 2024 Alessandro Caruso */

#ifndef CHEMTOOLS_IO_H
#define CHEMTOOLS_IO_H

#include "pointcloud.h"

#include <string>


namespace io {
  void read_xyz_from_file(const std::string &filename, PointCloud &data);
}

#endif // CHEMTOOLS_IO_H
