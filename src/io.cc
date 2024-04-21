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
    iss.str(line);
    iss >> data->npoints;
    file.clear();
    file.seekg(0);

    while (getline(file, line)) {
      getline(file, line);

      ++data->nframes;
      for (unsigned int i{0}; i < data->npoints; ++i) {
        iss.clear();
        std::string _;

        getline(file, line);
        iss.str(line);
        iss >> _ >> data->x[i + data->npoints*data->nframes]
                 >> data->y[i + data->npoints*data->nframes]
                 >> data->z[i + data->npoints*data->nframes];
      }
    }

    file.close();

    return data;
  }
  return nullptr;
}
