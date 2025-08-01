/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_ops_best.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/08/02 01:00:03 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_best	best_sts_init(t_sts sts);
static t_best	calc_best(t_best best_sts);

// calculates best stx operations , stack -> stack_push_from
t_best	stx_ops_best(t_sts sts, char stack)
{
	t_best	best_sts;

	best_sts = best_sts_init(sts);
	best_sts = calc_best(best_sts);
	if (stack == 'A')
		best_sts.push_from = 'A';
	else
		best_sts.push_from = 'B';
	best_sts.ops_total += 1;
	return (best_sts);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char *argv[])
// {
// 	t_sts	sts;
// 	if (argc != 5)
// 		return (puts("params"), 1);
// 	sts.ops_a_pos = atol(argv[1]);
// 	sts.ops_a_neg = atol(argv[2]);
// 	sts.ops_b_pos = atol(argv[3]);
// 	sts.ops_b_neg = atol(argv[4]);
// 	t_best best = stx_ops_best(sts, 'A');
// printf("| ops_total: %lu\n", best_sts.ops_total);
// printf("| | best.ops_a: %ld\n", best.ops_a);
// printf("| | best.ops_b: %ld\n", best.ops_b);
// printf("| | | ra: %ld\n", best.ra);
// printf("| | | rb: %ld\n", best.rb);
// printf("| | | rr: %ld\n", best.rr);
// printf("| | | rra: %ld\n", best.rra);
// printf("| | | rrb: %ld\n", best.rrb);
// printf("| | | rrr: %ld\n", best.rrr);
// 	return (0);
// }

static t_best	calc_best(t_best best_sts)
{
	best_sts.ra = 0;
	best_sts.rb = 0;
	best_sts.rr = 0;
	best_sts.rra = 0;
	best_sts.rrb = 0;
	best_sts.rrr = 0;
	best_sts = calc_best_helpr(best_sts);
	best_sts.ops_total = best_sts.ra + best_sts.rb + best_sts.rr;
	best_sts.ops_total += best_sts.rra + best_sts.rrb + best_sts.rrr;
	return (best_sts);
}

static t_best	pick_highest(t_best best_sts, long ops_a, long ops_b);
static t_best	sum_both(t_best best_sts, long ops_a, long ops_b);

static t_best	best_sts_init(t_sts sts)
{
	t_best	best_sts;

	best_sts.ops_a = 0;
	best_sts.ops_b = 0;
	best_sts.ops_total = sts.ops_a_pos + sts.ops_b_pos + -sts.ops_a_neg + -sts.ops_b_neg;
	best_sts = sum_both(best_sts, sts.ops_a_pos, sts.ops_b_neg);
	best_sts = sum_both(best_sts, sts.ops_a_neg, sts.ops_b_pos);
	best_sts = pick_highest(best_sts, sts.ops_a_pos, sts.ops_b_pos);
	best_sts = pick_highest(best_sts, sts.ops_a_neg, sts.ops_b_neg);
	return (best_sts);
}

static t_best	pick_highest(t_best best_sts, long ops_a, long ops_b)
{
	size_t	ops_total;
	
	ops_total = ft_abs(ops_a);
	if ((size_t) ft_abs(ops_b) > ops_total)
		ops_total = ft_abs(ops_b);
	if (ops_total < best_sts.ops_total)
	{
		best_sts.ops_a = ops_a;
		best_sts.ops_b = ops_b;
		best_sts.ops_total = ops_total;
	}
	return (best_sts);
}

static t_best	sum_both(t_best best_sts, long ops_a, long ops_b)
{
	size_t	ops_total;
	
	ops_total = ft_abs(ops_a) + ft_abs(ops_b);
	if (ops_total < best_sts.ops_total)
	{
		best_sts.ops_a = ops_a;
		best_sts.ops_b = ops_b;
		best_sts.ops_total = ops_total;
	}
	return (best_sts);
}
