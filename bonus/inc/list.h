/*
** list.h for list in /home/antiaskid/Documents/B1/tmp/lib/lib-Util/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Dec 21 16:05:30 2016 John Doe
** Last update Tue Jan 24 23:36:03 2017 Antoine Briaux
*/

#ifndef __LIST_H__
# define __LIST_H__

typedef struct      s_elem
{
    int             index;
    void            *elem;
    struct s_elem   *next;
    struct s_elem   *prev;
}                   t_elem;

typedef struct      s_list
{
    int             nbr_elem;
    t_elem          *first;
}                   t_list;

t_list *add_end_list(t_list *, void *);
t_list *add_begin_list(t_list *, void *);
t_elem *return_elem_n(t_list *, int);
t_list *erase_elem_n(t_list *, int);
void   delete_list(t_list *);

#endif /*!__LIST_H__*/
