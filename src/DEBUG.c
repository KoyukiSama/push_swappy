
#include "push_swap.h"
#include "ring_buffer.h"
#include <stdio.h>

void print_buff(t_stacks stx)
{
	t_ringbuff rb_a = stx.rb_a;
	t_ringbuff rb_b = stx.rb_b;
	if (rb_a.buffer)
	{
		fprintf(stderr, "a: [ ");
		for (size_t i = rb_a.bot; (i & rb_a.mask) != rb_a.top; i++)
		{
			fprintf(stderr, "%i, ", rb_a.buffer[i & rb_a.mask]);
		}
		fprintf(stderr, " ]\n");
	}
	if (rb_b.buffer)
	{
		fprintf(stderr, "b: [ ");
		for (size_t i = rb_b.bot; (i & rb_b.mask) != rb_b.top; i++)
		{
			fprintf(stderr, "%i, ", rb_b.buffer[i & rb_b.mask]);
		}
		fprintf(stderr, " ]\n");
	}
	fprintf(stderr, "\n");
}