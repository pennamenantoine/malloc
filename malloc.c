/*
** malloc.c for malloc in /home/pennam_a/Systeme_unix/PSU_2015_malloc
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Wed Jan 27 14:35:58 2016 antoine pennamen
** Last update Sun Feb 14 22:31:01 2016 antoine pennamen
*/

#include "malloc.h"

t_malloc	*g_container;

int		check_sbrk(void *ptr, size_t size)
{
  int		check;
  int		nb;

  check = sbrk(0) - ptr;
  if ((size + SIZE_STRUCT) > (size_t)check)
    {
      nb = ((size + SIZE_STRUCT) / getpagesize()) + 1;
      if ((sbrk(getpagesize() * nb)) == ((void *) -1))
	return (-1);
    }
  return (0);
}

void		*init_list(size_t size)
{
  int		nb;

  nb = ((size + SIZE_STRUCT) / getpagesize()) + 1;
  if ((g_container = sbrk(getpagesize() * nb)) == ((void *) -1))
    return (NULL);
  g_container->_size = size;
  g_container->free = 1;
  g_container->next = NULL;
  return (g_container + 1);
}

void		*put_in_list(size_t size)
{
  t_malloc	*tmp;
  t_malloc	*elem;

  tmp = g_container;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  elem = (void *)tmp + SIZE_STRUCT + MY_PAD(tmp->_size);
  check_sbrk(elem, size);
  elem->_size = size;
  elem->free = 1;
  elem->next = NULL;
  tmp->next = elem;
  return (elem + 1);
}

void		*malloc(size_t size)
{
  void		*ptr;

  if (size == 0)
    return (NULL);
  if ((ptr = check_free(size)) != NULL)
    return (ptr);
  if (g_container == NULL)
    return (init_list(size));
  else
    return (put_in_list(size));
}

void		*check_free(size_t size)
{
  t_malloc	*tmp;

  tmp = g_container;
  while (tmp != NULL)
    {
      if (tmp->free == 0 && MY_PAD(tmp->_size) >= size)
	{
	  tmp->_size = size;
	  tmp->free = 1;
	  return (tmp + 1);
	}
      tmp = tmp->next;
    }
  return (NULL);
}
