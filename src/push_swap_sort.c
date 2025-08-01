/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/08/02 01:57:40 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stx_insert(t_stacks *stx);

// returns total nbr of stx
void	stx_sort(t_stacks *stx)
{
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
	stx_init_push_to_b(stx);
	stx_insert(stx);
	//tot_ops += stx_finish(stx);
	print_bounds(stx);
	print_buff(*stx);
	return ;
}

static void		stx_ops_index(t_stacks *stx, size_t index, char stack);
static t_best	stx_best_ops_a(t_stacks *stx, t_best best, int *found);
static t_best	stx_best_ops_b(t_stacks *stx, t_best best, int *found);

//inserts the nbrs from stack a into b and b into a
static void	stx_insert(t_stacks *stx)
{
	t_best	best;
	int		found;

	found = 0;
	while (found = 1)
	{
		found = 0;
		best.ops_total = BEST_OPS_LIMIT;
		best = stx_best_a_dump(stx, best, &found);
		best = stx_best_ops_a(stx, best, &found);
		best = stx_best_ops_b(stx, best, &found);
		// best = stx_mini_sort();
		if (found)
			stx_do_ops(stx, best);
	}
}

// get best a insertion
static t_best	stx_best_a_insertion(t_stacks *stx, t_best best, int *found)
{
	t_best	temp_best;
	size_t	i;
	
	i = 0;
	while (i < stx->rb_a.count)
	{
		if (is_a_insertable(stx, rb_get(stx->rb_a, i)))
		{
			stx_ops_index(stx, i, 'A');
			temp_best = stx_ops_best(stx->sts, 'A');
			if (temp_best.ops_total < best.ops_total)
			{
				best = temp_best;
			}
			*found = 1;
		}
		i++;
	}
	return (best);
}

// get best b insertion
static t_best	stx_best_b_insertion(t_stacks *stx, t_best best, int *found)
{
	t_best	temp_best;
	size_t	i;

	i = 0;
	while (i < stx->rb_b.count)
	{
		if (is_b_insertable(stx, rb_get(stx->rb_b, i)))
		{
			stx_ops_index(stx, i, 'B');
			temp_best = stx_ops_best(stx->sts, 'B');
			if (temp_best.ops_total < best.ops_total)
			{
				best = temp_best;
			}
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
