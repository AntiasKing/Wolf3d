/*
** struct.h for struct in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec 27 20:14:38 2016 John Doe
** Last update Tue Jan 24 23:31:32 2017 Antoine Briaux
*/

#ifndef __STRUCT_H__
# define __STRUCT_H__

# include <SFML/Graphics.h>
# include "framebuffer.h"

typedef struct  s_map
{
    int         **map;
    int         nbr_line;
    int         *size_lines;
}               t_map;

typedef struct          s_graphics
{
    sfRenderWindow      *window;
    sfTexture           *texture;
    sfSprite            *sprite;
    t_my_framebuffer    *frame;
    sfColor             color;
    sfEvent             event;
}                       t_graphics;

typedef struct          s_player
{
    sfVector2f          pos;
    float               direction;
}                       t_player;
#endif /*__STRUCT_H__*/
