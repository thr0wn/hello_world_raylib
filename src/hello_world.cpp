#include "raylib.h"
#include <iostream>

int main() {
  InitWindow(300, 300, "Hello World with raylib.");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);    
    DrawText("Hello World", 120, 150, 12, RED);    
    EndDrawing();    
  }
}
