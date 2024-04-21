/* Copyright 2024 Alessandro Caruso */

#ifndef PARSER_H
#define PARSER_H

class InputParser {
 public:
   InputParser(int argc, char** argv);
   ~InputParser()                                   = default;
 private:
   InputParser(const InputParser& other)            = delete;
   InputParser& operator=(const InputParser& other) = delete;
   InputParser(InputParser&& other)                 = delete;
   InputParser& operator=(InputParser&& other)      = delete;
};

#endif // PARSER_H
