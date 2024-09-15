#ifndef MAZE_H
#define MAZE_H

#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>

/*DEBUG MODE*/
#define DEBUG 1


/* Define FPS */
#define FPS 30
#define TARGET_FRAME_TIME (1000 / FPS) /*Time expected for each frame*/

int last_frame_time = 0;

/**
 * PLAYER POSITION AND DIRECTION INITIALIZATION 
 */

double posX, posY;
double dirX, dirY;
/* CAMERA PLANE*/
double planeX, planeY; //the 2d raycaster version of camera plane

double move_speed;
double rotation_speed;


/* A series of shortcuts to define render colour*/
#define COLOUR_WHITE(x) SDL_SetRenderDrawColor(x, 255, 255, 255, 255);
#define COLOUR_BLACK(x) SDL_SetRenderDrawColor(x, 0, 0, 0, 255);
#define COLOUR_RED(x) SDL_SetRenderDrawColor(x, 255, 0, 0, 255);
#define COLOUR_GREEN(x) SDL_SetRenderDrawColor(x, 0, 255, 0, 255);
#define COLOUR_BLUE(x) SDL_SetRenderDrawColor(x, 0, 0, 255, 255);
#define COLOUR_GREY(x) SDL_SetRenderDrawColor(x, 100, 100, 100, 255);

/* A more versatile way to define Render colour */
typedef struct{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} colourRGB;

const colourRGB white = {255, 255, 255, 255};
const colourRGB black={ 0, 0, 0, 255};
const colourRGB red ={ 255, 0, 0, 255};
const colourRGB green ={ 0, 255, 0, 255};
const colourRGB blue ={ 0, 0, 255, 255};
const colourRGB yellow = { 255, 255, 0, 255};
/* const colourRGB ={ , , , }; */



//Window control
#define WINDOW_W 1500
#define WINDOW_H 800

int WINDOW_WIDTH = WINDOW_W;
int WINDOW_HEIGHT = WINDOW_H;

#define MAP_WIDTH  24
#define MAP_HEIGHT  24
#define MAP_PATH "test.map"

int WALL_HEIGHT = 64;
int TILE_SIZE = 64;


/*Texture array*/
#define TEXTURE_COUNT 7
SDL_Texture *texture_array[TEXTURE_COUNT];
SDL_Texture *texture_array_dark[TEXTURE_COUNT];

#define STATIC_FOLDER "static/"

char* texture_list[TEXTURE_COUNT]= {"wood.png", "greystone.png", "pillar.png", "redbrick.png", "mossy.png", "purplestone.png", "ghost.png"};


/*Enemies*/
#define NUM_ENEMIES 5
#define ENEMY_SPEED 1.5
#define ENEMY_TEXTURE 6

typedef struct {
    float x, y;  /*Position data for enemy*/
    float speedX, speedY;  // Speed of the enemy (in x and y directions)
    SDL_Texture* texture;  // SDL texture for rendering the enemy
} Enemy;


Enemy enemies[NUM_ENEMIES];

#define true 0
#define false 1

/*ENEMY CONFIG*/
/**
 * struct player - represents the position and direction faced by the player
 * @x: enemy position x
 * @y: enemy position y
 * @width: enemy speed in X direction
 * @angle: player direction in world.
*/

// typedef struct {
//     int x, y;          // Position
//     int width, height; // Size to be rendered in
//     int speed;         // Movement speed
//     int health;        // Health or hit points
//     SDL_Texture *texture;
// } Enemy;

struct Sprite {
    SDL_Texture * texture;
    struct SDL_Rect source;
    struct SDL_Rect destination;
};
typedef struct Sprite Sprite;

#define ENEMY_TEXTURE 6

// TODO - Field of View 
double FOV = 60;

/**
 * current view (angle + FOV/2) < view > (angle - FOV/2)
*/


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
int load_textures(SDL_Instance instance, SDL_Surface* surface);
void adjust_brightness(SDL_Texture *texture);
#endif