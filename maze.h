#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>

/* Define FPS */
#define FPS 30
#define TARGET_FRAME_TIME (1000 / FPS) /*Time expected for each frame*/

int last_frame_time = 0;


/* A series of shortcuts to define render colour*/
#define COLOUR_WHITE(x) SDL_SetRenderDrawColor(x, 255, 255, 255, 255);
#define COLOUR_BLACK(x) SDL_SetRenderDrawColor(x, 0, 0, 0, 255);
#define COLOUR_RED(x) SDL_SetRenderDrawColor(x, 255, 0, 0, 255);
#define COLOUR_GREEN(x) SDL_SetRenderDrawColor(x, 0, 255, 0, 255);
#define COLOUR_BLUE(x) SDL_SetRenderDrawColor(x, 0, 0, 255, 255);


//Window control
int WINDOW_WIDTH = 1500;
int WINDOW_HEIGHT = 800;

#define WINDOW_W 1500
#define WINDOW_H 800

#define true 0
#define false 1


/**
 * struct SDL_Instance - to contain window and associated renderer address.
 * 
 * @window: contain window address for this particular instance
 * @renderer: contain renderer address for this particular instance
*/

typedef struct{
    SDL_Window *window;
    SDL_Renderer *renderer;

} SDL_Instance;

SDL_Rect square; // todo. Globally available square instance to be removed

int init_instance(SDL_Instance *);
void draw_line(SDL_Instance * instance,  int x1, int x2, int y1, int y2);
int draw_rectangle(SDL_Instance * instance);
int draw_square(SDL_Instance * instance);
int poll_events(void);
void destroy(SDL_Instance * instance);
void update(SDL_Instance * instance);

#endif