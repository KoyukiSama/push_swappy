/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/28 20:27:05 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	stx_insert(t_stacks *stx);

#include <stdio.h>
// returns total nbr of stx
void	stx_sort(t_stacks *stx)
{
	long	tot_ops;

	tot_ops = 0;
	tot_ops += stx_init_push_to_b(stx);
	tot_ops += stx_init_push_bounds(stx);
	tot_ops += stx_insert(stx);

	printf("ops: %lu", tot_ops);
	print_buff(*stx);
}

static void		stx_ops_index(t_stacks *stx, size_t index, char stack);

// inserts the nbrs from stack a into b and b into a
static size_t	stx_insert(t_stacks *stx)
{
	size_t	ops;
	t_best	temp_best;
	t_best	best;
	size_t	i;
	char	found;

	found = 1;
	ops = 0;
	while (found)
	{
		found = 0;
		temp_best.ops_total = 999999999999999999;
		best.ops_total = 999999999999999999;
		i = 0;
		while (i < stx->rb_a.count)
		{
			stx_ops_index(stx, i, 'A');
			//printf("val: %i\n", stx->sts.val);
			//printf("ops_a_pos: %li, ops_a_neg: %li\n", stx->sts.ops_a_pos, stx->sts.ops_a_neg);
			if (stx->sts.val >= stx->rbb_low && stx->sts.val <= stx->rbb_high)
			{
				temp_best = stx_ops_best(stx->sts, 'A');
				if (temp_best.ops_total < best.ops_total)
					best = temp_best;
				found = 1;
			}
			i++;
		}
		i = 0;
		while (i < stx->rb_b.count)
		{
			stx_ops_index(stx, i, 'B');
			if (stx->sts.val >= stx->rba_low && stx->sts.val <= stx->rba_high)
			{
				temp_best = stx_ops_best(stx->sts, 'B');
				if (temp_best.ops_total < best.ops_total)
					best = temp_best;
				found = 1;
			}
			i++;
		}
		if (found)
			ops += stx_do_ops(stx, best);
		print_buff(*stx);
	}
	return (ops);
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
