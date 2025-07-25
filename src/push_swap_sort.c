/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/25 13:59:31 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stx_init_stacks(t_stacks *stx);
static void	stx_ops_index(t_stacks *stx, size_t index, char stack);

#include <stdio.h>
// returns total nbr of stx
void	stx_sort(t_stacks *stx)
{
	int	tot_ops;

printf("rba_low: %i, rba_high: %i, rbb_low: %i, rbb_high: %i\n", stx->rba_low, stx->rba_high, stx->rbb_low, stx->rbb_high);
printf("index: %li, val: %i\n", stx->sts.index, stx->sts.val);
printf("a_pos: %li , a_neg: %li\nb_pos: %li, b_neg: %li\n", stx->sts.ops_a_pos, stx->sts.ops_a_neg\
, stx->sts.ops_b_pos, stx->sts.ops_b_neg);
}

static void	stx_init_stacks(t_stacks *stx)
{
	
}

// gets ops from index
static void	stx_ops_index(t_stacks *stx, size_t index, char stack)
{
	stx->sts.index = index;
	if (stack == 'A')
	{
		stx->sts.index = rb_get(stx->rb_a, index);
		stx_ops_push_from(stx, 'A');
		stx_ops_push_to(stx, 'B');
		return ;
	}
	stx->sts.index = rb_get(stx->rb_b, index);
	stx_ops_push_from(stx, 'B');
	stx_ops_push_to(stx, 'A');
}
