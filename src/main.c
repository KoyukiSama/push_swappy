/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 18:17:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/24 19:19:32 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <push_swap.h>

#include <stdio.h>
void print_buff(t_ringbuff *rb_a, t_ringbuff *rb_b);

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
	for (int i = 0; i < 6; i++)
		stx_pb(&stx);
	stx_sort(&stx);
	print_buff(&(stx.rb_a), &(stx.rb_b));
	exit_clean(0, &stx);
}


#include <stdio.h>
void print_buff(t_ringbuff *rb_a, t_ringbuff *rb_b)
{
	// fprintf(stderr, "a: [ ");
	// for (size_t i = 0; i < rb_a->size; i++)
	// {
	// 	fprintf(stderr, "%i, ", (*rb_a).buffer[i]);
	// }
	// fprintf(stderr, " ]\n");
	if (rb_a)
	{
		fprintf(stderr, "a: [ ");
		for (size_t i = rb_a->bot; (i & rb_a->mask) != rb_a->top; i++)
		{
			fprintf(stderr, "%i, ", (*rb_a).buffer[i & rb_a->mask]);
		}
		fprintf(stderr, " ]\n");
	}
	if (rb_b)
	{
		fprintf(stderr, "b: [ ");
		for (size_t i = rb_b->bot; (i & rb_b->mask) != rb_b->top; i++)
		{
			fprintf(stderr, "%i, ", (*rb_b).buffer[i & rb_b->mask]);
		}
		fprintf(stderr, " ]\n");
	}
	fprintf(stderr, "\n");
}
