#include "maze.h" 
#define brightness_factor 0.5 /*ALWAYS between 1 and 0*/
/**
 * load_textures - loads all provided textures into texture array
 * @instance: SDL Instance struct for current window
 * @surface: Surface variable to load images before texture creation
 * 
 * return: integer error code
 */
int load_textures(SDL_Instance instance, SDL_Surface* surface)
{   
    char path[100];

    for (int i = 0; i < TEXTURE_COUNT; i++)
    {
        /*Construct complete path to texture*/
        strcpy(path, STATIC_FOLDER);
        strncat(path, texture_list[i], sizeof(path) - strlen(path) -1);

        /*Create surface and texture*/
        if (DEBUG) printf("%s\n", path);
        surface = IMG_Load(path);
        if (!surface) {
            printf("Unable to load image! IMG_Error: %s\n", IMG_GetError());
            return 1;
        }

        if (DEBUG) printf("Loading  texture from surface\n");
        texture_array[i] = SDL_CreateTextureFromSurface(instance.renderer, surface);
        texture_array_dark[i] = SDL_CreateTextureFromSurface(instance.renderer, surface);

        if (DEBUG) printf("Loading  texture from surface... Done!\n");
        
        adjust_brightness(texture_array_dark[i]);
        if (!texture_array[i]) {
            printf("Unable to create texture! SDL_Error: %s\n", SDL_GetError());
            return 1;
        }
    }
    return (0);
}

/**
 * adjust_brightness -  Adjust texture brightness
 * @texture: texture currently in use
 * 
 * return: nothing
 */
void adjust_brightness(SDL_Texture *texture)
{
    Uint8 r;
    Uint8 g;
    Uint8 b;

    SDL_GetTextureColorMod(texture, &r, &g, &b);

    if (DEBUG) printf("before r: %d g: %d b: %d\n", r, g, b);

    r = (Uint8) (r * brightness_factor);
    g = (Uint8) (g * brightness_factor);
    b = (Uint8) (b * brightness_factor);
    
    if (DEBUG) printf("after r: %d g: %d b: %d\n", r, g, b);

    SDL_SetTextureColorMod(texture, r, g, b);

}