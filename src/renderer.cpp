#include "renderer.hpp"

namespace grator {

std::shared_ptr<Renderer>
Renderer::get_instance() noexcept {
    if (!s_instance) {
        std::shared_ptr<Renderer> temp{new Renderer};
        s_instance = temp;
    }
    return s_instance;
}

void
Renderer::reset_instance() noexcept {
    // request stop in run thread here

    // while(!s_is_closed);
    s_instance.reset();
}

void
Renderer::run(const WindowSettings& init_settings) {
s_is_closed = false;
  WindowSettings settings = init_settings;
  InitWindow(settings.width, settings.height, settings.title.c_str());
  SetTargetFPS(settings.fps);
  
  while (!WindowShouldClose()/* && !stop_token.stop_requested() */) {
    BeginDrawing();
    ClearBackground(WHITE);

    DrawText("Hello, Raylib!", 10, 10, 20, MAROON);
    DrawRectangle(200, 200, 100, 50, GREEN);

    EndDrawing();
  }
  CloseWindow();
  s_is_closed = true;
}

} // namespace grator