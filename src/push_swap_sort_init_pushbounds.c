/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_init_pushbounds.c                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/27 17:41:15 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ring_buffer.h"
#include "libft.h"

static size_t	push_stack_a_rbb_val(t_stacks *stx, int rbb_val);
static size_t	push_stack_b_rba_val(t_stacks *stx, int rba_val);

// returns ops
size_t	stx_push_bounds(t_stacks *stx)
{
	push_stack_a_rbb_val(stx, stx->rba_low);
	push_stack_a_rbb_val(stx, stx->rba_high);
	push_stack_b_rba_val(stx, stx->rbb_high);
	push_stack_b_rba_val(stx, stx->rbb_low);
}

// push from stack A, b_low or b_high
static size_t	push_stack_a_rbb_val(t_stacks *stx, int rbb_val)
{
	size_t	ops;

	ops = 0;
	stx->sts.index = rb_get_index(stx->rb_a, rbb_val);
	stx_ops_push_from(stx, 'A');
	if (ft_abs(stx->sts.ops_a_pos) < ft_abs(stx->sts.ops_a_neg))
	{
		while (stx->sts.ops_a_pos--)
			ops += stx_ra(stx);
	}
	else
	{
		while (stx->sts.ops_a_neg++)
			ops += stx_rra(stx);
	}
	ops += stx_pb(stx);
	return (ops);
}

// push from stack B, a_low or a_high
static size_t	push_stack_b_rba_val(t_stacks *stx, int rba_val)
{
	size_t	ops;

	ops = 0;
	stx->sts.index = rb_get_index(stx->rb_b, rba_val);
	stx_ops_push_from(stx, 'B');
	if (ft_abs(stx->sts.ops_b_pos) < ft_abs(stx->sts.ops_b_neg))
	{
		while (stx->sts.ops_b_pos--)
			ops += stx_rb(stx);
	}
	else
	{
		while (stx->sts.ops_b_neg++)
			ops += stx_rrb(stx);
	}
	ops += stx_pa(stx);
	return (ops);
}