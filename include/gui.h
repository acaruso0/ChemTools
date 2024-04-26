/* Copyright 2024 Alessandro Caruso */

#ifndef GUI_H
#define GUI_H

#include <QApplication>
#include <QPushButton>


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

#endif // GUI_H
