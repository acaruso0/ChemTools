/* Copyright 2024 Alessandro Caruso */

#ifndef CHEMTOOLS_PARSER_H
#define CHEMTOOLS_PARSER_H

#include <string>


class InputParser {
 public:
  std::string filename;
  std::string method;

  //void listen();

  InputParser(int argc, char** argv);
  ~InputParser()                                   = default;

 private:
  void print_usage();

  InputParser(const InputParser& other)            = delete;
  InputParser& operator=(const InputParser& other) = delete;
  InputParser(InputParser&& other)                 = delete;
  InputParser& operator=(InputParser&& other)      = delete;
};

#endif // CHEMTOOLS_PARSER_H
