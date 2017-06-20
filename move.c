/*
** move.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Jan  6 12:27:14 2017 Antoine Briaux
** Last update Fri Jan  6 12:31:25 2017 Antoine Briaux
*/

#include <SFML/Graphics.h>
#include <math.h>

sfVector2f      move_forward(sfVector2f pos, float direction, float distance)
{
    direction *= M_PI / 180;
    pos.x += distance * cos(direction);
    pos.y += distance * sin(direction);
    return (pos);
}

sfVector2f      move_backward(sfVector2f pos, float direction, float distance)
{
    direction *= M_PI / 180;
    pos.x -= distance * cos(direction);
    pos.y -= distance * sin(direction);
    return (pos);
}
