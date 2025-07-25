/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_init_pushboundries copy.c           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/25 15:55:50 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns ops
static int	stx_push_boundry(t_stacks *stx, t_sts_bounds sts_bnds, t_sts best_sts)
{
	t_sts	best_sts;

	best_sts = push_boundry_init_best_sts(stx, sts_bnds);
	best_sts = push_boundry_find_best(stx, sts_bnds, best_sts);
}

t_sts	push_boundry_init_best_sts(t_stacks *stx, t_sts_bounds sts_bnds)
{
	t_sts	best_sts;

	best_sts.index = -1;
	best_sts.ops_a_pos = stx->rb_a.count + 1;
	best_sts.ops_a_neg = -stx->rb_a.count + 1;
	best_sts.ops_b_pos = stx->rb_b.count + 1;
	best_sts.ops_b_neg = -stx->rb_b.count + 1;
	return (best_sts);
}

static t_sts	test_against_pos_neg(t_sts sts, char stack, t_sts best_sts);

t_sts	push_boundry_find_best(t_stacks *stx, t_sts_bounds sts_bnds, t_sts best_sts)
{
	if (sts_bnds.rba_low.index != -1)
		best_sts = test_against_pos_neg(sts_bnds.rba_low, 'A', best_sts);
	if (sts_bnds.rba_high.index != -1)
		best_sts = test_against_pos_neg(sts_bnds.rba_high, 'A', best_sts);
	if (sts_bnds.rbb_low.index != -1)
		best_sts = test_against_pos_neg(sts_bnds.rbb_low, 'B', best_sts);
	if (sts_bnds.rbb_high.index != -1)
		best_sts = test_against_pos_neg(sts_bnds.rbb_high, 'B', best_sts);
	return (best_sts);
}

static t_sts	test_against_pos_neg(t_sts sts, char stack, t_sts best_sts)
{
	if (stack == 'A')
	{
		if (sts.ops_a_pos < best_sts.ops_a_pos)
			best_sts.ops_a_pos = sts.ops_a_pos;
		if (sts.ops_a_neg > best_sts.ops_a_neg)
			best_sts.ops_a_neg = sts.ops_a_neg;
		return (best_sts);
	}
	if (sts.ops_b_pos < best_sts.ops_b_pos)
		best_sts.ops_b_pos = sts.ops_b_pos;
	if (sts.ops_b_neg > best_sts.ops_b_neg)
		best_sts.ops_b_neg = sts.ops_b_neg;
	return (best_sts);
}
