/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_init_pushboundries.c                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/25 17:40:35 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			stx_push_boundry(t_stacks *stx, t_sts_bounds sts_bnds);
static t_sts_bounds	get_sts_bounds(t_stacks *stx, t_sts_bounds sts_bnds);
static t_sts_bounds	sts_bounds_init(void);

// returns ops
int	stx_init_push_boundries(t_stacks *stx)
{
	size_t			tot_ops;
	t_sts_bounds	sts_bnds;

	tot_ops = 0;
	while (tot_ops = 0 || 
(sts_bnds.rba_high.index == -1 && sts_bnds.rba_low.index == -1 && 
sts_bnds.rbb_high.index == -1 && sts_bnds.rbb_low.index == -1))
	{
		sts_bnds = sts_bounds_init();
		sts_bnds = get_sts_bounds(stx, sts_bnds);
		
	}
}


// TODO, you made your own functions for this
// returns ops
static int	stx_push_boundry(t_stacks *stx, t_sts_bounds sts_bnds, t_sts best_sts)
{
	t_sts	best_sts;

	best_sts.index = -1;
	best_sts.ops_a_pos = stx->rb_a.count + 1;
	best_sts.ops_a_neg = -stx->rb_a.count + 1;
	best_sts.ops_b_pos = stx->rb_b.count + 1;
	best_sts.ops_b_neg = -stx->rb_b.count + 1;
	if (sts_bnds.rba_low.ops_a_pos < best_sts.ops_a_pos && sts_bnds.rba_low.index != -1)
		best_sts.ops_a_pos = sts_bnds.rba_low.ops_a_pos;
	if (sts_bnds.rba_low.ops_a_pos < best_sts.ops_a_pos && sts_bnds.rba_low.index != -1)
		best_sts.ops_a_pos = sts_bnds.rba_low.ops_a_pos;
	if (sts_bnds.rba_low.ops_a_pos < best_sts.ops_a_pos && sts_bnds.rba_low.index != -1)
		best_sts.ops_a_pos = sts_bnds.rba_low.ops_a_pos;
	if (sts_bnds.rba_low.ops_a_pos < best_sts.ops_a_pos && sts_bnds.rba_low.index != -1)
		best_sts.ops_a_pos = sts_bnds.rba_low.ops_a_pos;
	if (sts_bnds.rba_low.ops_a_pos < best_sts.ops_a_pos && sts_bnds.rba_low.index != -1)
		best_sts.ops_a_pos = sts_bnds.rba_low.ops_a_pos;
	if (sts_bnds.rba_low.ops_a_pos < best_sts.ops_a_pos && sts_bnds.rba_low.index != -1)
		best_sts.ops_a_pos = sts_bnds.rba_low.ops_a_pos;
	if (sts_bnds.rba_low.ops_a_pos < best_sts.ops_a_pos && sts_bnds.rba_low.index != -1)
		best_sts.ops_a_pos = sts_bnds.rba_low.ops_a_pos;
	if (sts_bnds.rba_low.ops_a_pos < best_sts.ops_a_pos && sts_bnds.rba_low.index != -1)
		best_sts.ops_a_pos = sts_bnds.rba_low.ops_a_pos;
}

static t_sts	stx_ops_index(t_stacks *stx, size_t index, char stack);

static t_sts_bounds	get_sts_bounds(t_stacks *stx, t_sts_bounds sts_bnds)
{
	size_t			i;
	size_t			count;
	int				curr_nbr_a;
	int				curr_nbr_b;

	i = 0;
	count = stx->rb_a.count + 1;
	while (i < count)
	{
		curr_nbr_a = rb_get(stx->rb_a, i);
		curr_nbr_b = rb_get(stx->rb_a, i);
		if (curr_nbr_a == stx->rbb_low)
			sts_bnds.rbb_low = stx_ops_index(stx, i, 'A');
		else if (curr_nbr_a == stx->rbb_high)
			sts_bnds.rbb_high = stx_ops_index(stx, i, 'A');
		else if (curr_nbr_b == stx->rba_low)
			sts_bnds.rba_high = stx_ops_index(stx, i, 'B');
		else if (curr_nbr_b == stx->rba_high)
			sts_bnds.rba_high = stx_ops_index(stx, i, 'B');
		i++;
	}
	return (sts_bnds);
}

static t_sts	stx_ops_index(t_stacks *stx, size_t index, char stack)
{
	stx->sts.index = index;
	if (stack == 'A')
	{
		stx->sts.index = rb_get(stx->rb_a, index);
		stx_ops_push_from(stx, 'A');
		return (stx->sts);
	}
	stx->sts.index = rb_get(stx->rb_b, index);
	stx_ops_push_from(stx, 'B');
	return (stx->sts);
}

static	t_sts_bounds	sts_bounds_init(void)
{
	t_sts_bounds	sts_bnds;

	sts_bnds.rba_high.index = -1;
	sts_bnds.rbb_high.index = -1;
	sts_bnds.rba_low.index = -1;
	sts_bnds.rbb_low.index = -1;
}