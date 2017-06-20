/*
** set_struct.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/bonus/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Thu Jan 12 18:07:32 2017 Antoine Briaux
** Last update Tue Jan 24 23:34:37 2017 Antoine Briaux
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "struct.h"
#include "list.h"
#include "parsing.h"
#include "main.h"
# define POSX 3.5
# define POSY 3.5
# define DIREC 0.0

t_player        set_player(t_player player)
{
    player.pos.x = POSX;
    player.pos.y = POSY;
    player.direction = DIREC;
    return (player);
}

void        set_all(t_map **map, t_list **list,
            char *file, t_graphics **graphics, t_mouse *mouse)
{
    int     fd;
    char    *str;

    fd = open(file, O_RDONLY);
    *list = read_map(fd);
    str = create_str(*list);
    *map = set_map(str);
    free(str);
    *graphics = set_graphics("Wolf3d", WIDTH, HEIGHT, sfBlack);
    mouse->pos.x = WIDTH / 2;
    mouse->pos.y = HEIGHT / 2;
    mouse->visible = 1;
}
