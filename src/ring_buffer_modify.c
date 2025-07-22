/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ring_buffer_modify.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:48:29 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/22 17:38:08 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include <stddef.h>

void	rb_set(t_ringbuff *rb, size_t index, int nbr)
{
	rb->buffer[(index + rb->bot) & rb->mask] = nbr;
	return ;
}

int	rb_get(t_ringbuff rb, size_t index)
{
	return (rb.buffer[(index + rb.bot) & rb.mask]);
}

void	rb_addtop(t_ringbuff *rb, int nbr)
{
	rb->buffer[rb->top] = nbr;
	rb->top = (rb->top + 1) & rb->mask;
}

void	rb_remtop(t_ringbuff *rb)
{
	if (rb_isempty(*rb))
		return ;
	rb->top = (rb->top - 1 + rb->size) & rb->mask;
}
