/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/27 20:02:56 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// returns total nbr of stx
void	stx_sort(t_stacks *stx)
{
	long	tot_ops;

	print_buff(*stx);
	tot_ops = 0;
	tot_ops += stx_init_push_to_b(stx);
	tot_ops += stx_init_push_bounds(stx);


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
	char	b_val_in_a_found;
	char	a_val_in_b_found;

	ops = 0;
	b_val_in_a_found = 1;
	a_val_in_b_found = 1;
	while (b_val_in_a_found || a_val_in_b_found)
	{
		temp_best.ops_total = 999999999999999999;
		best.ops_total = 999999999999999999;
		i = 0;
		while (i < stx->rb_a.count)
		{
			stx_ops_index(stx, i, 'A');
			if (stx->sts.val >= stx->rbb_low && stx->sts.val <= stx->rbb_high)
			{
				temp_best = stx_ops_best(stx->sts, 'A');
				if (temp_best.ops_total < best.ops_total)
					best = temp_best;
			}
			else
				b_val_in_a_found = 0;
			i++;
		}
		i = 0;
		while (i < stx->rb_b.count)
		{
			stx_ops_index(stx, i, 'B');
			if (stx->sts.val >= stx->rba_low && stx->sts.val <= stx->rba_high)
			{
				temp_best = stx_ops_best(stx->sts, 'A');
				if (temp_best.ops_total < best.ops_total)
					best = temp_best;
			}
			else
				a_val_in_b_found = 0;
			i++;
		}
		if (b_val_in_a_found || a_val_in_b_found)
			ops += stx_do_ops(stx, best);
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
