/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_rba_high.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/23 15:41:12 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_next_low_high(int *low, int *high, t_stacks *stx);
static void	find_low_high(int *low, int *high, t_stacks *stx);

void	stx_get_rba_high(t_stacks *stx)
{
	size_t	iters_half;
	size_t	i;
	int		low;
	int		high;

	find_low_high(&low, &high, stx);
	iters_half = stx->rb_a.count / 2;
	i = 0;
	while (i < iters_half)
	{
		find_next_low_high(&low, &high, stx);
		i++;
	}
	stx->rba_high = low;
}

static void	find_low_high(int *low, int *high, t_stacks *stx)
{
	size_t	i;

	*low = rb_get(stx->rb_a, 0);
	*high = rb_get(stx->rb_a, stx->rb_a.count - 1);
	i = 0;
	while (i < stx->rb_a.count)
	{
		if (*low > rb_get(stx->rb_a, i))
			*low = rb_get(stx->rb_a, i);
		if (*high < rb_get(stx->rb_a, i))
			*high = rb_get(stx->rb_a, i);
		i++;
	}
}

static void	find_next_low_high(int *low, int *high, t_stacks *stx)
{
	size_t	i;
	int		new_low;
	int		new_high;

	new_low = *high;
	new_high = *low;
	i = 0;
	while (i < stx->rb_a.count)
	{
		if (*low < rb_get(stx->rb_a, i) && new_low > rb_get(stx->rb_a, i))
			new_low = rb_get(stx->rb_a, i);
		if (*high > rb_get(stx->rb_a, i) && new_high < rb_get(stx->rb_a, i))
			new_high = rb_get(stx->rb_a, i);
		i++;
	}
	*low = new_low;
	*high = new_high;
}
