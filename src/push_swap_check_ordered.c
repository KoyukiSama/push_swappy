/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_check_ordered.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/29 19:33:13 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/30 18:28:22 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ring_buffer.h"

#include <stdio.h>
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
