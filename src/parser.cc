/* Copyright 2024 Alessandro Caruso */

#include "parser.h"

#include <iostream>


InputParser::InputParser(int argc, char** argv) {
  if (argc > 1) [[likely]] {
    for (int i{0}; i < argc; ++i) {
      std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
  } else {
    print_usage();
  }
}

void InputParser::print_usage() {
  std::cout << "Usage: ChemTools [options] file...\n"
            << "Options:\n"
            << "-m/--method" << std::endl;
}
