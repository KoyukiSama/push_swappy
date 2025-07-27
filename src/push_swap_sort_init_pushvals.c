/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_init_pushvals.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/27 18:57:08 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
// returns ops
size_t	stx_init_push_to_b(t_stacks *stx)
{
	size_t	i;
	size_t	count;
	int		curr_top;
	size_t	ops;

	i = 0;
	ops = 0;
	count = stx->rb_a.count;
	while (i < count)
	{
		curr_top = rb_get_top(stx->rb_a);
		if (curr_top >= stx->rba_low && curr_top <= stx->rba_high)
			ops += stx_pb(stx);
		else
			ops += stx_ra(stx);
		i++;
	}
	return (ops);
}
