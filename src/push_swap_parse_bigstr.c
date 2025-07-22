/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_parse_bigstr.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 15:01:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/22 14:55:43 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "push_swap.h"

static int	bigstr_is_valid(const char *str);
static void	bigstr_fill_stx(const char *str, t_stacks *stx);

void	stx_init_bigstr(const char *str)
{
	size_t		i;
	size_t		size;
	t_stacks	stx;

	size = bigstr_is_valid(str);
	stx = stx_init(size);
	bigstr_fill_stx(str, &stx);
}

// returns ammount of nbr, returns 0 if invalid
static int	bigstr_is_valid(const char *str)
{
	size_t	i;
	size_t	nbr_count;

	if (!ft_isdigit(str[0]))
		exit_clean(ERR_BIG_STR_IS_VALID, NULL);
	i = 0;
	nbr_count = 1;
	while (str[i])
	{
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		if (!(str[i] == ' ' && ft_isdigit(str[i + 1])))
			exit_clean(ERR_BIG_STR_IS_VALID, NULL);
		nbr_count++;
		i++;
	}
	return (nbr_count);
}

// checks for int limit and fills stx
static void	bigstr_fill_stx(const char *str, t_stacks *stx)
{
	size_t	i;
	size_t	j;
	int		nbr;
	int		error;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			nbr = ft_atoi_err(str + i, &error);
		if (error == 1)
			exit_clean(ERR_BIG_STR_FILL_STX, stx);
		rb_addbot(&(stx->rb_a), nbr);
		while (ft_isdigit(str[i]))
			i++;
		while (ft_isspace(str[i]))
			i++;
	}
}
