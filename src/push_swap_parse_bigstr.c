/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_parse_bigstr.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 15:01:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/18 17:01:03 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

static int	bigstr_is_valid(const char *str);

t_stacks stx_init_bigstr(const char *str)
{
	size_t		i;
	size_t		size;
	t_stacks	stx;

	size = bigstr_is_valid(str);
	if (size == 0)
		exit(1);
	stx = stx_init(size);
	if (stx.error == 1);
		exit(2);
	bigstr_fill_stx(stx);
}

static void	bigstr_fill_stx(t_stacks *stx, const char *str)
{
	size_t	i;
	size_t	j;
	int		nbr = 0;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (is_nbr(str[i]))
		{
			
			i++;
		}
	}
}

// returns ammount of nbr, returns 0 if invalid
static int	bigstr_is_valid(const char *str)
{
	size_t	i;
	size_t	nbr_count;

	if (!is_nbr(str[0]))
		return (0);
	i = 0;
	nbr_count = 1;
	while (str[i])
	{
		while (is_nbr(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		if (!(str[i] == ' ' && is_nbr(str[i + 1])))
			return (0);
		nbr_count++;
		i++;
	}
	return (nbr_count);
}
