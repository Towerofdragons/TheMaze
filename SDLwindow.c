#include "maze.h"
#include "helper.c"
#include <stdio.h>

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
     * This loop, per iteration will:
     *  clear the renderer
     *  draw on th renderer
     *  flush the renderer
     * 
     * Each constitutes  a frame
    */

   while ("This is a lot of work, but fun")
   {

        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
        //SDL_RenderClear(instance.renderer);
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