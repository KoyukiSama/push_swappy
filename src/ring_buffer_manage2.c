/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ring_buffer_manage2.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:42:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/25 14:07:12 by kclaes        ########   odam.nl         */
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
