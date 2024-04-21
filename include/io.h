/* Copyright 2024 Alessandro Caruso */

#ifndef IO_H
#define IO_H

#include "pointcloud.h"

namespace io {
  PointCloud* read_xyz_from_file(const char* filename, PointCloud* data);
}

#endif // IO_H
