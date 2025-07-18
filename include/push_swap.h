/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 17:36:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/18 16:50:18 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"

typedef struct s_stacks
{
	t_ringbuff	rb_a;
	t_ringbuff	rb_b;
	int			error;
}	t_stacks;

// operations 
// all returns success value

int			stx_sa(t_stacks *stx);
int			stx_sb(t_stacks *stx);
int			stx_ss(t_stacks *stx);
int			stx_pa(t_stacks *stx);
int			stx_pb(t_stacks *stx);
int			stx_ra(t_stacks *stx);
int			stx_rb(t_stacks *stx);
int			stx_rr(t_stacks *stx);
int			stx_rra(t_stacks *stx);
int			stx_rrb(t_stacks *stx);
int			stx_rrr(t_stacks *stx);

// stx management
t_stacks	stx_init(size_t size);
void		stx_destroy(t_stacks *stx);

// TODO fill stx
