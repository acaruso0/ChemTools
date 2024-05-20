/* Copyright 2024 Alessandro Caruso */

#include "io.h"

#include <string>
#include <fstream>
#include <sstream>

void io::read_xyz_from_file(const std::string &filename, PointCloud &data) {
  std::ifstream file(filename);
  if (file.is_open()) {
    std::string line;
    std::istringstream iss;

    getline(file, line);
    ++data.nframes;
    iss.str(line);
    iss >> data.npoints;
    while (getline(file, line)) {
      ++data.nframes;
    }
    data.nframes /= (data.npoints + 2);
    file.clear();
    file.seekg(0);

    data.allocate();

    for (unsigned int i{0}; i < data.nframes; ++i) {
      getline(file, line);
      getline(file, line);

      for (unsigned int j{0}; j < data.npoints; ++j) {
        iss.clear();
        std::string _;

        getline(file, line);
        iss.str(line);
        iss >> _ >> data.x[j + data.npoints*i]
                 >> data.y[j + data.npoints*i]
                 >> data.z[j + data.npoints*i];
      }
    }

    file.close();
  }
}
