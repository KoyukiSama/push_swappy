/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_ops_push_to.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/24 22:14:23 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_above_below_index_a(int *highest, int *lowest, t_stacks *stx);
static void	find_above_below_index_b(int *highest, int *lowest, t_stacks *stx);

void	stx_ops_push_to(t_stacks *stx, char stack)
{
	int	lowest;
	int	highest;

	if (stack == 'B')
	{
		find_above_below_index_b(&highest, &lowest, stx);
		stx->sts.ops_b_neg = -highest;
		stx->sts.ops_b_pos = rb_top_index(stx->rb_b) - lowest;
		return ;
	}
	find_above_below_index_a(&highest, &lowest, stx);
	stx->sts.ops_a_neg = -highest;
	stx->sts.ops_a_pos = rb_top_index(stx->rb_a) - lowest;
}

static void	find_index_of_nbr(int *highest, int *lowest, t_stacks *stx, char stack);

static void	find_above_below_index_a(int *highest, int *lowest, t_stacks *stx)
{
	size_t	i;
	int		curr_nbr;
	int		temp;

	*lowest = stx->rba_low;
	*highest = stx->rba_high;
	i = 0;
	while (i < stx->rb_a.count)
	{
		curr_nbr = rb_get(stx->rb_a, i);
		if (curr_nbr >= *lowest && curr_nbr < stx->sts.val)
			*lowest = curr_nbr;
		if (curr_nbr <= *highest && curr_nbr > stx->sts.val)
			*highest = curr_nbr;
		i++;
	}
	find_index_of_nbr(highest, lowest, stx, 'A');
	temp = *lowest;
	*lowest = *highest;
	*highest = temp;
}

static void	find_index_of_nbr(int *highest, int *lowest, t_stacks *stx, char stack);

static void	find_above_below_index_b(int *highest, int *lowest, t_stacks *stx)
{
	size_t	i;
	int		curr_nbr;

	*lowest = stx->rbb_low;
	*highest = stx->rbb_high;
	i = 0;
	while (i < stx->rb_b.count)
	{
		curr_nbr = rb_get(stx->rb_b, i);
		if (curr_nbr >= *lowest && curr_nbr < stx->sts.val)
			*lowest = curr_nbr;
		if (curr_nbr <= *highest && curr_nbr > stx->sts.val)
			*highest = curr_nbr;
		i++;
	}
	find_index_of_nbr(highest, lowest, stx, 'B');
}

static void	find_index_of_nbr(int *highest, int *lowest, t_stacks *stx, char stack)
{
	size_t	i;

	if (stack == 'A')
	{
		i = 0;
		while (i < stx->rb_a.count)
		{
			if (rb_get(stx->rb_a, i) == *lowest)
				*lowest = i;
			if (rb_get(stx->rb_a, i) == *highest)
				*highest = i;
			i++;
		}
		return ;
	}	
	i = 0;
	while (i < stx->rb_b.count)
	{
		if (rb_get(stx->rb_b, i) == *lowest)
			*lowest = i;
		if (rb_get(stx->rb_b, i) == *highest)
			*highest = i;
		i++;
	}
}
