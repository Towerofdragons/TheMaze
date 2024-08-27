#include "maze.h"
#include <stdio.h>


/**
 * draw_line - Draw a line
 * @instance: The sdl instance to be affected
 *  Return: nothing
*/

void draw_line(SDL_Instance *instance_address, int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(instance_address->renderer, 0xFF,0xFF, 0xFF, 0xFF);

    SDL_RenderDrawLine(instance_address->renderer, x1, y1, x2, y2);
}


/**
 * draw_rectangle - Draw a rectangle outline
 * @instance: The sdl instance to be affected
 *  Return: nothing
 * To be moved
*/

int draw_rectangle(SDL_Instance *instance_address)
{
    SDL_SetRenderDrawColor(instance_address->renderer, 0xFF,0xFF, 0xFF, 0xFF);

    SDL_Rect rectangle;
    rectangle.x = WINDOW_WIDTH/4;
    rectangle.y = WINDOW_HEIGHT/4;
    rectangle.w = rectangle.x * 2;
    rectangle.h = rectangle.y *2;

    if (SDL_RenderDrawRect(instance_address->renderer, &rectangle) != 0)
    {
        return 1;
    }
    return 0;
}



/**
 * draw_square - Draw a filled square
 * @instance: The sdl instance to be affected
 *  Return: nothing
*/
int draw_square(SDL_Instance *instance_address)
{
    //SDL_SetRenderDrawColor(instance_address->renderer, 0xFF,0xFF, 0xFF, 0xFF);
    COLOUR_BLUE(instance_address->renderer);

    if (SDL_RenderFillRect(instance_address->renderer, &square) != 0)
    {
        return 1;
    }
    return 0;
}

/**
 *  update - logic to keep a fixed time per frame and regulate movement and rotation speed
 *  @instance: The sdl instance to be affected
 * 
 * Return: nothing
*/
void update(SDL_Instance * instance)
{
    // Get delta time factor for object updates.
    float delta_time =  (SDL_GetTicks() - last_frame_time) /  1000.0f;

    float time_to_wait =  SDL_GetTicks() - last_frame_time;

    if (time_to_wait > 0 && time_to_wait <= TARGET_FRAME_TIME)
    {
        SDL_Delay(time_to_wait);
    }

    square.x += 100 * delta_time;
    square.y += 0 * delta_time;
    draw_square(instance);

    last_frame_time = SDL_GetTicks();
    // speed modifier
    move_speed = (double)delta_time * 2.0;
    rotation_speed = (double)delta_time * 2.0;
}

void move()
{

}