#pragma once

namespace grator {

struct WindowSettings {
  int width = 800;
  int height = 600;
  int fps = 60;
  std::string title = "Hello, raylib!";
};


class Renderer {
public:
    static std::shared_ptr<Renderer> get_instance() noexcept;
    static void reset_instance() noexcept;

    void run(const WindowSettings& init_settings = {});
private:
    Renderer() = default;
    Renderer(const Renderer&) = delete;
    Renderer(Renderer &&) = delete;
private:
  inline static std::shared_ptr<Renderer> s_instance;
  inline static std::atomic<bool> s_is_closed = false;
};

} // namespace grator