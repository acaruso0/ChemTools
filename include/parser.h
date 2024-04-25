/* Copyright 2024 Alessandro Caruso */

#ifndef PARSER_H
#define PARSER_H

enum class Format : signed char { UNDEF, XYZ, PDB };
enum class Method : signed char { UNDEF, DFT, HF };

class InputParser {
 public:
   InputParser(int argc, char** argv);
   ~InputParser()                                   = default;

 private:
   Format data_format{0};
   Method method{0};

   void PrintUsage();

   InputParser(const InputParser& other)            = delete;
   InputParser& operator=(const InputParser& other) = delete;
   InputParser(InputParser&& other)                 = delete;
   InputParser& operator=(InputParser&& other)      = delete;
};

#endif // PARSER_H
