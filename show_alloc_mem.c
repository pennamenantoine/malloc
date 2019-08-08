/*
** show_alloc_mem.c for show in /home/pennam_a/Systeme_unix/PSU_2015_malloc
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Thu Feb 11 19:04:50 2016 antoine pennamen
** Last update Sun Feb 14 21:52:49 2016 antoine pennamen
*/

#include <stdio.h>
#include "malloc.h"

t_malloc	*g_container;

void		show_alloc_mem()
{
  t_malloc	*tmp;

  tmp = g_container;
  printf("break : %p\n", sbrk(0));
  while (tmp != NULL)
    {
      if (tmp->free == 1)
	printf("%p - %p : %lu bytes\n", tmp + 1,
	       (void *)tmp + SIZE_STRUCT + tmp->_size, tmp->_size);
	tmp = tmp->next;
    }
}
