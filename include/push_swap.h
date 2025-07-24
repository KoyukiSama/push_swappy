/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/13 17:36:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/24 15:07:17 by kclaes        ########   odam.nl         */
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
# define ERR_SML_STR_FILL_STX 23
# define ERR_NO_DUPES 24

typedef	struct s_best
{
	size_t	index;
	size_t	best_a;
	size_t	best_b;
	char	push_to;
	size_t	ops_total;
}	t_best;

typedef struct s_sts
{
	size_t	index;
	int		val;
	size_t	ops_a_pos;
	size_t	ops_a_neg;
	size_t	ops_b_pos;
	size_t	ops_b_neg;
}	t_sts;

typedef struct s_stacks
{
	t_ringbuff	rb_a;
	t_ringbuff	rb_b;
	int			rbb_high;
	int			rbb_low;
	int			rba_high;
	int			rba_low;
	t_sts		sts_a;
	t_sts		sts_b;
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
t_stacks	stx_init_smlstr(char **strs, size_t strs_size);
void		stx_no_dupes(t_stacks stx);

// stx sort
void		stx_sort(t_stacks *stx);
void		stx_get_rba_high(t_stacks *stx);
void		stx_ops_push_to(t_stacks *stx, char stack);
void		stx_ops_push_from(t_stacks *stx, char stack);

#endif
