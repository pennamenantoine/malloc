/*
** realloc.c for realloc in /home/pennam_a/Systeme_unix/PSU_2015_malloc
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Fri Feb 12 01:45:49 2016 antoine pennamen
** Last update Sun Feb 14 21:50:58 2016 antoine pennamen
*/

#include "malloc.h"

t_malloc	*g_container;

void		*realloc(void *ptr, size_t size)
{
  t_malloc	*tmp;

  tmp = g_container;
  if (ptr != NULL && size == 0)
    {
      free(ptr);
      return (NULL);
    }
  if (ptr == NULL)
    return (malloc(size));
  return (do_while(ptr, size, tmp));
}

void		*do_while(void *ptr, size_t size, t_malloc *tmp)
{
  void		*tmp2;

  while (tmp != NULL)
    {
      if (tmp + 1 == ptr)
	{
	  if (size > tmp->_size)
	    {
	      if ((tmp2 = malloc(size)) == NULL)
		return (NULL);
	      memcpy(tmp2, ptr, size);
	      free(ptr);
	      return (tmp2);
	    }
	  tmp->_size = size;
	  return (tmp);
	}
      tmp = tmp->next;
    }
  return (NULL);
}
