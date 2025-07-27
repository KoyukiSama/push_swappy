/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ring_buffer_manage2.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:42:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/27 15:40:30 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include <stddef.h>

size_t	rb_top_index(t_ringbuff rb)
{
	return (rb.count - 1);
}

int		rb_get_top(t_ringbuff rb)
{
	return (rb_get(rb, rb_top_index));
}

// returns rb_count + 1 if mistake happened.
size_t	rb_get_index(t_ringbuff rb, int val)
{
	size_t	i;
	int		curr_val;

	i = 0;
	while (i < rb.count)
	{
		curr_val = rb_get(rb, i);
		if (curr_val == val)
			return (i);
	}
	return (rb.count + 1);
}
