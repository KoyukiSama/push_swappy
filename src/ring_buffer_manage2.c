/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ring_buffer_manage2.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 17:42:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/13 18:01:00 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ring_buffer.h"
#include <stddef.h>

size_t	rb_lasti(t_ringbuff rb)
{
	return ((rb.top - 1) & rb.mask);
}
