/* Copyright 2024 Alessandro Caruso */

#ifndef DISPLAY_H
#define DISPLAY_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class DisplayApplication {
 public:
  void Run();

 private:
  GLFWwindow* window;
  VkInstance instance;

  void init_window();
  void init_vulkan();
  void main_loop();
  void cleanup();

  void create_instance();
};

#endif // DISPLAY_H
