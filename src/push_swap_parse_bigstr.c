/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_parse_bigstr.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 15:01:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/18 18:04:32 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "push_swap.h"

static int	bigstr_is_valid(const char *str, t_app *app);
static void	bigstr_fill_stx(const char *str, t_app *app);

void	stx_init_bigstr(const char *str, t_app *app)
{
	size_t		i;
	size_t		size;
	t_stacks	stx;

	size = bigstr_is_valid(str, app);
	app->stx = stx_init(size, app);
	bigstr_fill_stx(stx, str);
}

// returns ammount of nbr, returns 0 if invalid
static int	bigstr_is_valid(const char *str, t_app *app)
{
	size_t	i;
	size_t	nbr_count;

	if (!ft_isdigit(str[0]))
		exit_clean(ERR_BIG_STR_IS_VALID, app);
	i = 0;
	nbr_count = 1;
	while (str[i])
	{
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		if (!(str[i] == ' ' && ft_isdigit(str[i + 1])))
			exit_clean(ERR_BIG_STR_IS_VALID, app);
		nbr_count++;
		i++;
	}
	return (nbr_count);
}

static void	bigstr_fill_stx(const char *str, t_app *app)
{
	size_t	i;
	size_t	j;
	int		nbr = 0;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (ft_isdigit(str[i]))
		{
			
			i++;
		}
	}
}
