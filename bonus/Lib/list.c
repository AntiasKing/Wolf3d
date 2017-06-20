/*
** list.c for list in /home/antiaskid/Documents/B1/tmp/lib/lib-Util/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Dec 21 16:13:20 2016 John Doe
** Last update Fri Jan 13 14:32:57 2017 Antoine Briaux
*/

#include <stdlib.h>
#include "list.h"

char    *my_strdup(char *);

t_list          *add_end_list(t_list *list, void *elem)
{
    static int  index = 0;
    t_elem      *new;
    t_elem      *tmp;

    if (!(new = malloc(sizeof(t_elem))))
        return (NULL);
    list->nbr_elem += 1;
    new->index = index;
    index += 1;
    new->next = NULL;
    new->prev = NULL;
    new->elem = my_strdup(elem);
    if (list->first == NULL)
        list->first = new;
    else
    {
        tmp = list->first;
        while (tmp->next != NULL)
            tmp = tmp->next;
        new->prev = tmp;
        tmp->next = new;
    }
    return (list);
}

t_list      *add_begin_list(t_list *list, void *elem)
{
    t_elem  *new;
    t_elem  *tmp;

    if (!(new = malloc(sizeof(t_elem))))
        return (NULL);
    list->nbr_elem += 1;
    new->index = 0;
    tmp = list->first;
    new->elem = elem;
    new->next = tmp;
    new->prev = NULL;
    tmp->prev = new;
    list->first = new;
    while (tmp != NULL)
    {
        tmp->index += 1;
        tmp = tmp->next;
    }
    return (list);
}

t_elem      *return_elem_n(t_list *list, int index)
{
    t_elem  *tmp;

    tmp = list->first;
    while (tmp->index != index)
        tmp = tmp->next;
    return (tmp);
}

t_list      *erase_elem_n(t_list *list, int index)
{
    t_elem  *tmp;
    t_elem  *tmp1;

    tmp = list->first;
    while (tmp->index != index)
        tmp = tmp->next;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    tmp1 = tmp->next;
    free(tmp);
    while (tmp1 != NULL)
    {
        tmp1->index -= 1;
        tmp = tmp->next;
    }
    return (list);
}

void        delete_list(t_list *list)
{
    t_elem  *tmp;

    tmp = list->first;
    while (tmp->next != NULL)
    {
        free(tmp->elem);
        tmp = tmp->next;
        free(tmp->prev);
    }
    free(tmp);
    free(list);
}
