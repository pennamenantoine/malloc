/*
** malloc.h for malloc in /home/pennam_a/Systeme_unix/PSU_2015_malloc
**
** Made by antoine pennamen
** Login   <pennam_a@epitech.net>
**
** Started on  Wed Jan 27 14:36:05 2016 antoine pennamen
** Last update Sun Feb 14 22:31:26 2016 antoine pennamen
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>
# include <string.h>

# define PAD		(sizeof(void *) * 2)
# define SIZE_STRUCT	(sizeof(struct s_malloc))
# define MY_PAD(size)	(size + (((PAD - (size % PAD))) % PAD))

typedef struct		s_malloc
{
  struct s_malloc	*next;
  size_t		_size;
  char			pad[8];
  int			free;
}			t_malloc;

extern t_malloc		*g_container;

void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			free(void *ptr);
void			show_alloc_mem();
void			*init_list(size_t size);
void			*put_in_list(size_t size);
int			check_sbrk(void *ptr, size_t size);
void			*check_free(size_t size);
void			*calloc(size_t nmemb, size_t size);
void			*do_while(void *ptr, size_t size, t_malloc *tmp);

#endif /* !MALLOC_H_ */
