/*
** free.c for free in /home/pennam_a/Systeme_unix/PSU_2015_malloc
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Fri Feb 12 01:15:05 2016 antoine pennamen
** Last update Sun Feb 14 21:45:58 2016 antoine pennamen
*/

#include "malloc.h"

t_malloc	*g_container;

void		free(void *ptr)
{
  t_malloc	*tmp;

  tmp = g_container;
  while (tmp != NULL)
    {
      if ((tmp + 1) == ptr)
	{
	  tmp->free = 0;
	  return ;
	}
      tmp = tmp->next;
    }
}
