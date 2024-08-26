#include "maze.h"
#include "helper.c"
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

    if (init_instance(&instance) != 0)
        return (1);

    //           L1, L2
    int p1X[] = {0, 750}; //P1L1
    int p1Y[] = {400, 0}; //P1L2

    int p2X[] = {1500, 750};//P2L1
    int p2Y[] = {400, 800};//P2L2
    
    int i = 0;
    int array_bound = 2;

    square.x = 0;
    square.y = WINDOW_HEIGHT/4;
    square.w = 50;
    square.h = 50;



/**
 * PLAYER POSITION AND DIRECTION INITIALIZATION 
 */

double posX = 2.0, posY = 2.0;
double dirX = 0.5, dirY = 0.0;
/* CAMERA PLANE*/
double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

 /*the position of the right blue point is pos+dir+plane, and 
 the posistion of the left blue dot is pos+dir-plane (these are all vector additions).*/

/*RIGHT AND LEFT limits(CAMERA PLANE)*/
//double planeX = planeX + posX + dirX, double plane_Y = planeY + posY + dirY ;




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

        COLOUR_BLACK(instance.renderer);
        SDL_RenderClear(instance.renderer);
        update(&instance);

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

        // Draw axes
        draw_line(&instance, p1X[i], p1Y[i], p2X[i], p2Y[i]);
        i++;
        draw_line(&instance, p1X[i], p1Y[i], p2X[i], p2Y[i]);
       
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
            int side; //was a NS or a EW wall hit?


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
                    printf("\nHit\n");
                }
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

            printf("%i",side);

            //choose wall color
            switch(worldMap[mapX][mapY])
            {
                case 1: COLOUR_BLUE(instance.renderer); break; //red
                case 2: COLOUR_GREEN(instance.renderer); break; //green
                case 3:  COLOUR_WHITE(instance.renderer); break; //blue
                case 4: COLOUR_BLUE(instance.renderer);  break; //white
                default: COLOUR_RED(instance.renderer); break; //yellow
            }

            //give x and y sides different brightness
            if (side == 1) {COLOUR_GREY(instance.renderer);}

            //draw the pixels of the stripe as a vertical line

            SDL_RenderDrawLine(instance.renderer, x, drawStart, x, drawEnd);

        }


        SDL_RenderPresent(instance.renderer);

        i++;
        if (i == array_bound)
            i = 0;

       // printf("%i",p1[i]);
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

    // Curse over the event stack to identify new events.
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                return (1);

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

                break;
            
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