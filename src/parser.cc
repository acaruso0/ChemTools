#include "parser.h"

#include "logger.h"

InputParser::InputParser(int argc, char** argv) {
  WARNING("TESTING PARSER");
  for (int i{0}; i < argc; ++i) {
    WARNING(argv[i]);
  }
}

