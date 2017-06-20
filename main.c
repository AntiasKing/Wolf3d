/*
** main.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec 27 18:02:35 2016 John Doe
** Last update Fri Jan 27 10:36:40 2017 Antoine Briaux
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "list.h"
#include "parsing.h"
#include "main.h"
# define MOVE 0.1
# define ANGLE 3
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

void        set_all(t_map **map, t_list **list, char *file, t_graphics **graphics)
{
    int     fd;
    char    *str;

    fd = open(file, O_RDONLY);
    *list = read_map(fd);
    str = create_str(*list);
    *map = set_map(str);
    free(str);
    *graphics = set_graphics("Wolf3d", WIDTH, HEIGHT, sfBlack);
}

t_player        move(t_player player)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
        player.pos = move_forward(player.pos, player.direction, MOVE);
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
        player.pos = move_backward(player.pos, player.direction, MOVE);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
        player.direction -= ANGLE;
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
        player.direction += ANGLE;
    return (player);
}

void        all(t_graphics *graphics, t_map *map, t_player player)
{
    float   *tab;

    tab = raycast_all(player, map, WIDTH);
    draw_sky_and_floor(graphics->frame, WIDTH, HEIGHT);
    draw_wall(graphics->frame, WIDTH, HEIGHT, tab);
    sfTexture_updateFromPixels(graphics->texture,
        graphics->frame->pixels, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_clear(graphics->window, sfBlack);
    sfRenderWindow_drawSprite(graphics->window, graphics->sprite, NULL);
    sfRenderWindow_display(graphics->window);
    free(tab);
}

int             main(int ac, char **av)
{
    t_list      *list;
    t_map       *map;
    t_graphics  *graphics;
    t_player    player;

    if (ac != 2)
        return (84);
    set_all(&map, &list, av[1], &graphics);
    player = set_player(player);
    sfSprite_setTexture(graphics->sprite, graphics->texture, sfTrue);
    while (sfRenderWindow_isOpen(graphics->window))
    {
        while (sfRenderWindow_pollEvent(graphics->window, &(graphics->event)))
        {
            if (graphics->event.type == sfEvtClosed)
                sfRenderWindow_close(graphics->window);
            if (graphics->event.type == sfEvtKeyReleased)
                if (graphics->event.key.code == 36)
                    sfRenderWindow_close(graphics->window);
        }
        player = move(player);
        all(graphics, map, player);
    }
    destroy_graphics(graphics); return (0);
}
