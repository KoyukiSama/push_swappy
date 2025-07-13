/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 17:36:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/13 17:38:15 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"

typedef struct s_stacks
{
	t_ringbuff	rb_a;
	t_ringbuff	rb_b;
}	t_stacks;
