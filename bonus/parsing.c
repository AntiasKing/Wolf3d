/*
** parsing.c for wolf in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Dec 22 13:28:15 2016 John Doe
** Last update Tue Jan 24 23:34:15 2017 Antoine Briaux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "tools.h"
# define __READ_SIZE__ 64

t_list      *read_map(int fd)
{
    t_list  *list;
    char    *buffer;

    if (!(buffer = xmalloc(__READ_SIZE__)))
        return (NULL);
    if (!(list = malloc(sizeof(t_list))))
        return (NULL);
    list->nbr_elem = 0;
    list->first = NULL;
    while (read(fd, buffer, __READ_SIZE__ - 1))
        add_end_list(list, buffer);
    return (list);
}

char            *create_str(t_list *list)
{
    t_elem      *tmp;
    char        *str;

    if (!(str = xmalloc(__READ_SIZE__ * list->nbr_elem)))
        return (NULL);
    tmp = list->first;
    while (tmp != NULL)
    {
        my_strcat(str, (char *) tmp->elem);
        tmp = tmp->next;
    }
    delete_list(list);
    return (str);
}
