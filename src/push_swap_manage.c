/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_manage.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 17:49:21 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/30 18:18:58 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static int	stx_perror(int error_nbr);

t_stacks	stx_init(size_t size)
{
	t_stacks	stx;

	stx.rb_a = rb_init(size);
	if (!stx.rb_a.buffer)
		exit_clean(ERR_STX_INIT, &stx);
	stx.rb_b = rb_init(size);
	if (!stx.rb_b.buffer)
		exit_clean(ERR_STX_INIT, &stx);
	return (stx);
}

void	stx_destroy(t_stacks *stx)
{
	rb_destroy(stx->rb_a);
	rb_destroy(stx->rb_b);
	return ;
}

void exit_clean(int err_code, t_stacks *stx)
{
	if (stx)
		stx_destroy(stx);
	if (err_code != 0)
		exit(stx_perror(err_code));
	exit(0);
}

static int	stx_perror(int error_nbr)
{
	if (error_nbr != 0)
		write(2, "Error\n", 6);
	return (error_nbr);
}
