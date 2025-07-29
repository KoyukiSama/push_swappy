/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_parse_smlstr.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 15:01:44 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/29 18:46:42 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	smlstr_is_valid(char **strs, size_t strs_size);
static void	smlstr_fill_stx(char **strs, size_t strs_size, t_stacks *stx);

t_stacks	stx_init_smlstr(char **strs, size_t strs_size)
{
	size_t		size;
	t_stacks	stx;

	size = smlstr_is_valid(strs, strs_size);
	stx = stx_init(size);
	smlstr_fill_stx(strs, strs_size, &stx);
	return (stx);
}

#include <stdio.h>
static int	smlstr_is_valid(char **strs, size_t strs_size)
{
	size_t	i;
	size_t	nbr_count;

	nbr_count = 0;
	while (nbr_count < strs_size)
	{
		i = 0;
		if (ft_issign(strs[nbr_count][i]))
			i++;
		while (ft_isdigit(strs[nbr_count][i]))
			i++;
		if (strs[nbr_count][i] != '\0')
			exit_clean(ERR_SML_STR_IS_VALID, NULL);
		nbr_count++;
	}
	return (nbr_count);
}

static void	smlstr_fill_stx(char **strs, size_t strs_size, t_stacks *stx)
{
	size_t	i;
	int		error;

	i = 0;
	while (i < strs_size)
	{
		rb_addbot(&(stx->rb_a), ft_atoi_err(strs[i], &error));
		if (error)
			exit_clean(ERR_SML_STR_FILL_STX, stx);
		i++;
	}
}
