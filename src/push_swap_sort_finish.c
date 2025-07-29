/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_finish.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/29 17:59:26 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ops_a_to_top(t_stacks *stx);
static void		ops_b_to_top(t_stacks *stx);
static size_t	push_stack_b_to_a(t_stacks *stx);

// returns total nbr of stx
size_t	stx_finish(t_stacks *stx)
{
	t_best	best;
	size_t	ops;

	ops = 0;
	ops_a_to_top(stx);
	ops_b_to_top(stx);
	best = stx_ops_best(stx->sts, 'B');
	ops += stx_do_ops(stx, best);
	ops += push_stack_b_to_a(stx);
	return (ops);
}

static void	ops_a_to_top(t_stacks *stx)
{
	stx->sts.index = rb_get_index(stx->rb_a, stx->rba_low);
	stx_ops_push_from(stx, 'A');
}

static void	ops_b_to_top(t_stacks *stx)
{
	stx->sts.index = rb_get_index(stx->rb_b, stx->rbb_high);
	stx_ops_push_from(stx, 'B');
}

static size_t	push_stack_b_to_a(t_stacks *stx)
{
	int		full;
	size_t	ops;

	full = 1;
	while (full)
	{
		full = stx_pa(stx);
		ops += full;
	}
	return (ops);
}
