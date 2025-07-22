/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 17:36:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/22 17:18:30 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes
# include "ring_buffer.h"

// return codes
// < 10 COMMAND LINE
# define ERR_CMD_LINE 1
// < 20 STX error
# define ERR_STX_INIT 11
// < 30 PARSE error
# define ERR_BIG_STR_IS_VALID 20
# define ERR_BIG_STR_FILL_STX 21
# define ERR_SML_STR_IS_VALID 22

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
void		exit_clean(int err_code, t_stacks *stx);

// stx parsing
t_stacks	stx_init_bigstr(const char *str);

#endif
