/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ring_buffer.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 16:57:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/13 18:09:52 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RING_BUFFER_H
# define RING_BUFFER_H

# include <stddef.h>

/**
 * when rb is empty, top and bottom are size_max
 * when 
 * 
 * @param top is always full, top of stack
 * @param bot is always full, it's the bottom of the stack
 * @param size is always power of 2
 * @param mask is size - 1
 * @param buffer is allocated on heap
 */
typedef struct s_ringbuff
{
	size_t	top;
	size_t	bot;
	size_t	size;
	size_t	mask;
	int 	*buffer;
}	t_ringbuff;

t_ringbuff	rb_init(size_t memsize);
void		rb_destroy(t_ringbuff rb);
int			rb_isempty(t_ringbuff rb);
int			rb_isone(t_ringbuff rb);
size_t		rb_lasti(t_ringbuff rb);

// modify
void		rb_set(t_ringbuff *rb, size_t index, int nbr);
int			rb_get(t_ringbuff rb, size_t index);
void		rb_addtop(t_ringbuff *rb, int nbr);
void		rb_remtop(t_ringbuff *rb);
void		rb_addbot(t_ringbuff *rb, int nbr);
void		rb_rembot(t_ringbuff *rb);


#endif