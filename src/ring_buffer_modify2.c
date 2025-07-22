/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ring_buffer_modify2.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:48:29 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/22 18:44:48 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include <stddef.h>

void	rb_addbot(t_ringbuff *rb, int nbr)
{
	rb->bot = (rb->bot - 1 + rb->size) & rb->mask;
	rb_set(rb, 0, nbr);
	rb->count++;
}

void	rb_rembot(t_ringbuff *rb)
{
	if (rb_isempty(*rb))
		return ;
	rb->bot = (rb->bot + 1) & rb->mask;
	rb->count--;
}
