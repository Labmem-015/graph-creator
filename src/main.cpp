#include "renderer.hpp"

using namespace grator;

int main(int argc, char *argv[]) {
  auto renderer = Renderer::get_instance();
  renderer->run();
  
  return EXIT_SUCCESS;
}