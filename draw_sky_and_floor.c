/*
** draw_sky_and_floor.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Dec 30 16:49:48 2016 John Doe
** Last update Tue Jan 24 23:27:52 2017 Antoine Briaux
*/

#include <SFML/Graphics.h>
#include "draw_line.h"

void            draw_sky(t_my_framebuffer *frame,
                int width, int height)
{
    int         i;
    sfVector2i  from;
    sfVector2i  to;

    i = 0;
    from.x = 0;
    to.x = width;
    while (i < height / 2)
    {
        from.y = i;
        to.y = i;
        my_draw_line(frame, from, to, sfBlue);
        i += 1;
    }
}

void            draw_floor(t_my_framebuffer *frame, int width, int height)
{
    int         i;
    sfVector2i  from;
    sfVector2i  to;

    i = 0;
    from.x = 0;
    to.x = width;
    while (i <= height / 2)
    {
        from.y = height - i;
        to.y = height - i;
        my_draw_line(frame, from, to, sfWhite);
        i += 1;
    }
}

void    draw_sky_and_floor(t_my_framebuffer *frame, int width, int height)
{
    draw_sky(frame, width, height);
    draw_floor(frame, width, height);
}
