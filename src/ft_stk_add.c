/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:55:08 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 11:55:46 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_stk_add(t_stack **dest, t_stack *src)
{
	t_stack		*last;

	if (!dest || !src)
		return ;
	last = *dest;
	while (last && last->next)
		last = last->next;
	src->next = *dest;
	src->prev = last;
	*dest = src;
}
