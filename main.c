#include "raylib.h"

#define WINDOW_WIDTH 120
#define WINDOW_HEIGHT 90
#define SPRITE_W 27
#define SPRITE_H 34

int main() {

  SetWindowPosition(1, 2);
  SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TRANSPARENT);

  SetTargetFPS(60);
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Clippy");

  int current_monitor = GetCurrentMonitor();
  int current_monitor_w = GetMonitorWidth(current_monitor);
  int current_monitor_h = GetMonitorHeight(current_monitor);

  int current_window_pos_x = current_monitor_w - WINDOW_WIDTH;
  int current_window_pos_y = current_monitor_h - WINDOW_HEIGHT;

  SetWindowPosition(current_window_pos_x, current_window_pos_y);

  // Sprite: W  * H
  // Sprite: 27 * 34
  Image sprite_sheet_img = LoadImage("./clippy.png");
  Texture2D texture = LoadTextureFromImage(sprite_sheet_img);

  Rectangle frame_rec = {0.0f, 0.0f, (float)texture.width / 27,
                         (float)texture.height / 34};

  float single_texture_width = (float)texture.width / 27;
  float single_texture_height = (float)texture.height / 34;

  int current_clippy_animation_set = 0;
  int current_frame = 0;
  int frame_speed = 8;
  int frame_counter = 0;
  bool move_clippy = false;

  while (!WindowShouldClose()) {
    // INFO: handle data

    Vector2 mouse_pos = GetMousePosition();

    frame_counter++;
    if (frame_counter >= (60 / frame_speed)) {
      frame_counter = 0;
      current_frame = (current_frame + 1) % 27;

      frame_rec.x = (float)current_frame * (float)texture.width / 27;
    }

    if (IsKeyPressed(KEY_DOWN)) {
      frame_rec.y =
          (float)current_clippy_animation_set * (float)texture.height / 34;
      current_clippy_animation_set = (current_clippy_animation_set + 1) % 34;
    }

    if (move_clippy) {
      current_window_pos_x -= 1;
      SetWindowPosition(current_window_pos_x, current_window_pos_y);
    }

    if (IsKeyPressed(KEY_M)) {
      move_clippy = !move_clippy;
    }

    // INFO: handle rendering
    ClearBackground(BLANK);
    BeginDrawing();

    DrawTextureRec(texture, frame_rec, (Vector2){0, 0}, WHITE);

    EndDrawing();
  }

  UnloadTexture(texture);

  return 1;
}
