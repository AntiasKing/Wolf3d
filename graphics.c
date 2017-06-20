/*
** graphics.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Dec 28 18:07:15 2016 John Doe
** Last update Fri Dec 30 18:44:30 2016 John Doe
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct.h"

t_my_framebuffer    *my_framebuffer_create(int width, int height);

sfRenderWindow      *create_window(char *name, int width, int height)
{
    sfRenderWindow  *window;
    sfVideoMode     mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    if (!(window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL)))
        return (NULL);
    return (window);
}

void                destroy_window(t_graphics *graphics)
{
    sfRenderWindow_destroy(graphics->window);
    free(graphics);
}

t_graphics          *set_graphics(char *name, int width,
                                int height, sfColor color)
{
    t_graphics      *graphics;

    if (!(graphics = malloc(sizeof(t_graphics))))
        return (NULL);
    if (!(graphics->window = create_window(name, width, height))) {
        free(graphics);
        return (NULL);
    }
    if (!(graphics->sprite = sfSprite_create())) {
        destroy_window(graphics);
        return (NULL);
    }
    if (!(graphics->texture = sfTexture_create(width, height))) {
        sfSprite_destroy(graphics->sprite);
        destroy_window(graphics);
        return (NULL);
    }
    if (!(graphics->frame = my_framebuffer_create(width, height))) {
        sfTexture_destroy(graphics->texture);
        sfSprite_destroy(graphics->sprite);
        destroy_window(graphics);
        return (NULL);
    }
    graphics->color = color;
    return (graphics);
}

void                destroy_graphics(t_graphics *graphics)
{
    free(graphics->frame->pixels);
    free(graphics->frame);
    sfTexture_destroy(graphics->texture);
    sfSprite_destroy(graphics->sprite);
    destroy_window(graphics);
}
