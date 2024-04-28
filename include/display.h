/* Copyright 2024 Alessandro Caruso */

#ifndef CHEMTOOLS_DISPLAY_H
#define CHEMTOOLS_DISPLAY_H

#include <optional>
#include <vector>
#include <vulkan/vulkan_core.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::vector<const char*> validation_layers = { "VK_LAYER_KHRONOS_validation" };

#ifdef NDEBUG
  const bool enable_validation_layers = false;
#else
  const bool enable_validation_layers = true;
#endif

VkResult create_debug_utils_messengerEXT(VkInstance instance,
    const VkDebugUtilsMessengerCreateInfoEXT* create_info,
    const VkAllocationCallbacks* allocator, VkDebugUtilsMessengerEXT* debug_messenger);

void destroy_debug_utils_messengerEXT(VkInstance instance,
    VkDebugUtilsMessengerEXT debug_messenger,
    const VkAllocationCallbacks* allocator);

struct QueueFamilyIndices {
  std::optional<uint32_t> graphics_family;
  std::optional<uint32_t> present_family;

  bool is_complete() {
    return graphics_family.has_value() && present_family.has_value();
  }
};

class DisplayApplication {
 public:
  void run();

 private:
  GLFWwindow* window;
  VkInstance instance;
  VkDebugUtilsMessengerEXT debug_messenger;
  VkPhysicalDevice physical_device = VK_NULL_HANDLE;
  VkDevice device;
  VkQueue graphics_queue;
  VkSurfaceKHR surface;
  VkQueue present_queue;

  void init_window();
  void init_vulkan();
  void main_loop();
  void cleanup();

  void create_instance();
  bool check_validation_layer_support();
  std::vector<const char*> get_required_extensions();
  static VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(
    VkDebugUtilsMessageSeverityFlagBitsEXT message_severity,
    VkDebugUtilsMessageTypeFlagsEXT message_type,
    const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
    void* user_data);
  void setup_debug_messenger();
  void populate_debug_messenger_create_info(VkDebugUtilsMessengerCreateInfoEXT& create_info);

  void pick_physical_device();
  bool is_device_suitable(VkPhysicalDevice device);
  QueueFamilyIndices find_queue_families(VkPhysicalDevice device);
  void create_logical_device();

  void create_surface();
};

#endif // CHEMTOOLS_DISPLAY_H
