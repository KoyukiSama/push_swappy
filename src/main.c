/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 18:17:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/30 18:29:18 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

#include <stdio.h>
int main(int argc, char *argv[])
{
	t_stacks	stx;

	if (argc == 1)
		exit(0);
	if (argc == 2)
		stx = stx_init_bigstr(argv[1]);
	else
		stx = stx_init_smlstr(argv + 1, argc - 1);
	stx_no_dupes(stx);
	stx_check_ordered(stx);
	stx_get_bounds(&stx);
	stx_sort(&stx);
	stx_check_ordered(stx);
	printf("not-ordered\n");
	exit_clean(0, &stx);
}
