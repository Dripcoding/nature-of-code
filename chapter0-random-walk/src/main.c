#include "raylib.h"
#include <stdlib.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

struct Walker {
	Vector2 position;
};

// EXAMPLE 0.1 - Traditional random walk

int main () {
	SetTargetFPS(60);
	SetRandomSeed(0);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Random Walker");

	struct Walker walker = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };

	while(!WindowShouldClose()) {
		int choice = GetRandomValue(0, 3);

		// take a step in a random direction
		if (choice == 0) {
			walker.position.x += 1; // go right
		} else if (choice == 1) {
			walker.position.x -= 1; // go left
		} else if (choice == 2) {
			walker.position.y += 1; // go down
		} else {
			walker.position.y -=1; // go up
		}

		BeginDrawing();

		DrawPixelV(walker.position, WHITE);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}