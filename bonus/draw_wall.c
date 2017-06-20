/*
** draw_wall.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/Includes/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Dec 30 17:43:09 2016 John Doe
** Last update Fri Jan 13 13:50:54 2017 Antoine Briaux
*/

#include <SFML/Graphics.h>
#include "draw_line.h"

void            draw_wall(t_my_framebuffer *frame,
                int width, int height, float *tab)
{
    sfVector2i  from;
    sfVector2i  to;
    int         i;

    i = 0;
    while (i < width)
    {
        from.x = i;
        to.x = i;
        from.y = (height / 2.) - (tab[i] / 2.);
        to.y = (height / 2.) + (tab[i] / 2.);
        my_draw_line(frame, from, to, sfWhite);
        i += 1;
    }
}
