/*
** my_draw_line.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Dec 28 17:48:44 2016 John Doe
** Last update Fri Jan 13 13:57:36 2017 Antoine Briaux
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include "framebuffer.h"

void        my_put_pixel(t_my_framebuffer *, int, int, sfColor);

void        my_draw_line(t_my_framebuffer   *framebuffer,
            sfVector2i from, sfVector2i to, sfColor color)
{
    int     i;

    if (from.x == to.x && from.x > 0 && from.x < framebuffer->width)
    {
        if (from.y > framebuffer->height)
            from.y = framebuffer->height;
        if (to.y < 0)
            to.y = 0;
        i = to.y;
        while (i < from.y)
        {
            my_put_pixel(framebuffer, from.x, i, color);
            i += 1;
        }
    }
}
