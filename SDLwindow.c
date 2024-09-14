#include "maze.h"
#include "helper.c"
#include "texture.c"
#include "raycast.c"
#include <stdio.h>


/*WORLD MAP*/
// int worldMap[MAP_WIDTH][MAP_HEIGHT] = {
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// };

int worldMap[MAP_WIDTH][MAP_HEIGHT] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};



// Just creating a window 
int main (void)
{
    SDL_Instance instance;
    int SDL_event_rep;

    SDL_Surface* surface;
    SDL_Texture* texture;
    int texWidth, texHeight;
    int texX;

    surface =  NULL;

    if (init_instance(&instance) != 0)
        return (1);




/**
 * PLAYER POSITION AND DIRECTION INITIALIZATION 
 */

posX = 22.0, posY = 12.0;
dirX = -1, dirY = 0;
/* CAMERA PLANE*/
planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

 /*the position of the right blue point is pos+dir+plane, and 
 the posistion of the left blue dot is pos+dir-plane (these are all vector additions).*/

/*RIGHT AND LEFT limits(CAMERA PLANE)*/
//double planeX = planeX + posX + dirX, double plane_Y = planeY + posY + dirY ;


 if (load_textures(instance, surface)) {
                printf("Unable to create textures!");
                return 1;
            }


    /**
     * This loop, per iteration will:
     *  clear the renderer
     *  draw on th renderer
     *  flush the renderer
     * 
     * Each constitutes  a frame
    */

   while ("C is killing me in a fun way")
   {
        //Poll Events
        SDL_event_rep = poll_events();

        if (SDL_event_rep == 1)
        {
            break;
        }
        else if (SDL_event_rep == 2)
        {
             if (draw_rectangle(&instance) != 0)
            {
                printf("Draw Rectangle");
                break;
            }
        } 


        renderFloor(instance.renderer,posX,  posY, dirX,  dirY,  planeX, planeY, texWidth, texHeight);

       
        for(int x = 0; x < (double)WINDOW_WIDTH; x ++)
        {
            /*Calculate ray position and direction*/

            double cameraX = 2*x / (double)WINDOW_WIDTH -1 ; // X-coordinate in camera space
            /*Camera rays*/
            /**
             *  The direction of these rays is easily calculated out of the camera: it's the sum of the direction vector of the camear
             *  and a part of the plane vector of the camera:
             */

            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;

            /* mapX and mapY represent the current square of the map the ray is in*/
            int mapX = (int)posX;
            int mapY = (int)posY;

            /* Length of array from current position to next x or y side*/
            double sideDistX;
            double sideDistY;        

            /* Length of array from one x or y side to next x or y side*/
            double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
            double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

            double perpWallDist;        

            //what direction to step in x or y-direction (either +1 or -1)
            int stepX;
            int stepY;

            int hit = 0; //was there a wall hit?
            int side; //was a N-S or a E-W wall hit?


            //calculate step and initial sideDist
            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (posX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - posX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (posY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - posY) * deltaDistY;
            }


            //perform DDA
            while (hit == 0)
            {
                //jump to next map square, either in x-direction, or in y-direction
                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                //Check if ray has hit a wall
                if (worldMap[mapX][mapY] > 0) 
                {
                    hit = 1;
                    //printf("\nHit\n");
                }
                /*TODO -  What if DDA detects no hit? eg no wall on outer borders*/
            } 
        
            //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
            if(side == 0) 
            {
                perpWallDist = (sideDistX - deltaDistX);
            }
            else
            {          
                perpWallDist = (sideDistY - deltaDistY);
            }

            //calculate line height of line to be drawn on screen

            int lineHeight = WINDOW_HEIGHT / (perpWallDist);

            //calculate lowest and highest pixel to fill current stripe
            int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
            if (drawStart < 0)
            {
                drawStart = 0;
            }

            int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;

            if (drawEnd > WINDOW_HEIGHT)
            {
                drawEnd = WINDOW_HEIGHT - 1;
            }

            
/*       

            //give x and y sides different brightness
            if (side == 1) 
            {
                texture = texture_array[worldMap[mapX][mapY]];
                //SDL_SetRenderDrawColor(instance.renderer, colour.r / 2, colour.g / 2, colour.b / 2, colour.a / 2);
            }
            else
            {
                texture = texture_array_dark[worldMap[mapX][mapY]];
                //SDL_SetRenderDrawColor(instance.renderer, colour.r, colour.g, colour.b, colour.a);
            }

            //draw the pixels of the stripe as a vertical line

            //SDL_RenderDrawLine(instance.renderer, x, drawStart, x, drawEnd);

*/
        

            double wallX; // x-coord where the wall was hit
            //give x and y sides different brightness while calculating wall X
            if (side == 0) 
            {
                wallX = posY + perpWallDist * rayDirY;
                texture = texture_array[worldMap[mapX][mapY]];
            }
            else
            {           
                wallX = posX + perpWallDist * rayDirX;
                texture = texture_array_dark[worldMap[mapX][mapY]];
            }

            wallX -= floor(wallX);

            SDL_QueryTexture(texture, NULL, NULL, &texWidth, &texHeight);
            
            texX = (int)(wallX * (double)texWidth);
            if (side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
            if (side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

            SDL_Rect srcRect = {texX, 0, 1, texHeight};
            SDL_Rect destRect = {x, drawStart, 1, drawEnd - drawStart};

            SDL_RenderCopy(instance.renderer , texture, &srcRect, &destRect);
            SDL_FreeSurface(surface);

        }


        SDL_RenderPresent(instance.renderer);

        COLOUR_BLACK(instance.renderer);
        SDL_RenderClear(instance.renderer);
        update(&instance);

   }

    // Release everything initialized by SDL
   
    destroy(&instance);

    return (0);
}

/**
 * destroy - release all SDL instance initializations
 * @instance : SDL instance struct.
 * 
 * Return: nothing
*/
void destroy (SDL_Instance *instance)
{
    SDL_DestroyRenderer(instance->renderer);
    SDL_DestroyWindow(instance->window);
    SDL_Quit();
}




/**
 * poll_events - Retrieve events on each frame(Ideally works every frame)
 * 
 * Return - it value TODO
 * To be moved
*/

int poll_events(void)
{
    SDL_Event event;
    SDL_KeyboardEvent key;

    double oldDirX;
    double oldPlaneX;

    // Curse over the event stack to identify new events.
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

            case SDL_KEYDOWN:
                key = event.key;
                /* If escape is pressed*/
                if (key.keysym.scancode == 0x29)
                {
                    return (1);
                }
                if (key.keysym.scancode == SDL_SCANCODE_R)
                {
                    return (2);
                }

                // Move forward with no obstacle
            
                if (key.keysym.scancode == SDL_SCANCODE_W)
                {
                    if(DEBUG) printf("Back/n");
                
                    if(worldMap[(int)(posX + dirX * move_speed)][(int)posY] == 0)
                    {
                        posX += dirX * move_speed;
                    }

                        if(worldMap[(int)posX][(int)(posY + dirY * move_speed)] == 0)
                    {
                        posY += dirY * move_speed;
                    }
                }

                // Move backward with no obstacle
                 if (key.keysym.scancode == SDL_SCANCODE_S)
                 {
                    if(DEBUG) printf("Forward/n");
                    if(worldMap[(int)(posX - dirX * move_speed)][(int)posY] == 0)
                    {
                        posX -= dirX * move_speed;
                    }

                     if(worldMap[(int)posX][(int)(posY - dirY * move_speed)] == 0)
                    {
                        posY -= dirY * move_speed;
                    }
                 }

                 /*Rotate Left*/
                if (key.keysym.scancode == SDL_SCANCODE_LEFT)
                {
                    if(DEBUG) printf("Turn Left/n");
                    oldDirX = dirX;
                    dirX = dirX * cos(rotation_speed) - dirY * sin(rotation_speed);
                    dirY = oldDirX * sin(rotation_speed) + dirY * cos(rotation_speed);
                    oldPlaneX = planeX;
                    planeX = planeX * cos(rotation_speed) - planeY * sin(rotation_speed);
                    planeY = oldPlaneX * sin(rotation_speed) + planeY * cos(rotation_speed);
                
                }

                 /*Rotate Right*/
                if (key.keysym.scancode ==  SDL_SCANCODE_RIGHT)
                {
                    if(DEBUG) printf("Turn Right/n");
                    oldDirX = dirX;
                    dirX = dirX * cos(-rotation_speed) - dirY * sin(-rotation_speed);
                    dirY = oldDirX * sin(-rotation_speed) + dirY * cos(-rotation_speed);
                    oldPlaneX = planeX;
                    planeX = planeX * cos(-rotation_speed) - planeY * sin(-rotation_speed);
                    planeY = oldPlaneX * sin(-rotation_speed) + planeY * cos(-rotation_speed);

                }

            break;
                
            case SDL_QUIT:
                return (1);  
            
            default:
                break;
        }

    }

    return (0);
}



/**
 * init_instance -  initializes an SDL Instance
 * @instance_address: Pointer variable containing address to instance struct
*/
int init_instance(SDL_Instance * instance_address)
{
    /*Initialize SDL*/
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Unable to Initialize SDL Instance: %s\n", SDL_GetError());
        return (1);
    }
    instance_address->window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    
    if (instance_address->window == NULL)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }

    

    /*Create new renderer instance linked to the window*/
    instance_address->renderer = SDL_CreateRenderer( instance_address->window, -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    

    if (instance_address->renderer == NULL)
    {
        SDL_DestroyWindow(instance_address->window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return(1);
    }


    return (0);
}