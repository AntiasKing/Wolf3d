/*
** collide.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/bonus/inc/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Thu Jan 12 19:31:46 2017 Antoine Briaux
** Last update Fri Jan 13 10:52:24 2017 Antoine Briaux
*/

#include "struct.h"
# define DIST .1

int     check_collide(t_map map, t_player player, int dir)
{
    if (dir == 0)
    {
        if (map.map[(int) player.pos.y][(int) (player.pos.x + DIST)] == 1)
            return (0);
    }
    else if (dir == 1)
    {
        if (map.map[(int) player.pos.y][(int) (player.pos.x - DIST)] == 1)
            return (0);
    }
    else if (dir == 2)
    {
        if (map.map[(int) (player.pos.y + DIST)][(int) player.pos.x] == 1)
            return (0);
    }
    else if (dir == 2)
    {
        if (map.map[(int) (player.pos.y - DIST)][(int) player.pos.x] == 1)
            return (0);
    }
    return (1);
}
