/*
** my_draw_line.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Dec 28 17:48:44 2016 John Doe
** Last update Fri Jan 13 14:17:41 2017 Antoine Briaux
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "framebuffer.h"

void        my_put_pixel(t_my_framebuffer *, int, int, sfColor);

int         my_abs(int x)
{
    if (x < 0)
        return (-x);
    return (x);
}

void        my_draw_line(t_my_framebuffer   *framebuffer,
            sfVector2i from, sfVector2i to, sfColor color)
{
    float   length;
    float   delta_x;
    float   delta_y;
    float   x;
    float   y;
    int     i;

    if (my_abs(to.x - from.x) >= my_abs(to.y - from.y))
        length = my_abs(to.x - from.x);
    else
        length = my_abs(to.y - from.y);
    delta_x = (to.x - from.x) / length;
    delta_y = (to.y - from.y) / length;
    x = from.x + 0.5;
    y = from.y + 0.5;
    i = 1;
    while (i <= length)
    {
        my_put_pixel(framebuffer, x, y, color);
        x += delta_x;
        y += delta_y;
        i += 1;
    }
}
