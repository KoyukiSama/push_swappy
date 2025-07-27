/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_init_pushboundries.c                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/27 14:52:05 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sts_bounds	get_sts_bounds(t_stacks *stx, t_sts_bounds sts_bnds);
static t_sts_bounds	sts_bounds_init(void);

// returns ops
int	stx_init_push_boundries(t_stacks *stx)
{
	size_t			tot_ops;
	t_sts_bounds	sts_bnds;

	tot_ops = 0;
	while (tot_ops == 0 || 
(sts_bnds.rba_high.index != -1 && sts_bnds.rba_low.index != -1 && 
sts_bnds.rbb_high.index != -1 && sts_bnds.rbb_low.index != -1))
	{
		sts_bnds = sts_bounds_init();
		sts_bnds = get_sts_bounds(stx, sts_bnds);
		tot_ops += stx_push_boundry(stx, sts_bnds);
	}
}

// if push_from = 0, then no best has been found
static int	stx_push_boundry(t_stacks *stx, t_sts_bounds sts_bnds)
{
	t_best	best;
	
	best = stx_find_best_bounds(stx, sts_bnds);
	return (stx_do_ops(stx, best));
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
		curr_nbr_b = rb_get(stx->rb_b, i);
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
		stx->sts.val = rb_get(stx->rb_a, index);
		stx_ops_push_from(stx, 'A');
		return (stx->sts);
	}
	stx->sts.val = rb_get(stx->rb_b, index);
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