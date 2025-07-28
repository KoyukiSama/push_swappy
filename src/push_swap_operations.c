/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_operations.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:27:30 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/28 22:32:34 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include "push_swap.h"
#include "unistd.h"

// push to a
int	stx_pa(t_stacks *stx)
{
	t_ringbuff	*rb_a;
	t_ringbuff	*rb_b;

	rb_a = &(stx->rb_a);
	rb_b = &(stx->rb_b);
	if (rb_isempty(*rb_b))
		return (0);
	rb_addtop(rb_a, rb_get_top(*rb_b));
	rb_remtop(rb_b);
	write(1, "pa\n", 3);
	return (1);
}

// push to b
int	stx_pb(t_stacks *stx)
{
	t_ringbuff	*rb_a;
	t_ringbuff	*rb_b;

	rb_a = &(stx->rb_a);
	rb_b = &(stx->rb_b);
	if (rb_isempty(*rb_a))
		return (0);
	rb_addtop(rb_b, rb_get_top(*rb_a));
	rb_remtop(rb_a);
	write(1, "pb\n", 3);
	return (1);
}
