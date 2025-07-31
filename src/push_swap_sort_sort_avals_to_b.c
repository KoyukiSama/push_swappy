/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_init_pushvals.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/31 17:01:00 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	tot_a_val(t_stacks stx);
static int	find_a_val_keep(t_stacks *stx, size_t *a_val_count);
static void	one_b_push(t_stacks *stx, int curr_top);

void	stx_init_push_to_b(t_stacks *stx)
{
	int		curr_top;
	int		a_val_keep;
	size_t	a_val_count;

	a_val_count = tot_a_val(*stx);
	a_val_keep = find_a_val_keep(stx, &a_val_count);
	while (a_val_count)
	{
		curr_top = rb_get_top(stx->rb_a);
		one_b_push(stx, curr_top);
		if (curr_top >= stx->rba_low && curr_top <= stx->rba_high &&
curr_top != a_val_keep)
		{
			stx_pb(stx);
			a_val_count--;
		}
		else
			stx_ra(stx);
	}
}

// calculate a values present in a
static int	tot_a_val(t_stacks stx)
{
	size_t	i;
	size_t	count;
	int		curr_val;

	count = 0;
	i = 0;
	while (i < stx.rb_a.count)
	{
		curr_val = rb_get(stx.rb_a, i);
		if (curr_val >= stx.rba_low && curr_val <= stx.rba_high)
			count++;
		i++;
	}
	return (count);
}

static int	find_a_val_keep(t_stacks *stx, size_t *a_val_count)
{
	int	curr_top;

	while (*a_val_count)
	{
		curr_top = rb_get_top(stx->rb_a);
		one_b_push(stx, curr_top);
		if (curr_top >= stx->rba_low && curr_top <= stx->rba_high)
			break;
		stx_ra(stx);
	}
	stx->a_min = curr_top;
	stx->a_max = curr_top;
	return ((*a_val_count)--, curr_top);
}

static void	one_b_push(t_stacks *stx, int curr_top)
{
	static int	b_set = 0;

	if (!b_set && curr_top >= stx->rbb_low && curr_top <= stx->rbb_high)
	{
		b_set = 1;
		stx_pb(stx);
		stx->b_min = curr_top;
		stx->b_max = curr_top;
	}
}

// returns: 1 if ra, 2 if rra
static int ra_or_rra(t_stacks *stx)
{
	int
	stx_ops_push_from(stx, 'A');
}
