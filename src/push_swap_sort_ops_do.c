/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_ops_do.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/29 18:20:10 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stx_do_ops_double(t_stacks *stx, t_best best);
static void	stx_do_ops_a(t_stacks *stx, t_best best);
static void	stx_do_ops_b(t_stacks *stx, t_best best);

// returns ops
size_t	stx_do_ops(t_stacks *stx, t_best best)
{
	stx_do_ops_double(stx, best);
	stx_do_ops_a(stx, best);
	stx_do_ops_b(stx, best);
	if (best.push_from == 'A')
		stx_pb(stx);
	else if (best.push_from == 'B')
		stx_pa(stx);
	else
		return (0);
	return (best.ops_total);
}

static void	stx_do_ops_double(t_stacks *stx, t_best best)
{
	while (best.rr)
	{
		stx_rr(stx);
		best.rr--;
	}
	while (best.rrr)
	{
		stx_rrr(stx);
		best.rrr--;
	}
}

static void	stx_do_ops_a(t_stacks *stx, t_best best)
{
	while (best.ra)
	{
		stx_ra(stx);
		best.ra--;
	}
	while (best.rra)
	{
		stx_rra(stx);
		best.rra--;
	}
}

static void	stx_do_ops_b(t_stacks *stx, t_best best)
{
	while (best.rb)
	{
		stx_rb(stx);
		best.rb--;
	}
	while (best.rrb)
	{
		stx_rrb(stx);
		best.rrb--;
	}
}
