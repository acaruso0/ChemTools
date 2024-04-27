/* Copyright 2024 Alessandro Caruso */

#ifndef CHEMTOOLS_IO_H
#define CHEMTOOLS_IO_H

#include "pointcloud.h"

namespace io {
  PointCloud* read_xyz_from_file(const char* filename, PointCloud* data);
}

#endif // CHEMTOOLS_IO_H
