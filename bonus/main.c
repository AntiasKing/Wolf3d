/*
** main.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec 27 18:02:35 2016 John Doe
** Last update Tue Jan 24 23:33:39 2017 Antoine Briaux
*/

#include <stdlib.h>
#include "list.h"
#include "main.h"
# define MOVE 0.1
# define ANGLE 3
# define RIGHT 0
# define LEFT 1
# define UP 2
# define DOWN 3

t_player        move(t_player player, t_map map)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
        player.pos = move_forward(player.pos, player.direction, MOVE, map);
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
        player.pos = move_backward(player.pos, player.direction, MOVE, map);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
        player.pos = move_left(player.pos, player.direction, MOVE, map);
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
        player.pos = move_right(player.pos, player.direction, MOVE, map);
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

void       change_mouse_state(t_mouse *mouse, t_graphics *graphics)
{
    if (mouse->visible)
        mouse->visible = sfFalse;
    else
        mouse->visible = sfTrue;
    sfWindow_setMouseCursorVisible((sfWindow *)
    graphics->window, mouse->visible);
}

void        check_event(t_graphics *graphics, t_player *player, t_mouse *mouse)
{
    while (sfRenderWindow_pollEvent(graphics->window, &(graphics->event)))
    {
        if (graphics->event.type == sfEvtClosed)
            sfRenderWindow_close(graphics->window);
        if (graphics->event.type == sfEvtMouseMoved)
            player->direction = change_direction(graphics, player->direction);
        if (graphics->event.type == sfEvtKeyReleased)
        {
            if (graphics->event.key.code == 17)
                change_mouse_state(mouse, graphics);
            if (graphics->event.key.code == 36)
                sfRenderWindow_close(graphics->window);
        }
    }
}

int             main(int ac, char **av)
{
    t_list      *list;
    t_map       *map;
    t_graphics  *graphics;
    t_player    player;
    t_mouse     mouse;

    if (ac != 2)
        return (84);
    set_all(&map, &list, av[1], &graphics, &mouse);
    player = set_player(player);
    sfSprite_setTexture(graphics->sprite, graphics->texture, sfTrue);
    while (sfRenderWindow_isOpen(graphics->window))
    {
        check_event(graphics, &player, &mouse);
        if (!mouse.visible)
            sfMouse_setPosition(mouse.pos, (sfWindow *) graphics->window);
        player = move(player, *map);
        all(graphics, map, player);
    }
    destroy_graphics(graphics);
    return (0);
}
