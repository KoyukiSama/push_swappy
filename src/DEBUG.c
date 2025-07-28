
#include "push_swap.h"
#include "ring_buffer.h"
#include "colors.h"
#include <stdio.h>

void print_buff(t_stacks stx)
{
	t_ringbuff rb_a = stx.rb_a;
	t_ringbuff rb_b = stx.rb_b;
	int curr_val;
	if (rb_a.buffer)
	{
		fprintf(stderr, "a: [ ");
		for (size_t i = 0; i < rb_a.count; i++)
		{
			curr_val = rb_get(rb_a, i);
			if (curr_val == stx.rba_low)
				fprintf(stderr, COLOR_BRIGHT_GREEN"%i, "COLOR_RESET, curr_val);
			else if (curr_val == stx.rba_high)
				fprintf(stderr, COLOR_GREEN"%i, "COLOR_RESET, curr_val);
			else if (curr_val == stx.rbb_low)
				fprintf(stderr, COLOR_BRIGHT_BLUE"%i, "COLOR_RESET, curr_val);
			else if (curr_val == stx.rbb_high)
				fprintf(stderr, COLOR_BLUE"%i, "COLOR_RESET, curr_val);
			else
				fprintf(stderr, "%i, ", curr_val);
		}
		fprintf(stderr, " ]\n");
	}
	if (rb_b.buffer)
	{
		fprintf(stderr, "b: [ ");
		for (size_t i = 0; i < rb_b.count; i++)
		{
			curr_val = rb_get(rb_b, i);
			if (curr_val == stx.rba_low)
				fprintf(stderr, COLOR_BRIGHT_GREEN"%i, "COLOR_RESET, curr_val);
			else if (curr_val == stx.rba_high)
				fprintf(stderr, COLOR_GREEN"%i, "COLOR_RESET, curr_val);
			else if (curr_val == stx.rbb_low)
				fprintf(stderr, COLOR_BRIGHT_BLUE"%i, "COLOR_RESET, curr_val);
			else if (curr_val == stx.rbb_high)
				fprintf(stderr, COLOR_BLUE"%i, "COLOR_RESET, curr_val);
			else
				fprintf(stderr, "%i, ", curr_val);
		}
		fprintf(stderr, " ]\n");
	}
	fprintf(stderr, "\n");
}

void print_best(t_best best)
{
	printf("|| best_opa_a: %li, best_ops_b: %li\n", best.ops_a, best.ops_b);
	printf("|| push_from: %c\n", best.push_from);
	printf("|| ops_total: %lu\n", best.ops_total);
	printf("||| ra: %lu\n", best.ra);
	printf("||| rb: %lu\n", best.rb);
	printf("||| rr: %lu\n", best.rr);
	printf("||| rra: %lu\n", best.rra);
	printf("||| rrb: %lu\n", best.rrb);
	printf("||| rrr: %lu\n", best.rrr);
}