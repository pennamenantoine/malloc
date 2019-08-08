/*
** calloc.c for calloc in /home/pennam_a/Systeme_unix/PSU_2015_malloc
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Sat Feb 13 13:16:39 2016 antoine pennamen
** Last update Sun Feb 14 21:50:29 2016 antoine pennamen
*/

#include "malloc.h"

t_malloc	*g_container;

void		*calloc(size_t nmemb, size_t size)
{
  void		*ptr;

  if ((ptr = malloc(nmemb * size)) == NULL)
    return (NULL);
  memset(ptr, 0, size * nmemb);
  if (nmemb == 0 || size == 0)
    return (NULL);
  return (ptr);
}
