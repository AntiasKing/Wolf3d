/*
** main.h for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/Includes/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Dec 30 16:12:47 2016 John Doe
** Last update Tue Jan 24 23:36:23 2017 Antoine Briaux
*/

#ifndef __MAIN_H__
# define __MAIN_H__

# include <SFML/Graphics.h>
# include "struct.h"
# define WIDTH 1600
# define HEIGHT 900

t_map       *set_map(char *str);
t_graphics  *set_graphics(char *, int, int, sfColor);
void        destroy_graphics(t_graphics *);
void        draw_sky_and_floor(t_my_framebuffer *, int, int);
float       *raycast_all(t_player, t_map *, int);
void        draw_wall(t_my_framebuffer *, int, int, float *);
sfVector2f  move_forward(sfVector2f, float, float, t_map);
sfVector2f  move_backward(sfVector2f, float, float, t_map);
sfVector2f  move_left(sfVector2f, float, float, t_map);
sfVector2f  move_right(sfVector2f, float, float, t_map);
float       change_direction(t_graphics *graphics, float direction);
void        set_all(t_map **, t_list **, char *, t_graphics **, t_mouse *);
t_player    set_player(t_player player);

#endif /*!__MAIN_H__*/
