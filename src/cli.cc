/* Copyright 2024 Alessandro Caruso */

#include "ChemToolsConfig.h"

#include <mpi.h>

#include "logger.h"
#include "pointcloud.h"
#include "parser.h"

int main(int argc, char** argv) {
  LOG(LogLevel::Info);
  INFO("Version ", ChemTools_VERSION_MAJOR, '.', ChemTools_VERSION_MINOR);
  //WARNING("This is a ", "TEST", '\n', "WARNING");
  //ERROR("TEST ", "ERROR! ", 42);

  InputParser settings(argc, argv);

  PointCloud frame{5};

  MPI_Init(&argc, &argv);

  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int my_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  INFO("World size: ", world_size, ", Rank: ", my_rank);

  MPI_Finalize();

  return 0;
}

