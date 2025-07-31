/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_check_ordered.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/29 19:33:13 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/31 15:21:15 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ring_buffer.h"

void	stx_check_ordered(t_stacks stx)
{
	size_t	i;
	int		prev_val;
	int		curr_val;

	if (stx.rb_a.count == 1)
		exit_clean(0, &stx);
	i = 0;
	while (i < stx.rb_a.count - 1)
	{
		prev_val = rb_get(stx.rb_a, i);
		curr_val = rb_get(stx.rb_a, i + 1);
		if (curr_val > prev_val)
			return ;
		i++;
	}
	exit_clean(0, &stx);
}
