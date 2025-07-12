/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ring_buffer_swap.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:27:30 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/12 19:17:47 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"

void	rb_sa(t_ringbuff *rb_a, t_ringbuff *rb_b)
{
	int	temp;
	(void) rb_b;

	if (rb_isempty(*rb_a) || rb_isone(*rb_a))
		return ;
	temp = rb_get(*rb_a, rb_lasti(*rb_a));
	rb_set(rb_a, rb_lasti(*rb_a), rb_get(*rb_a, rb_lasti(*rb_a) - 1));
	rb_set(rb_a, (rb_lasti(*rb_a) - 1) & rb_a->mask, temp);
	return ;
}

void	rb_sb(t_ringbuff *rb_a, t_ringbuff *rb_b)
{
	int	temp;
	(void) rb_a;

	if (rb_isempty(*rb_b) || rb_isone(*rb_b))
		return ;
	temp = rb_get(*rb_b, rb_lasti(*rb_b));
	rb_set(rb_b, rb_lasti(*rb_b), rb_get(*rb_b, rb_lasti(*rb_b) - 1));
	rb_set(rb_b, (rb_lasti(*rb_b) - 1) & rb_b->mask, temp);
	return ;
}

void	rb_ss(t_ringbuff *rb_a, t_ringbuff *rb_b)
{
	rb_sa(rb_a, NULL);
	rb_sa(NULL, rb_b);
}

void	rb_pa(t_ringbuff *rb_a, t_ringbuff *rb_b)
{
	if (rb_isempty(*rb_b))
		return ;
	rb_addtop(rb_a, rb_get(*rb_b, rb_lasti(*rb_b)));
	rb_remtop(rb_b);
}

void	rb_pb(t_ringbuff *rb_a, t_ringbuff *rb_b)
{
	if (rb_isempty(*rb_a))
		return ;
	rb_addtop(rb_b, rb_get(*rb_a, rb_lasti(*rb_a)));
	rb_remtop(rb_a);
}

#include <stdio.h>
void print_buff(t_ringbuff *rb_a, t_ringbuff *rb_b)
{
	if (rb_a)
	{
		fprintf(stderr, "a: [ ");
		for (size_t i = rb_a->bot; i != rb_a->top; i++)
		{
			fprintf(stderr, "%i, ", (*rb_a).buffer[i]);
		}
		fprintf(stderr, " ]\n");
	}
	if (rb_b)
	{
		fprintf(stderr, "b: [ ");
		for (size_t i = rb_b->bot; i != rb_b->top; i++)
		{
			fprintf(stderr, "%i, ", (*rb_b).buffer[i]);
		}
		fprintf(stderr, " ]\n");
	}
	fprintf(stderr, "\n");
}

int main(void)
{
	t_ringbuff rb_a = rb_init(8);
	t_ringbuff rb_b = rb_init(8);

	for (size_t i = 0; i < 8; i++)
	{
		rb_a.buffer[i] = 0;
		rb_b.buffer[i] = 0;
	}
	rb_addtop(&rb_b, 1);
	rb_pa(&rb_a, &rb_b);
	print_buff(&rb_a, &rb_b);

	rb_a.top += 1;

	rb_destroy(rb_a);
	rb_destroy(rb_b);
}