/*
** raycast_FOV.h for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Dec 30 17:20:06 2016 John Doe
** Last update Fri Jan 13 13:29:36 2017 Antoine Briaux
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include "struct.h"
# define FOV 90.0
# define PROJ_DIST 2
# define HEIGHT_SLICE 900

float   raycast(sfVector2f, float, int **, sfVector2i);

float   *length_line(float *tab, int width)
{
    int i;

    i = 0;
    while (i < width)
    {
        tab[i] = HEIGHT_SLICE * PROJ_DIST / tab[i] * cos(FOV);
        i += 1;
    }
    return (tab);
}

float       *raycast_all(t_player player, t_map *map, int width)
{
    int     i;
    double  angle;
    float   *tab;
    sfVector2i  size;

    if (!(tab = malloc(sizeof(float) * width)))
        return (NULL);
    i = 0;
    angle = - FOV / 2;
    size.x = map->size_lines[0];
    size.y = map->nbr_line;
    while (i < width && angle < FOV / 2)
    {
        tab[i] = raycast(player.pos, player.direction + angle, map->map, size);
        angle += FOV / width;
        i += 1;
    }
    tab = length_line(tab, width);
    return (tab);
}
