namespace grator {

struct WindowSettings {
  int width = 800;
  int height = 600;
  int fps = 60;
  std::string title = "Hello, raylib!";
};
} // namespace grator

int main(int argc, char *argv[]) {
  grator::WindowSettings settings;
  InitWindow(settings.width, settings.height, settings.title.c_str());
  SetTargetFPS(settings.fps);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    DrawText("Hello, Raylib!", 10, 10, 20, MAROON);
    DrawRectangle(200, 200, 100, 50, GREEN);

    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}