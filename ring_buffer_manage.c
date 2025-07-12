/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ring_buffer_manage.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 16:21:56 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/12 18:20:33 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	ft_next_p2(size_t nbr);

t_ringbuff	rb_init(size_t memsize)
{
	t_ringbuff	rb;

	rb.size = ft_next_p2(memsize);
	rb.mask = rb.size - 1;
	rb.bot = 0;
	rb.top = 0;
	rb.buffer = malloc(rb.size * sizeof(int));
	return (rb);
}

void	rb_destroy(t_ringbuff rb)
{
	free(rb.buffer);
	return ;
}

int	rb_isempty(t_ringbuff rb)
{
	return (rb.bot == rb.top);
}

int	rb_isone(t_ringbuff rb)
{
	return (((rb.bot + 1) & rb.mask) == rb.top);
}

/**
 * Function: makes a number be the next power of two
 * Caveats:	 if nbr < 2, returns 2. this function is only used for & mask wrap
 * 
 * @param[in] nbr
 * 
 * @returns power of 2 nbr > input nbr
 */
static size_t	ft_next_p2(size_t nbr)
{
	if (nbr < 2)
		return (2);
	nbr--;
	nbr |= nbr >> 1;
	nbr |= nbr >> 2;
	nbr |= nbr >> 4;
	nbr |= nbr >> 8;
	nbr |= nbr >> 16;
	nbr |= nbr >> 32;
	return (nbr + 1);
}
