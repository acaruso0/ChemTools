/* Copyright 2024 Alessandro Caruso */

#include "display.h"

void DisplayApplication::run() {
  initWindow();
  initVulkan();
  mainLoop();
  cleanup();
}

void DisplayApplication::initWindow() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(WIDTH, HEIGHT, "ChemTools", nullptr, nullptr);
}

void DisplayApplication::initVulkan() {

}

void DisplayApplication::mainLoop() {

}

void DisplayApplication::cleanup() {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }
}
