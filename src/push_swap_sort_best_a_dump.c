/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_best_a_dump.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/08/02 01:53:11 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int		closest_a_dump_val(t_stacks *stx);
static t_best	closest_b_insert(t_stacks *stx);

t_best	stx_a_dump(t_stacks *stx, t_best best, int *found)
{
	t_best	best;

	if (closest_a_dump_val(stx) == -1);
		return (best);
	stx_ops_push_from(stx, 'A');
	best = closest_b_insert(stx);
	*found = 1;
	return (best);
}

static int	closest_a_dump_val(t_stacks *stx)
{
	size_t	i;
	size_t	len;
	int		curr_val;

	i = 0;
	len = stx->rb_a.count - 1;
	while (i < len)
	{
		curr_val = rb_get(stx->rb_a, len);
		if (is_a_dumpable(stx, curr_val))
		{
			return (stx->sts.val = curr_val, stx->sts.index = len);
		}
		curr_val = rb_get(stx->rb_a, i);
		if (is_b_bounds(stx, curr_val))
		{
			return (stx->sts.val = curr_val, stx->sts.index = i);
		}
		i++;
		len--;
	}
	return (-1);
}

static t_best	closest_b_insert(t_stacks *stx)
{
	size_t	low_insert_index;
	size_t	high_insert_index;
	t_best	best1;
	t_best	best2;

	low_insert_index = rb_get_index(stx->rb_b, stx->b_min);
	high_insert_index = rb_get_index(stx->rb_b, stx->b_max);
	low_insert_index = (low_insert_index - 1 + stx->rb_a.size) & stx->rb_a.mask;
	high_insert_index = (high_insert_index + 1) & stx->rb_a.mask;
	stx->sts.index = low_insert_index;
	stx_ops_push_from(stx, "B");
	best1 = stx_ops_best(stx->sts, 'B');
	stx->sts.index = high_insert_index;
	stx_ops_push_from(stx, "B");
	best2 = stx_ops_best(stx->sts, 'B');
	if (best1.ops_total < best2.ops_total)
		return (best1);
	return (best2);
}
