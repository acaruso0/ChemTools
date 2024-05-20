/* Copyright 2024 Alessandro Caruso */

#include "io.h"
#include "pointcloud.h"

#include <cstdint>
#include <string>
#include <fstream>
#include <sstream>

#include <print>

void io::load_xyz(const std::string &filename, PointCloud &data) {
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

    for (std::uint32_t i{0}; i < data.nframes; ++i) {
      getline(file, line);
      getline(file, line);

      for (std::uint16_t j{0}; j < data.npoints; ++j) {
        iss.clear();
        std::string _;

        getline(file, line);
        iss.str(line);
        iss >> _ >> data.x[j + i*data.npoints]
                 >> data.y[j + i*data.npoints]
                 >> data.z[j + i*data.npoints];
      }
    }

    file.close();
  }
}

void io::dump_xyz(const std::string &filename, PointCloud &data) {
  std::ofstream file(filename);
  if (file.is_open()) {
    for (std::uint32_t i{0}; i < data.nframes; ++i) {
      std::print(file, "{}\n\n", data.npoints);
      for (std::uint16_t j{0}; j < data.npoints; ++j) {
        std::print(file, "{0:12.8f} {1:12.8f} {2:12.8f}\n", data.x[j + i*data.npoints],
                                                            data.y[j + i*data.npoints],
                                                            data.z[j + i*data.npoints]);
      }
    }
  }

  file.close();
}
