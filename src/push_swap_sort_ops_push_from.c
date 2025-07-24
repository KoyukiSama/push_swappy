/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_ops_push_from.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/24 20:11:31 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stx_ops_push_from(t_stacks *stx, char stack)
{
	if (stack == 'A')
	{
		stx->sts.ops_a_pos = rb_top_index(stx->rb_a) - stx->sts.index;
		if (stx->sts.ops_a_pos == 0)
			stx->sts.ops_a_neg = 0;
		else
			stx->sts.ops_a_neg = -stx->sts.index - 1;
		return ;
	}
	stx->sts.ops_b_pos = rb_top_index(stx->rb_b) - stx->sts.index;
	if (stx->sts.ops_b_pos == 0)
		stx->sts.ops_b_neg = 0;
	else
		stx->sts.ops_b_neg = -stx->sts.index - 1;
}
