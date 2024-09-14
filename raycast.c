#include "maze.h"

void draw_floors_ceilings()
{

}

void renderFloor(SDL_Renderer *renderer, float posX, float posY, float dirX, float dirY, float planeX, float planeY, int texWidth, int texHeight) {

    float posZ = 0.5 * WINDOW_HEIGHT;

    // Iterate over each row on the screen (for floor and ceiling rendering)
    for (int y = 0; y < WINDOW_HEIGHT; ++y) {
        // Calculate ray direction for leftmost and rightmost rays
        float rayDirX0 = dirX - planeX;
        float rayDirY0 = dirY - planeY;
        float rayDirX1 = dirX + planeX;
        float rayDirY1 = dirY + planeY;

        // Current y position compared to the center of the screen (horizon)
        int p = y - WINDOW_HEIGHT / 2;

        // Horizontal distance from the camera to the floor for the current row
        float rowDistance = posZ / p;

        // Calculate the step size for each x-column (moving along the floor)
        float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / WINDOW_WIDTH;
        float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / WINDOW_WIDTH;

        // Initialize the floor position for the leftmost column
        float floorX = posX + rowDistance * rayDirX0;
        float floorY = posY + rowDistance * rayDirY0;

        // Iterate over each column on the screen
        for (int x = 0; x < WINDOW_WIDTH; ++x) {
            // Get the cell coordinates by taking the integer part of floorX and floorY
            int cellX = (int)floorX;
            int cellY = (int)floorY;

            
            SDL_Texture* texture;
            texture =  FLOOR_TEXTURE;
            SDL_QueryTexture(texture, NULL, NULL, &texWidth, &texHeight);

            // Get the texture coordinates from the fractional part of floorX and floorY
            int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
            int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

            // Step to the next position on the floor
            floorX += floorStepX;
            floorY += floorStepY;


            // SDL_Rect srcRect = {texX, 0, 1, texHeight};
            // SDL_Rect destRect = {x, drawStart, 1, drawEnd - drawStart};

            // Create a source SDL_Rect to select the pixel from the texture
            SDL_Rect srcRect = { tx, ty, 1, 1 }; // We are rendering 1x1 texture pixels

            // Create a destination SDL_Rect for where to render the pixel on screen
            SDL_Rect dstRectFloor = { x, y, 1, 1 }; // Render floor pixel at (x, y)
            SDL_Rect dstRectCeiling = { x, WINDOW_HEIGHT - y - 1, 1, 1 }; // Render ceiling pixel symmetrically

            // Render floor pixel using SDL_RenderCopy
            SDL_RenderCopy(renderer, texture, &srcRect, &dstRectFloor);

            // Render ceiling pixel using SDL_RenderCopy
            SDL_RenderCopy(renderer, texture, &srcRect, &dstRectCeiling);
        }
    }
}


