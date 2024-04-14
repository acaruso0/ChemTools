/* Copyright 2024 Alessandro Caruso */

#ifndef DISPLAY_H
#define DISPLAY_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class DisplayApplication {
 public:
  void run();

 private:
  GLFWwindow* window;

  void initWindow();
  void initVulkan();
  void mainLoop();
  void cleanup();
};

#endif // DISPLAY_H
