/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/24 13:08:53 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// returns total nbr of stx
void	stx_sort(t_stacks *stx)
{
	//int	tot_ops;

	stx_get_rba_high(stx);

}

void	stx_ops_push_from(t_stacks *stx, char stack)
{
	if (stack == 'A')
	{
		stx->sts_a.ops_a_pos = rb_top_index(stx->rb_a) - stx->sts_a.index;
		stx->sts_a.ops_a_neg = -stx->sts_a.index - 1;
		return ;
	}
	stx->sts_b.ops_b_pos = rb_top_index(stx->rb_b) - stx->sts_b.index;
	stx->sts_b.ops_b_neg = -stx->sts_b.index - 1;
}
