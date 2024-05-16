/* Copyright 2024 Alessandro Caruso */

#include "ChemToolsConfig.h"

#include <cstdlib>
//#include <exception>
#include <mpi.h>
#include <thread>
#include <iostream>

//#include "logger.h"
#include "options.h"
#include "parser.h"
#include "gui.h"
#include "display.h"
#include "pointcloud.h"
#include "io.h"


void make_gui(int argc, char** argv) {
  GraphicalUserInterface gui(argc, argv);
  gui.run();
}

void make_display() {
  DisplayApplication app;
  app.run();

  //try {
  //  app.run();
  //} catch (const std::exception& e) {
  //  std::cerr << e.what() << std::endl;
  //  return EXIT_FAILURE;
  //}
}

int main(int argc, char** argv) {
  std::cout << "Version " << ChemTools_VERSION_MAJOR << '.' << ChemTools_VERSION_MINOR << std::endl;

  InputParser parser(argc, argv);

  std::cout << parser.method << '\n';
  std::cout << parser.filename << '\n';

  //std::jthread thread_gui(make_gui, argc, argv);
  //std::jthread thread_display(make_display);

  //PointCloud pc;
  //io::read_xyz_from_file(parser.filename, pc);

  MPI_Init(&argc, &argv);

  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int my_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  std::cout << "World size: " << world_size << ", Rank: " << my_rank << std::endl;

  MPI_Finalize();

  return EXIT_SUCCESS;
}

