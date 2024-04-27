/* Copyright 2024 Alessandro Caruso */

#include "gui.h"

#include <QApplication>
#include <QPushButton>

GraphicalUserInterface::GraphicalUserInterface(int argc, char** argv): app(argc, argv) {}

int GraphicalUserInterface::run() {
  QPushButton button("DON'T PRESS");
  button.show();

  return app.exec();
}

