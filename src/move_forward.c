/*
** move_forward.c for bswolf in /home/antiaskid/Documents/B1/B-MUL/bswolf3d/src/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Dec 16 09:26:28 2016 Antoine Briaux
** Last update Fri Dec 16 12:30:09 2016 Antoine Briaux
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
