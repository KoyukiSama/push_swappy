/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 18:17:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/13 19:33:53 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_nbr(char c)
{
	return (c >= '0' && c <= '9');
}

char **str_to_strs(char *str)
{
	size_t	i;

	i = 0;
	if (!is_nbr(str[0]))
		return (NULL);	// TODO EXIT
	while (str[i])
	{
		while (is_nbr(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		if (!(str[i] == ' ' && is_nbr(str[i + 1])))
			return (NULL); // TODO EXIT
		i++;
	}
	i = 0;
	while (str[i])
	{
		// ATOI // plus exceed check
	}
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc == 2)  // string given
		
	else			// nbr list given

}
