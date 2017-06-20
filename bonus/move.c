/*
** move.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Jan  6 12:27:14 2017 Antoine Briaux
** Last update Tue Jan 24 23:39:23 2017 Antoine Briaux
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "struct.h"
# define PREC 100

sfVector2f      move_forward(sfVector2f pos,
                float direction, float distance, t_map map)
{
    float       y;
    float       x;

    direction *= M_PI / 180;
    x = distance * cos(direction);
    y = distance * sin(direction);
    if (map.map[(int) (pos.y + y)][(int) (pos.x + x)] != 1)
    {
        pos.x += x;
        pos.y += y;
    }
    return (pos);
}

sfVector2f      move_backward(sfVector2f pos,
                float direction, float distance, t_map map)
{
    float       y;
    float       x;

    direction *= M_PI / 180;
    x = distance * cos(direction);
    y = distance * sin(direction);
    if (map.map[(int) (pos.y - y)][(int) (pos.x - x)] != 1)
    {
        pos.x -= x;
        pos.y -= y;
    }
    return (pos);
}

sfVector2f      move_left(sfVector2f pos,
                float direction, float distance, t_map map)
{
    float       y;
    float       x;

    direction *= M_PI / 180;
    x = distance * cos(direction - M_PI / 2);
    y = distance * sin(direction - M_PI / 2);
    if (map.map[(int) (pos.y + y)][(int) (pos.x + x)] != 1)
    {
        pos.x += x;
        pos.y += y;
    }
    return (pos);
}

sfVector2f      move_right(sfVector2f pos,
                float direction, float distance, t_map map)
 {
     float      y;
     float      x;

     direction *= M_PI / 180;
     x = distance * cos(direction + M_PI / 2);
     y = distance * sin(direction + M_PI / 2);
     if (map.map[(int) (pos.y + y)][(int) (pos.x + x)] != 1)
     {
         pos.x += x;
         pos.y += y;
     }
     return (pos);
 }

float           change_direction(t_graphics *graphics, float direction)
{
    sfVector2i  mouse_move;

    mouse_move = sfMouse_getPosition((sfWindow *) graphics->window);
    direction += (mouse_move.x - graphics->frame->width / 2) / PREC;
    return (direction);
}
