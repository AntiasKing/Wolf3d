/*
** framebuffer.h for wolf3d in /home/antiaskid/Documents/B1/BMUL/wolf3d/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Dec 28 17:35:36 2016 John Doe
** Last update Tue Jan 24 23:30:59 2017 Antoine Briaux
*/

#ifndef __FRAMEBUFFER__
# define __FRAMEBUFFER__

# include <SFML/Graphics.h>

typedef struct      s_my_framebuffer
{
    sfUint8         *pixels;
    int             width;
    int             height;
}                   t_my_framebuffer;

#endif  /*!__FRAMEBUFFER__*/
