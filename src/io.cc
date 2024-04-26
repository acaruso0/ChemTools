/* Copyright 2024 Alessandro Caruso */

#include "io.h"

#include <fstream>
#include <sstream>

PointCloud* io::read_xyz_from_file(const char* filename, PointCloud* data) {
  std::ifstream file(filename);
  if (file.is_open()) {
    std::string line;
    std::istringstream iss;

    getline(file, line);
    ++data->nframes;
    iss.str(line);
    iss >> data->npoints;
    while (getline(file, line)) {
      ++data->nframes;
    }
    data->nframes /= data->npoints;
    file.clear();
    file.seekg(0);

    data->allocate();

    for (unsigned int i{0}; i < data->nframes; ++i) {
      getline(file, line);
      getline(file, line);

      for (unsigned int j{0}; j < data->npoints; ++j) {
        iss.clear();
        std::string _;

        getline(file, line);
        iss.str(line);
        iss >> _ >> data->x[j + data->npoints*data->nframes]
                 >> data->y[j + data->npoints*data->nframes]
                 >> data->z[j + data->npoints*data->nframes];
      }
    }

    file.close();

    return data;
  }
  return nullptr;
}
