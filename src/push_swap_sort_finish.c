/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_finish.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/28 23:18:28 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	stx_insert(t_stacks *stx);

// returns total nbr of stx
size_t	stx_finish(t_stacks *stx)
{
	
}

static size_t	stx_bring_a_to_top(t_stacks *stx)
{
	stx->sts.index = rb_get_index(stx->rb_a, stx->rba_low);

	stx_ops_push_from(stx, 'A');
}
