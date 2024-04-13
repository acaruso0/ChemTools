#include "ChemToolsConfig.h"

#include <QApplication>
#include <QPushButton>
#include "logger.h"


int main(int argc, char **argv) {
  LOG(LogLevel::Info);
  INFO("Version ", ChemTools_VERSION_MAJOR, '.', ChemTools_VERSION_MINOR);
  WARNING("This is a ", "TEST", '\n', "WARNING");
  ERROR("TEST ", "ERROR! ", 42);
  
  QApplication app(argc, argv);
  QPushButton button("DON'T PRESS");
  button.show();

  return app.exec();
}

