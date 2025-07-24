/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/24 15:35:58 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
// returns total nbr of stx
void	stx_sort(t_stacks *stx)
{
	//int	tot_ops;

	stx->sts_a.index = 4;
	stx->sts_a.val = rb_get(stx->rb_a, stx->sts_a.index);
	stx_ops_push_from(stx, 'A');
	stx_ops_push_to(stx, 'B');
	printf("index: %li, val: %i\n", stx->sts_a.index, stx->sts_a.val);
	printf("a_pos: %li , a_neg: %li\nb_pos: %li, b_neg: %li\n", stx->sts_a.ops_a_pos, stx->sts_a.ops_a_neg\
	, stx->sts_a.ops_b_pos, stx->sts_a.ops_b_neg);
}

