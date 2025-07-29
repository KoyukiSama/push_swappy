/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/29 20:29:24 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	stx_insert(t_stacks *stx);

// returns total nbr of stx
void	stx_sort(t_stacks *stx)
{
	long	tot_ops;
	if (stx->rb_a.count == 2)
	{
		if (rb_get(stx->rb_a, 0) < rb_get(stx->rb_a, 1))
			stx_ra(stx);
		return ;
	}
	if (stx->rb_a.count == 3)
	{
		stx_sort_3(stx);
		return ;
	}
	tot_ops = 0;
	tot_ops += stx_init_push_to_b(stx);
	tot_ops += stx_init_push_bounds(stx);
	tot_ops += stx_insert(stx);
	tot_ops += stx_finish(stx);
	return ;
}

static void		stx_ops_index(t_stacks *stx, size_t index, char stack);
static t_best	stx_best_ops_a(t_stacks *stx, t_best best, int *found);
static t_best	stx_best_ops_b(t_stacks *stx, t_best best, int *found);

//inserts the nbrs from stack a into b and b into a
static size_t	stx_insert(t_stacks *stx)
{
	size_t	ops;
	t_best	best;
	int		found;

	found = 1;
	ops = 0;
	while (found)
	{
		found = 0;
		best.ops_total = 999999999999999999;
		best = stx_best_ops_a(stx, best, &found);
		best = stx_best_ops_b(stx, best, &found);
		if (found)
			ops += stx_do_ops(stx, best);
	}
	return (ops);
}

//get best ops stack a
static t_best	stx_best_ops_a(t_stacks *stx, t_best best, int *found)
{
	t_best	temp_best;
	size_t	i;
	
	i = 0;
	while (i < stx->rb_a.count)
	{
		stx_ops_index(stx, i, 'A');
		if (stx->sts.val >= stx->rbb_low && stx->sts.val <= stx->rbb_high)
		{
			temp_best = stx_ops_best(stx->sts, 'A');
			if (temp_best.ops_total < best.ops_total)
				best = temp_best;
			*found = 1;
		}
		i++;
	}
	return (best);
}

static t_best	stx_best_ops_b(t_stacks *stx, t_best best, int *found)
{
	t_best	temp_best;
	size_t	i;

	i = 0;
	while (i < stx->rb_b.count)
	{
		stx_ops_index(stx, i, 'B');
		if (stx->sts.val >= stx->rba_low && stx->sts.val <= stx->rba_high)
		{
			temp_best = stx_ops_best(stx->sts, 'B');
			if (temp_best.ops_total < best.ops_total)
				best = temp_best;
			*found = 1;
		}
		i++;
	}
	return (best);
}

//gets ops from index
static void	stx_ops_index(t_stacks *stx, size_t index, char stack)
{
	stx->sts.index = index;
	if (stack == 'A')
	{
		stx->sts.val = rb_get(stx->rb_a, index);
		stx_ops_push_from(stx, 'A');
		stx_ops_push_to(stx, 'B');
		return ;
	}
	stx->sts.val = rb_get(stx->rb_b, index);
	stx_ops_push_from(stx, 'B');
	stx_ops_push_to(stx, 'A');
}
