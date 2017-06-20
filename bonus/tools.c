/*
** tools.c for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec 27 17:25:23 2016 John Doe
** Last update Tue Dec 27 18:40:58 2016 John Doe
*/

#include <stdlib.h>

char        *xmalloc(int size)
{
    int     i;
    char    *str;

    if (!(str = malloc(size + 1)))
        return (NULL);
    i = 0;
    while (i < size)
    {
        str[i] = '\0';
        i += 1;
    }
    return (str);
}

void    my_strcat(char *str1, char *str2)
{
    int i;
    int j;

    i = 0;
    while (str1[i] != '\0')
        i += 1;
    j = 0;
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i += 1;
        j += 1;
    }
    str1[i] = '\0';
}
