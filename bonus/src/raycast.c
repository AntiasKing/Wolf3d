/*
** raycast.c for raycast in /home/antiaskid/Documents/B1/B-MUL/bswolf3d/src/
**
** Made by Antoine Briaux
** Login   <antoine.briaux@epitech.eu>
**
** Started on  Fri Dec 16 11:07:17 2016 Antoine Briaux
** Last update Fri Jan  6 12:40:33 2017 Antoine Briaux
*/

#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

typedef struct  s_tab
{
    sfVector2f  vector;
    float       k;
}               t_tab;

float       raycast(sfVector2f pos, float direction, int **map,
                                                sfVector2i mapSize)
{
    float   k;
    int     j;
    t_tab   tab[1000];

    direction *= M_PI / 180;
    k = 0;
    j = 0;
    while (j < 1000)
    {
        tab[j].vector.x = pos.x + k * cos(direction);
        tab[j].vector.y = pos.y + k * sin(direction);
        tab[j].k = k;
        k += .003;
        j += 1;
    }
    j = 0;
    k = tab[500].k;
    while (j < 1000 && tab[j].vector.x < mapSize.x &&
                            tab[j].vector.y < mapSize.y)
    {
        if (tab[j].k < k &&
            map[(int) tab[j].vector.y][(int) tab[j].vector.x] == 1)
            k = tab[j].k;
        j += 1;
    } return (k);
}
