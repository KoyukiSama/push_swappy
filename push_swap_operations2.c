/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_operations2.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:27:30 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/13 18:11:12 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include "push_swap.h"

int stx_rra(t_stacks *stx)
{
	t_ringbuff	*rb_a;

	rb_a = &(stx->rb_a);
	if (rb_isempty(*rb_a) || rb_isone(*rb_a))
		return (0);
	rb_addtop(rb_a, rb_get(*rb_a, 0));
	rb_rembot(rb_a);
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
	return (1);
}

int stx_rrr(t_stacks *stx)
{
	int	pass;

	pass = 1;
	if (!rb_rra(stx))
		pass = 0;
	if (!rb_rrb(stx))
		pass = 0;
	return (pass);
}
