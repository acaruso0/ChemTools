/* Copyright 2024 Alessandro Caruso */

#ifndef PARSER_H
#define PARSER_H

class InputParser {
 public:
   InputParser(int, char**);
   ~InputParser()                             = default;
 private:
   InputParser(const InputParser&)            = delete;
   InputParser& operator=(const InputParser&) = delete;
   InputParser(InputParser&&)                 = delete;
   InputParser& operator=(InputParser&&)      = delete;
};

#endif // PARSER_H
