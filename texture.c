   #include "maze.h" 

int load_textures(SDL_Instance instance, SDL_Surface* surface)
{   
    char path[100];

    for (int i = 0; i < TEXTURE_NUMBER; i++)
    {
        strcpy(path, STATIC_FOLDER);

        strncat(path, texture_list[i], sizeof(path) - strlen(path) -1);
        /*Create surface and texture*/
        if (DEBUG) printf("%s\n", path);
        surface = IMG_Load(path);
        if (!surface) {
            printf("Unable to load image! IMG_Error: %s\n", IMG_GetError());
            return 1;
        }

        texture_array[i] = SDL_CreateTextureFromSurface(instance.renderer, surface);
        if (!texture_array[i]) {
            printf("Unable to create texture! SDL_Error: %s\n", SDL_GetError());
            return 1;
        }
    }
    return (0);
}