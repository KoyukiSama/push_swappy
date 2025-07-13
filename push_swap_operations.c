/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_operations.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:27:30 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/13 18:10:49 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include "push_swap.h"

int	stx_sa(t_stacks *stx)
{
	int	temp;
	t_ringbuff	*rb_a;

	rb_a = &(stx->rb_a);
	if (rb_isempty(*rb_a) || rb_isone(*rb_a))
		return (0);
	temp = rb_get(*rb_a, rb_lasti(*rb_a));
	rb_set(rb_a, rb_lasti(*rb_a), rb_get(*rb_a, rb_lasti(*rb_a) - 1));
	rb_set(rb_a, (rb_lasti(*rb_a) - 1) & rb_a->mask, temp);
	return (1);
}

int	stx_sb(t_stacks *stx)
{
	int	temp;
	t_ringbuff	*rb_b;

	rb_b = &(stx->rb_b);
	if (rb_isempty(*rb_b) || rb_isone(*rb_b))
		return (0);
	temp = rb_get(*rb_b, rb_lasti(*rb_b));
	rb_set(rb_b, rb_lasti(*rb_b), rb_get(*rb_b, rb_lasti(*rb_b) - 1));
	rb_set(rb_b, (rb_lasti(*rb_b) - 1) & rb_b->mask, temp);
	return (1);
}

int	stx_ss(t_stacks *stx)
{
	int	pass;

	pass = 1;
	if (!rb_sa(stx))
		pass = 0;
	if (!rb_sb(stx))
		pass = 0;
	return (pass);
}

int	stx_pa(t_stacks *stx)
{
	t_ringbuff	*rb_a;
	t_ringbuff	*rb_b;

	rb_a = &(stx->rb_a);
	rb_b = &(stx->rb_b);
	if (rb_isempty(*rb_b))
		return (0);
	rb_addtop(rb_a, rb_get(*rb_b, rb_lasti(*rb_b)));
	rb_remtop(rb_b);
	return (1);
}

int	stx_pb(t_stacks *stx)
{
	t_ringbuff	*rb_a;
	t_ringbuff	*rb_b;

	rb_a = &(stx->rb_a);
	rb_b = &(stx->rb_b);
	if (rb_isempty(*rb_a))
		return (0);
	rb_addtop(rb_b, rb_get(*rb_a, rb_lasti(*rb_a)));
	rb_remtop(rb_a);
	return (1);
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
		for (size_t i = rb_b->bot; (i & rb_a->mask) != rb_b->top; i++)
		{
			fprintf(stderr, "%i, ", (*rb_b).buffer[i & rb_b->mask]);
		}
		fprintf(stderr, " ]\n");
	}
	fprintf(stderr, "\n");
}

int main(void)
{
	t_stacks stacks;
	
	stacks.rb_a = rb_init(8);
	stacks.rb_b = rb_init(8);

	for (size_t i = 0; i < 8; i++)
	{
		rb_a.buffer[i] = 0;
		rb_b.buffer[i] = 0;
	}
	rb_addtop(&rb_a, 1);
	rb_addtop(&rb_a, 2);
	rb_addtop(&rb_a, 3);
	rb_addtop(&rb_b, 1);
	rb_addtop(&rb_b, 2);
	rb_addtop(&rb_b, 3);
	fprintf(stderr, "top: %lu , bot: %lu\n", rb_a.top, rb_a.bot);
	print_buff(&rb_a, &rb_b);
	rb_ss(&rb_a, &rb_b);
	//rb_sb(&rb_a, &rb_b);
	
	fprintf(stderr, "top: %lu , bot: %lu\n", rb_a.top, rb_a.bot);
	print_buff(&rb_a, &rb_b);

	rb_a.top += 1;

	rb_destroy(rb_a);
	rb_destroy(rb_b);
}