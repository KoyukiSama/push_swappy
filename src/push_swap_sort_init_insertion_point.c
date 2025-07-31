/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_init_insertion_point.c              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 19:04:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/31 18:11:39 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_a_insertion_point(t_stacks *stx);
static void	set_b_insertion_point(t_stacks *stx);

void	stx_init_push_to_b(t_stacks *stx)
{
	int		curr_top;

	while ()
	{
		curr_top = rb_get_top(stx->rb_a);
		one_b_push(stx, curr_top);
		
	}
}

static void	set_a_insertion_point(t_stacks *stx)
{
	int		curr_val;
	size_t	i;

	i = 0;
	while (i < stx->rb_a.count)
	{
		curr_val = rb_get(stx->rb_a, i);
		if (is_a_bounds(stx, curr_val))
		{
			stx->a_min = curr_val;
			stx->a_max = curr_val;
		}
		i++;
	}
}

static void	set_b_insertion_point(t_stacks *stx)
{
	size_t	i;
	size_t	len;
	int		curr_val;

	i = 0;
	len = stx->rb_a.count;
	while (i < len)
	{
		curr_val = rb_get(stx->rb_a, len);
		if (is_b_bounds(stx, curr_val))
		{
			stx->b_min = curr_val;
			stx->b_max = curr_val;
		}
		curr_val = rb_get(stx->rb_a, i);
		if (is_b_bounds(stx, curr_val))
		{
			stx->b_min = curr_val;
			stx->b_max = curr_val;
		}
		i++;
		len--;
	}
}

// push b insertion point to b
static void push_b_insertion_point(t_stacks *stx)
{

}
