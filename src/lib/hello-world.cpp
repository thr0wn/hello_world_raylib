#include "hello-world.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void helloWorld() {
  InitWindow(300, 300, "Hello World with raylib.");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);    
    DrawText("Hello World", 120, 150, 12, RED);    
    GuiButton((Rectangle) {115, 180, 80, 16}, "Hello World");    
    EndDrawing();    
  }
}
