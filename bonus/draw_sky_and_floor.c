/*
** draw_sky_and_floor.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Dec 30 16:49:48 2016 John Doe
** Last update Fri Jan 13 13:54:03 2017 Antoine Briaux
*/

#include <SFML/Graphics.h>
#include "draw_line.h"

void            draw_sky(t_my_framebuffer *frame,
                int width, int height)
{
    int         i;

    i = 0;
    while (i < height * width * 2)
    {
        frame->pixels[i] = 0;
        i += 1;
    }
}

void            draw_floor(t_my_framebuffer *frame,
                int width, int height)
{
    int         i;

    i = height * width * 2;
    while (i <= height * width * 4)
    {
        frame->pixels[i] = 0;
        i += 1;
    }
}

void    draw_sky_and_floor(t_my_framebuffer *frame, int width, int height)
{
    draw_sky(frame, width, height);
    draw_floor(frame, width, height);
}
