/* Copyright 2024 Alessandro Caruso */

#include "parser.h"

#include <cstring>
#include <iostream>
#include <cstdint>
#include <sstream>


InputParser::InputParser(int argc, char** argv) {
  if (argc > 1) [[likely]] {
    std::istringstream iss;

    //for (std::uint8_t i{0}; i < argc; ++i) {
    std::uint8_t i{0};
    while (i < argc) {
      if (!strncmp(argv[i], "--m", 3)) {
        iss.clear();
        iss.str(argv[++i]);
        iss >> this->method;
      } else {
        iss.clear();
        iss.str(argv[i++]);
        iss >> this->filename;
      }
    }
  } else {
    print_usage();
  }
}

void InputParser::print_usage() {
  std::cout << "Usage: ChemTools [options] file\n"
            << "Options:\n"
            << "-m/--method" << std::endl;
}
