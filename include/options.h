/* Copyright 2024 Alessandro Caruso */

#ifndef CHEMTOOLS_OPTIONS_H
#define CHEMTOOLS_OPTIONS_H


enum class Format : signed char { UNDEF, XYZ, PDB };
enum class Method : signed char { UNDEF, DFT, HF };

struct Options {
  friend class InputParser;
 public:
  Options()                                = default;
  ~Options()                               = default;

 private:
  Format data_format{0};
  Method method{0};

  Options(const Options& other)            = delete;
  Options& operator=(const Options& other) = delete;
  Options(Options&& other)                 = delete;
  Options& operator=(Options&& other)      = delete;
};

#endif // CHEMTOOLS_OPTIONS_H
