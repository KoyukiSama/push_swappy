/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_parse_smlstr.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 15:01:44 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/22 17:18:36 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	smlstr_is_valid(const char **str);

t_stacks	stx_init_smlstr(const char **str)
{
	size_t		size;
	t_stacks	stx;

	size = bigstr_is_valid(str);
	stx = stx_init(size);
	bigstr_fill_stx(str, &stx);
	return (stx);
}

static int	smlstr_is_valid(const char **str)
{
	size_t	i;
	size_t	nbr_count;

	if (!ft_isdigit(str[0]))
		exit_clean(ERR_SML_STR_IS_VALID, NULL);
	i = 0;
	nbr_count = 1;
	while (str[i])
	{
		if (ft_issign(str[i]))
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		if (!gap_isvalid(str + i))
			exit_clean(ERR_BIG_STR_IS_VALID, NULL);
		nbr_count++;
		i++;
	}
	return (nbr_count);
}
