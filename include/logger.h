/* Copyright 2024 Alessandro Caruso */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>


#define DEBUG 1

#define RESET       "\033[0m"
#define BLACK       "\033[30m"      /* Black */
#define RED         "\033[31m"      /* Red */
#define GREEN       "\033[32m"      /* Green */
#define YELLOW      "\033[33m"      /* Yellow */
#define BLUE        "\033[34m"      /* Blue */
#define MAGENTA     "\033[35m"      /* Magenta */
#define CYAN        "\033[36m"      /* Cyan */
#define WHITE       "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#if DEBUG == 1
  #define LOG(level)   Log& log { Log::GetInstance() }; \
                           log.SetLevel(level);
  #define INFO(...)    log.Info(__VA_ARGS__);
  #define WARNING(...) log.Warning(__VA_ARGS__);
  #define ERROR(...)   log.Error(__VA_ARGS__);
#elif DEBUG == 0
  #define LOG(...)
  #define INFO(...)
  #define WARNING(...)
  #define ERROR(...)
#endif

enum LogLevel { Error = 0, Warning, Info };

class Log {
 public:
  static Log& GetInstance() {
    static Log log;

    return log;
  }

  void SetLevel(LogLevel level) {
    level = level;
  }

  template<char sep='\0', char end='\n', class T, class... U>
  void Info(const T& first, const U&... rest) {
    if (level >= LogLevel::Info) {
      std::cout << '[' << BOLDBLUE << "INFO" << RESET << "]: " << first;
      ((std::cout << sep << rest), ...);
      std::cout << end;
    }
  }

  template<char sep='\0', char end='\n', class T, class... U>
  void Warning(const T& first, const U&... rest) {
    if (level >= LogLevel::Warning) {
      std::cout << '[' << BOLDYELLOW << "WARNING" << RESET << "]: " << first;
      ((std::cout << sep << rest), ...);
      std::cout << end;
    }
  }

  template<char sep='\0', char end='\n', class T, class... U>
  void Error(const T& first, const U&... rest) {
    if (level >= LogLevel::Error) {
      std::cout << '[' << BOLDRED << "ERROR" << RESET << "]: " << first;
      ((std::cout << sep << rest), ...);
      std::cout << end;
    }
  }

  ~Log()                           = default;

 private:
  LogLevel level { LogLevel::Info };

  Log()                            = default;
  Log(const Log& other)            = delete;
  Log& operator=(const Log& other) = delete;
  Log(Log&& other)                 = delete;
  Log& operator=(Log&& other)      = delete;

};

#endif // LOGGER_H
