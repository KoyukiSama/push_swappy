/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_parse_strs.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/18 17:42:37 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/18 17:45:09 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	strs_destroy(char **strs)
{
	while (*strs)
		free(*strs++);
	if (strs)
		free(strs);
	return ;
}
