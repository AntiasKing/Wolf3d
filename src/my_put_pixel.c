/*
** my_put_pixel.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Dec 28 15:52:42 2016 John Doe
** Last update Fri Jan  6 16:11:24 2017 Antoine Briaux
*/

#include <SFML/Graphics.h>
#include "framebuffer.h"

void                my_put_pixel(t_my_framebuffer *framebuffer,
                                        int x, int y, sfColor color)
{
    int             position;
    unsigned int    *pixel;

    position = (framebuffer->width * y + x) * 4;
    pixel = (void *) &(framebuffer->pixels[position]);
    if ((x > 0 && x < framebuffer->width) && (y > 0 && y < framebuffer->height))
    {
        *pixel = (color.a << 24) | (color.b << 16) | (color.g << 8) | color.r;
        framebuffer->pixels[position] = *pixel;
    }
}
