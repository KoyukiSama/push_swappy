/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/24 20:05:02 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
// returns total nbr of stx
void	stx_sort(t_stacks *stx)
{
	//int	tot_ops;

	stx->sts.index = 1;
	stx->sts.val = rb_get(stx->rb_b, stx->sts.index);
printf("rba_low: %i, rba_high: %i, rbb_low: %i, rbb_high: %i\n", stx->rba_low, stx->rba_high, stx->rbb_low, stx->rbb_high);
	stx_ops_push_from(stx, 'B');
	stx_ops_push_to(stx, 'A');
printf("index: %li, val: %i\n", stx->sts.index, stx->sts.val);
printf("a_pos: %li , a_neg: %li\nb_pos: %li, b_neg: %li\n", stx->sts.ops_a_pos, stx->sts.ops_a_neg\
, stx->sts.ops_b_pos, stx->sts.ops_b_neg);
}

