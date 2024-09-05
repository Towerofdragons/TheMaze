#include "maze.h"
#include <stdio.h>

/**
 * map_parser - load the map from file into an array
 * @path: path to file
 * 
 * return - map Array
 */
int** map_parser (char* path)
 {
    int worldMap[MAP_WIDTH][MAP_HEIGHT] = {0};
    int width, height;
    char buffer[25];

    /*open file*/
    FILE * file = fopen(path, "r");

    if (file == NULL)
    {
        fprintf(stderr, "File map '%s' could not be opened!\n", path);
        return (NULL);
    }
    /*Validate Map 
     If File Empty / Invalid error out
      fprintf(stderr, "File map '%s' Invalid\n", path);
      return (NULL);
    */
    /*read sequentially i.e to [MAP WIDTH] rows for [MAP HEIGHT] length COLUMNS*/

    height = 0;
    width = 0;
    

    while (fscanf(file, "%d", &worldMap[width][height]))
    {
        width++;
        if (width == MAP_WIDTH) { // Move to the next row when a line is completed
            width = 0;
            height++;
        }
    }


    for(width = 0; width < MAP_WIDTH; width++)
    {
        for(height = 0; height < MAP_HEIGHT; height++)
        {
            printf("%i", worldMap[height][width]);
        }
        printf("\n");
    }

 }

int main (void)
{
    int** map;

    map = map_parser("test.map");
}


 