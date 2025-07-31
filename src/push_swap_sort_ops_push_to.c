/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_ops_push_to.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/31 15:21:51 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_above_below_index_a(int *highest, int *lowest, t_stacks *stx);
static void	find_above_below_index_b(int *highest, int *lowest, t_stacks *stx);

void	stx_ops_push_to(t_stacks *stx, char stack)
{
	int	lowest;
	int	highest;
	int	val;

	val = stx->sts.val;
	if (stack == 'B' && val >= stx->rbb_low && val <= stx->rbb_high)
	{
		find_above_below_index_b(&highest, &lowest, stx);
		stx->sts.ops_b_neg = -highest;
		stx->sts.ops_b_pos = rb_top_index(stx->rb_b) - lowest;
		return ;
	}
	if (stack == 'A' && val >= stx->rba_low && val <= stx->rba_high)
	{
		find_above_below_index_a(&highest, &lowest, stx);
		stx->sts.ops_a_neg = -highest;
		stx->sts.ops_a_pos = rb_top_index(stx->rb_a) - lowest;
		return ;
	}
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
	if (stack == 'A')
	{
		*lowest = rb_get_index(stx->rb_a, *lowest);
		*highest = rb_get_index(stx->rb_a, *highest);
		return ;
	}	
	*lowest = rb_get_index(stx->rb_b, *lowest);
	*highest = rb_get_index(stx->rb_b, *highest);
	return ;
}
