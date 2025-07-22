/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/22 19:57:47 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stx_init_min_max(t_stacks *stx);

// returns total nbr of stx
int	stx_sort(t_stacks *stx)
{
	int	tot_ops;

	stx_pb(stx);
	stx_pb(stx);
	tot_ops = 2;
	stx_min_max(stx);

	stx_sort_three();
}

static void	stx_init_min_max(t_stacks *stx)
{
	if (rb_get(stx->rb_b, 0) < rb_get(stx->rb_b, stx->rb_b.count - 1))
	{
		stx->min = rb_get(stx->rb_b, 0);
		stx->max = rb_get(stx->rb_b, stx->rb_b.count - 1);
		return ;
	}
	stx->min = rb_get(stx->rb_b, 0);
	stx->max = rb_get(stx->rb_b, stx->rb_b.count - 1);
	return ;
}

static void	stx_find_short(t_stacks *stx, int *func_best_ops)
{
	int	ops;
	int	curr_top;

	*func_best_ops = 1;
	curr_top = rb_get(stx->rb_a, 2);
	ops = 3;
	
	
}
