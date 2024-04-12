#include "ChemToolsConfig.h"

#include "logger.h"
#include <iostream>


int main() {
  //std::cout << "Version " << ChemTools_VERSION_MAJOR << '.' << ChemTools_VERSION_MINOR << std::endl;

  //LOG(LogLevel::Warning);
  LOG(LogLevel::Info);
  INFO("Hello!");
  INFO("Version ", ChemTools_VERSION_MAJOR, '.', ChemTools_VERSION_MINOR);
  WARNING("Hello! ", '\n', "test2");
  ERROR("Hello! ", "test ", 42);

  return 0;
}

