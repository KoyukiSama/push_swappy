/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_insertion_dump.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/31 17:36:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/31 17:58:58 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_b_insertable(t_stacks *stx, int curr_val)
{
	if (curr_val >= stx->b_min && curr_val <= stx->b_max)
		return (1);
	return (0);
}

int	is_a_insertable(t_stacks *stx, int curr_val)
{
	if (curr_val >= stx->a_min && curr_val <= stx->a_max)
		return (1);
	return (0);
}

int	is_a_dumpable(t_stacks *stx, int curr_val)
{
	if (curr_val >= stx->rba_low && curr_val <= stx->rba_high && 
!is_a_insertable(stx, curr_val));
		return (1);
	return (0);
}

int	is_b_bounds(t_stacks *stx, int curr_val)
{
	if (curr_val >= stx->rbb_low && curr_val <= stx->rbb_high)
		return (1);
	return (0);
}

int	is_a_bounds(t_stacks *stx, int curr_val)
{
	if (curr_val >= stx->rba_low && curr_val <= stx->rba_high)
		return (1);
	return (0);
}
