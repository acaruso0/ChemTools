/* Copyright 2024 Alessandro Caruso */

#ifndef CHEMTOOLS_GUI_H
#define CHEMTOOLS_GUI_H

#include <QApplication>


class GraphicalUserInterface {
 public:
  int Run();
  GraphicalUserInterface(int argc, char** argv);
  ~GraphicalUserInterface()                                              = default;

 private:
  QApplication app;

  GraphicalUserInterface(const GraphicalUserInterface& other)            = delete;
  GraphicalUserInterface* operator=(const GraphicalUserInterface& other) = delete;
  GraphicalUserInterface(GraphicalUserInterface&& other)                 = delete;
  GraphicalUserInterface* operator=(GraphicalUserInterface&& other)      = delete;
};

#endif // CHEMTOOLS_GUI_H
