/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ring_buffer_manage.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 16:21:56 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/18 17:38:35 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

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
	if (rb.buffer)
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
