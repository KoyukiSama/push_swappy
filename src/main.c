/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 18:17:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/27 15:35:30 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <push_swap.h>

#include <stdio.h>
int main(int argc, char *argv[])
{
	t_stacks	stx;

	if (argc == 1)
		exit_clean(ERR_CMD_LINE, NULL);
	if (argc == 2)
		stx = stx_init_bigstr(argv[1]);
	else
		stx = stx_init_smlstr(argv + 1, argc - 1);
	stx_no_dupes(stx);
	stx_get_rba_high(&stx);
	
printf("rba_low: %i, rba_high: %i, rbb_low: %i, rbb_high: %i\n", stx.rba_low, stx.rba_high, stx.rbb_low, stx.rbb_high);
printf("index: %li, val: %i\n", stx.sts.index, stx.sts.val);
printf("a_pos: %li , a_neg: %li\nb_pos: %li, b_neg: %li\n", stx.sts.ops_a_pos, stx.sts.ops_a_neg\
, stx.sts.ops_b_pos, stx.sts.ops_b_neg);

	stx_sort(&stx);

	exit_clean(0, &stx);
}
