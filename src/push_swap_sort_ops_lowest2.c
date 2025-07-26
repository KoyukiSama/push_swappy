/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_ops_lowest2.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/26 15:04:57 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_best calc_best_pos(t_best best_sts, long ops_a, long ops_b);
static t_best calc_best_neg(t_best best_sts, long ops_a, long ops_b);
static t_best calc_best_posneg(t_best best_sts, long ops_a, long ops_b);
static t_best calc_best_negpos(t_best best_sts, long ops_a, long ops_b);

t_best	calc_best_helpr(t_best best_sts)
{
	if (best_sts.ops_a >= 0 && best_sts.ops_b >= 0)
		best_sts = calc_best_pos(best_sts, best_sts.ops_a, best_sts.ops_b);
	else if (best_sts.ops_a < 0 && best_sts.ops_b < 0)
		best_sts = calc_best_neg(best_sts, best_sts.ops_a, best_sts.ops_b);
	else if (best_sts.ops_a > best_sts.ops_b)
		best_sts = calc_best_posneg(best_sts, best_sts.ops_a, best_sts.ops_b);
	else if (best_sts.ops_a < best_sts.ops_b)
		best_sts = calc_best_negpos(best_sts, best_sts.ops_a, best_sts.ops_b);
	return (best_sts);
}

static t_best calc_best_pos(t_best best_sts, long ops_a, long ops_b)
{
	if (ops_a > ops_b)
	{
		best_sts.rr = ops_a;
		best_sts.ra = ops_a - ops_b;
	}
	else
	{
		best_sts.rr = ops_b;
		best_sts.rb = ops_b - ops_a;
	}
	return (best_sts);
}

static t_best calc_best_neg(t_best best_sts, long ops_a, long ops_b)
{
	if (ops_a < ops_b)
	{
		best_sts.rrr = -ops_b;
		best_sts.rra = -ops_a + ops_b;
	}
	else
	{
		best_sts.rrr = -ops_a;
		best_sts.rrb = ops_b + -ops_a;
	}
	return (best_sts);
}

static t_best calc_best_posneg(t_best best_sts, long ops_a, long ops_b)
{
	if (ops_a > -ops_b)
	{
		best_sts.ra = ops_a;
		best_sts.rrb = -ops_b;
	}
	else
	{
		best_sts.ra = ops_a;
		best_sts.rrb = -ops_b;
	}
	return (best_sts);
}

static t_best calc_best_negpos(t_best best_sts, long ops_a, long ops_b)
{
	// -50 > +30
	if (-ops_a > ops_b)
	{
		best_sts.rra = -ops_a;
		best_sts.rb = ops_b;
	}
	else // -30 > +50
	{
		best_sts.rra = -ops_a;
		best_sts.rb = ops_b;
	}
	return (best_sts);
}
