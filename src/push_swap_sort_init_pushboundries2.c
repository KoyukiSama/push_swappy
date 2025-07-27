/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_init_pushboundries2.c               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/27 14:47:17 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stx_push_boundry(t_stacks *stx, t_sts_bounds sts_bnds);

// returns best bounds
t_best	stx_find_best_bounds(t_stacks *stx, t_sts_bounds sts_bnds)
{
	t_best	best;

	return (stx_find_curr_best(stx, sts_bnds));
}

// if push_from == 0, then no best has been found
static t_best	stx_find_curr_best(t_stacks *stx, t_sts_bounds sts_bnds)
{
	t_best	temp_best;
	t_best	best;

	best.push_from = 0;
	temp_best.ops_total = 9999999999999999;
	best.ops_total = 9999999999999999;
	if (sts_bnds.rba_low.index != -1)
		temp_best = stx_ops_best(sts_bnds.rba_low, 'B');
	if (temp_best.ops_total < best.ops_total)
		best = temp_best;
	if (sts_bnds.rba_high.index != -1 )
		temp_best = stx_ops_best(sts_bnds.rba_high, 'B');
	if (temp_best.ops_total < best.ops_total)
		best = temp_best;
	if (sts_bnds.rbb_low.index != -1)
		temp_best = stx_ops_best(sts_bnds.rbb_low, 'A');
	if (temp_best.ops_total < best.ops_total)
		best = temp_best;
	if (sts_bnds.rbb_high.index != -1 )
		temp_best = stx_ops_best(sts_bnds.rbb_high, 'A');
	if (temp_best.ops_total < best.ops_total)
		best = temp_best;
	return (best);
}
