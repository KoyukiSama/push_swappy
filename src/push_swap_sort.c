/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/27 18:04:33 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void		stx_ops_index(t_stacks *stx, size_t index, char stack);

#include <stdio.h>
// returns total nbr of stx
void	stx_sort(t_stacks *stx)
{
	long	tot_ops;

	print_buff(*stx);
	tot_ops = 0;
	tot_ops += stx_init_push_to_b(stx);
	//ops += stx_init_push_bounds(stx);
	print_buff(*stx);
}

// gets ops from index
// static void	stx_ops_index(t_stacks *stx, size_t index, char stack)
// {
// 	stx->sts.index = index;
// 	if (stack == 'A')
// 	{
// 		stx->sts.index = rb_get(stx->rb_a, index);
// 		stx_ops_push_from(stx, 'A');
// 		stx_ops_push_to(stx, 'B');
// 		return ;
// 	}
// 	stx->sts.index = rb_get(stx->rb_b, index);
// 	stx_ops_push_from(stx, 'B');
// 	stx_ops_push_to(stx, 'A');
// }
