#include "maze.h"

// Initialize enemies with random positions and basic movement
void init_enemies(Enemy enemies[], SDL_Texture *enemyTexture)
{
    for (int i = 0; i < NUM_ENEMIES; i++) {
        enemies[i].x = rand() % WINDOW_WIDTH;
        enemies[i].y = rand() % WINDOW_HEIGHT;
        enemies[i].speedX = ((float)rand() / RAND_MAX) * ENEMY_SPEED - ENEMY_SPEED / 2; // Random speed in X
        enemies[i].speedY = ((float)rand() / RAND_MAX) * ENEMY_SPEED - ENEMY_SPEED / 2; // Random speed in Y
        enemies[i].texture = enemyTexture;  // Assign texture to each enemy
    }
}

// Update the position of each enemy (basic movement)
void update_enemies(Enemy enemies[])
{
    for (int i = 0; i < NUM_ENEMIES; i++) {
        enemies[i].x += enemies[i].speedX;
        enemies[i].y += enemies[i].speedY;

        // Bounce off walls
        if (enemies[i].x < 0 || enemies[i].x > WINDOW_WIDTH - 32) {  // Assuming 32px enemy size
            enemies[i].speedX = -enemies[i].speedX;
        }
        if (enemies[i].y < 0 || enemies[i].y > WINDOW_HEIGHT - 32) {
            enemies[i].speedY = -enemies[i].speedY;
        }
    }
}

// Render enemies on the screen
void render_enemies(SDL_Renderer *renderer, Enemy enemies[])
{
    SDL_Rect dstRect;
    for (int i = 0; i < NUM_ENEMIES; i++) {
        dstRect.x = (int)enemies[i].x;
        dstRect.y = (int)enemies[i].y;
        dstRect.w = 32;  // Assuming enemy width is 32 pixels
        dstRect.h = 32;  // Assuming enemy height is 32 pixels
        SDL_RenderCopy(renderer, enemies[i].texture, NULL, &dstRect);
    }
}

// Main function to handle enemies in the game loop
// void handle_enemies(SDL_Renderer *renderer, SDL_Texture *enemyTexture)
// {
//     Enemy enemies[NUM_ENEMIES];
//     init_enemies(enemies, renderer, enemyTexture);

//     // Main game loop
//     int running = 1;
//     SDL_Event event;

//     while (running) {
//         // Handle events (e.g., quitting the game)
//         while (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT) {
//                 running = 0;
//             }
//         }

//         // Clear the screen
//         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Set background to black
//         SDL_RenderClear(renderer);

//         // Update and render enemies
//         update_enemies(enemies);
//         render_enemies(renderer, enemies);

//         // Present the updated screen
//         SDL_RenderPresent(renderer);

//         // Control the frame rate (delay for 16ms ~ 60 FPS)
//         SDL_Delay(16);
//     }
// }
