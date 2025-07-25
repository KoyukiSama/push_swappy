/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_ops_lowest.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/25 17:50:54 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_best	best_sts_init(t_best best_sts, t_sts sts);
static t_best	calc_best(t_best best_sts);

// calculates best stx operations
t_best	stx_push_boundry(t_sts sts)
{
	t_best	best_sts;

	best_sts = best_sts_init(best_sts, sts);
	best_sts = calc_best(best_sts);
	return (best_sts);
}

// TODO
static t_best	calc_best(t_best best_sts)
{
	if (best_sts.ops_a >= 0 && best_sts.ops_b >= 0 && best_sts.ops_a < best_sts.ops_b)
	{
		best_sts.rr = best_sts.ops_a;
		best_sts.ra = 0;
		best_sts.rb = best_sts.ops_b - best_sts.ops_a;
	}
	else if (best_sts.ops_a >= 0 && best_sts.ops_b >= 0 && best_sts.ops_a > best_sts.ops_b)
	{
		best_sts.rr = best_sts.ops_b;
		best_sts.ra = best_sts.ops_a - best_sts.ops_b;
		best_sts.rb = 0;
	}
	else if (best_sts.ops_a < 0 && best_sts.ops_b < 0 && best_sts.ops_a > best_sts.ops_b)
	{
		best_sts.rr = -best_sts.ops_a;
		best_sts.ra = 0;
		best_sts.rb = best_sts.ops_a - best_sts.ops_b;
	}
	else if (best_sts.ops_a < 0 && best_sts.ops_b < 0 && best_sts.ops_a < best_sts.ops_b)
	{ // TODO
		best_sts.rr = -best_sts.ops_a;
		best_sts.ra = 0;
		best_sts.rb = best_sts.ops_a - best_sts.ops_b;
	}
	return (best_sts);
}

static t_best	best_assign(t_best best_sts, long a, long b);
static t_best	best_sts_init_helpr(t_best best_sts, t_sts sts);

static t_best	best_sts_init(t_best best_sts, t_sts sts)
{
	best_sts = best_assign(best_sts, sts.ops_a_pos, sts.ops_b_neg);
	best_sts.ops_total = ft_abs(sts.ops_a_pos - sts.ops_b_neg);
	if (ft_abs(sts.ops_a_neg - sts.ops_b_pos) < best_sts.ops_total)
	{
		best_sts = best_assign(best_sts, sts.ops_a_neg, sts.ops_b_pos);
		best_sts.ops_total = ft_abs(sts.ops_a_neg - sts.ops_b_pos);
	}
	if (ft_abs(sts.ops_a_neg) < best_sts.ops_total || 
ft_abs(sts.ops_b_neg) < best_sts.ops_total)
	{
		best_sts = best_assign(best_sts, sts.ops_a_neg, sts.ops_b_neg);
		if (ft_abs(sts.ops_a_neg) < best_sts.ops_total)
			best_sts.ops_total = ft_abs(sts.ops_a_neg);
		if (ft_abs(sts.ops_b_neg) < best_sts.ops_total)
			best_sts.ops_total = ft_abs(sts.ops_b_neg);
	}
	best_sts = best_sts_init_helpr(best_sts, sts);	
	return (best_sts);
}

static t_best	best_sts_init_helpr(t_best best_sts, t_sts sts)
{
	if (ft_abs(sts.ops_a_pos) < best_sts.ops_total || 
ft_abs(sts.ops_b_pos) < best_sts.ops_total)
	{
		best_sts = best_assign(best_sts, sts.ops_a_pos, sts.ops_b_pos);
		if (ft_abs(sts.ops_a_pos) < best_sts.ops_total)
			best_sts.ops_total = ft_abs(sts.ops_a_pos);
		if (ft_abs(sts.ops_b_pos) < best_sts.ops_total)
			best_sts.ops_total = ft_abs(sts.ops_b_pos);
	}
	return (best_sts);
}

static t_best	best_assign(t_best best_sts, long a, long b)
{
	best_sts.ops_a = a;
	best_sts.ops_b = b;
	return (best_sts);
}
