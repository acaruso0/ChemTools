/* Copyright 2024 Alessandro Caruso */

#include "gui.h"

GraphicalUserInterface::GraphicalUserInterface(int argc, char** argv): app(argc, argv) {}

int GraphicalUserInterface::Run() {
  QPushButton button("DON'T PRESS");
  button.show();

  return app.exec();
}

