/* Copyright 2024 Alessandro Caruso */

#ifndef CHEMTOOLS_DISPLAY_H
#define CHEMTOOLS_DISPLAY_H

#include <optional>
#include <string>
#include <vector>
#include <vulkan/vulkan_core.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::vector<const char*> validation_layers = { "VK_LAYER_KHRONOS_validation" };
const std::vector<const char*> device_extensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

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

struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> present_modes;
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
  VkQueue present_queue;
  VkSurfaceKHR surface;
  VkSwapchainKHR swap_chain;
  std::vector<VkImage> swap_chain_images;
  VkFormat swap_chain_image_format;
  VkExtent2D swap_chain_extent;
  std::vector<VkImageView> swap_chain_image_views;
  VkRenderPass render_pass;
  VkPipelineLayout pipeline_layout;
  VkPipeline graphics_pipeline;
  std::vector<VkFramebuffer> swap_chain_framebuffers;
  VkCommandPool command_pool;
  VkCommandBuffer command_buffer;

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
  bool check_device_extension_support(VkPhysicalDevice device);
  SwapChainSupportDetails query_swap_chain_support(VkPhysicalDevice device);
  VkSurfaceFormatKHR choose_swap_surface_format(const std::vector<VkSurfaceFormatKHR>& available_formats);
  VkPresentModeKHR choose_swap_present_mode(const std::vector<VkPresentModeKHR>& available_present_modes);
  VkExtent2D choose_swap_extent(const VkSurfaceCapabilitiesKHR& capabilities);
  void create_swap_chain();
  
  void create_image_views();
  void create_graphics_pipeline();

  static std::vector<char> read_binary_file(const std::string& filename);
  VkShaderModule create_shader_module(const std::vector<char>& code);
  void create_render_pass();
  void create_framebuffers();
  void create_command_pool();
  void create_command_buffer();
  void record_command_buffer(VkCommandBuffer command_buffer, uint32_t image_index);

  void draw_frame();
};

#endif // CHEMTOOLS_DISPLAY_H
