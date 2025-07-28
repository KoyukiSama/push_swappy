/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_operations2.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:27:30 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/28 22:32:41 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include "push_swap.h"
#include "unistd.h"

int stx_rra(t_stacks *stx)
{
	t_ringbuff	*rb_a;

	rb_a = &(stx->rb_a);
	if (rb_isempty(*rb_a) || rb_isone(*rb_a))
		return (0);
	rb_addtop(rb_a, rb_get(*rb_a, 0));
	rb_rembot(rb_a);
	write(1, "rra\n", 4);
	return (1);
}

int stx_rrb(t_stacks *stx)
{
	t_ringbuff	*rb_b;

	rb_b = &(stx->rb_b);
	if (rb_isempty(*rb_b) || rb_isone(*rb_b))
		return (0);
	rb_addtop(rb_b, rb_get(*rb_b, 0));
	rb_rembot(rb_b);
	write(1, "rrb\n", 4);
	return (1);
}

int stx_rrr(t_stacks *stx)
{
	if (!stx_rra(stx))
		return (0);
	if (!stx_rrb(stx))
		return (stx_rra(stx), 0);
	write(1, "rrr\n", 4);
	return (1);
}
