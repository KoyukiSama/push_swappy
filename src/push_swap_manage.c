/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 17:49:21 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/15 16:32:29 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include "push_swap.h"

t_stacks stx_init(size_t size)
{
	t_stacks	stx;
	
	stx.error = 0;
	stx.rb_a = rb_init(size);
	if (!stx.rb_a.buffer)
		return (stx.error = 1, stx);
	stx.rb_b = rb_init(size);
	if (!stx.rb_b.buffer)
		return (free(stx.rb_a), stx.error = 1, stx);
	return (stx);
}

void	stx_destroy(t_stacks *stx)
{
	rb_destroy(stx->rb_a);
	rb_destroy(stx->rb_b);
	return ;
}
