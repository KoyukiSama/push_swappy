/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort3.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/29 20:10:57 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/29 20:30:27 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

void	stx_sort_3(t_stacks *stx)
{
	if (rb_get(stx->rb_a, 0) < rb_get(stx->rb_a, 1) && 
rb_get(stx->rb_a, 1) < rb_get(stx->rb_a, 2))
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
	}
	else if (rb_get(stx->rb_a, 0) < rb_get(stx->rb_a, 1) && 
rb_get(stx->rb_a, 1) > rb_get(stx->rb_a, 2))
	{
		write(1, "rra\n", 4);
	}
	else if (rb_get(stx->rb_a, 0) > rb_get(stx->rb_a, 1) && 
rb_get(stx->rb_a, 1) < rb_get(stx->rb_a, 2))
	{
		write(1, "ra\n", 3);
	}
	exit_clean(0, stx);
}