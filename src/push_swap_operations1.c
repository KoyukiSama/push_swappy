/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_operations1.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:27:30 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/28 22:32:38 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include "push_swap.h"
#include "unistd.h"

int	stx_ra(t_stacks *stx)
{
	t_ringbuff	*rb_a;

	rb_a = &(stx->rb_a);
	if (rb_isempty(*rb_a) || rb_isone(*rb_a))
		return (0);
	rb_addbot(rb_a, rb_get_top(*rb_a));
	rb_remtop(rb_a);
	write(1, "ra\n", 3);
	return (1);
}

int stx_rb(t_stacks *stx)
{
	t_ringbuff	*rb_b;

	rb_b = &(stx->rb_b);
	if (rb_isempty(*rb_b) || rb_isone(*rb_b))
		return (0);
	rb_addbot(rb_b, rb_get_top(*rb_b));
	rb_remtop(rb_b);
	write(1, "rb\n", 3);
	return (1);
}

int stx_rr(t_stacks *stx)
{
	if (!stx_ra(stx))
		return (0);
	if (!stx_rb(stx))
		return (stx_ra(stx), 0);
	write(1, "rr\n", 3);
	return (1);
}
