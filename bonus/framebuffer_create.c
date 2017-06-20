/*
** framebuffer_create.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Dec 28 17:40:18 2016 John Doe
** Last update Fri Dec 30 16:22:50 2016 John Doe
*/

#include <stdlib.h>
#include "framebuffer.h"

t_my_framebuffer        *my_framebuffer_create(int width, int height)
{
    int                 i;
    t_my_framebuffer    *tab;

    if (!(tab = malloc(sizeof(t_my_framebuffer))))
        return (NULL);
    if (!(tab->pixels = malloc(sizeof(sfUint8) * width * height * 4)))
    {
        free(tab);
        return (NULL);
    }
    tab->width = width;
    tab->height = height;
    i = 0;
    while (i < width * height * 4)
    {
        tab->pixels[i] = 0;
        i += 1;
    }
    return (tab);
}

void    framebuffer_destroy(t_my_framebuffer *frame)
{
    free(frame->pixels);
    free(frame);
}
