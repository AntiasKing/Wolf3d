/*
** create_map_tab.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec 27 18:59:58 2016 John Doe
** Last update Tue Jan 24 23:23:47 2017 Antoine Briaux
*/

#include <stdlib.h>
#include "struct.h"

int     get_nbr_line(char *str)
{
    int i;
    int nbr_line;

    i = 0;
    nbr_line = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            nbr_line += 1;
        i += 1;
    }
    if (str[i - 1] != '\n')
        nbr_line += 1;
    return (nbr_line);
}

int     *get_size_lines(char *str, int nbr_line)
{
    int *size_lines;
    int i;
    int first;
    int j;

    i = 0;
    first =  0;
    j = 0;
    if (!(size_lines = malloc(sizeof(int) * nbr_line)))
        return (NULL);
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            size_lines[j] = i - first;
            j += 1;
            first = i + 1;
            i += 1;
        }
        i += 1;
    }
    size_lines[j] = 0;
    return (size_lines);
}

t_map       *set_map2(t_map *map, char *str)
{
    int     i;
    int     j;
    int     k;

    i = 0;
    k = 0;
    while (i < map->nbr_line)
    {
        j = 0;
        if (!(map->map[i] = malloc(sizeof(int) * map->size_lines[i])))
            return (NULL);
        while (j < map->size_lines[i])
        {
            if (str[k] != '\n')
            {
                map->map[i][j] = str[k] - '0';
                j += 1;
            }
            k += 1;
        }
        i += 1;
    }
    return (map);
}

t_map       *set_map(char *str)
{
    t_map   *map;

    if (!(map = malloc(sizeof(t_map))))
        return (NULL);
    map->nbr_line = get_nbr_line(str);
    map->size_lines = get_size_lines(str, map->nbr_line);
    if (!(map->map = malloc(sizeof(int *) * map->nbr_line)))
        return (NULL);
    map = set_map2(map, str);
    return (map);
}
