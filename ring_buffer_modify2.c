/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ring_buffer_modify2.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:48:29 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/12 18:59:39 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include <stddef.h>

void	rb_addbot(t_ringbuff *rb, int nbr)
{
	rb->bot = (rb->bot - 1) & rb->mask;
	rb_set(rb, rb->bot, nbr);
}

void	rb_rembot(t_ringbuff *rb)
{
	if (rb_isempty(*rb))
		return ;
	rb->top = (rb->top + 1) & rb->mask;
}

