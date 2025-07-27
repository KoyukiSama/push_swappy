
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
		for (size_t i = 0; i < rb_a.count; i++)
		{
			fprintf(stderr, "%i, ", rb_get(rb_a, i));
		}
		fprintf(stderr, " ]\n");
	}
	if (rb_b.buffer)
	{
		fprintf(stderr, "b: [ ");
		for (size_t i = 0; i < rb_b.count; i++)
		{
			fprintf(stderr, "%i, ", rb_get(rb_b, i));
		}
		fprintf(stderr, " ]\n");
	}
	fprintf(stderr, "\n");
}