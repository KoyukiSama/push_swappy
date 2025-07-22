/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_parse_dupes.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 18:37:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/22 18:58:37 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stx_no_dupes(t_stacks stx)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < stx.rb_a.count)
	{
		i = j + 1;
		while (i < stx.rb_a.count)
		{
			if (rb_get(stx.rb_a, j) == rb_get(stx.rb_a, i))
				exit_clean(ERR_NO_DUPES, &stx);
			i++;
		}
		j++;
	}
}
