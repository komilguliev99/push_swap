/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:17:36 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 12:19:17 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_stk_rotate(t_stack **stk, int rev)
{
	t_stack		*first;
	t_stack		*last;

	if (!stk || !*stk || !(*stk)->next)
		return ;
	first = *stk;
	last = first->prev;
	if (!rev)
	{
		last->next = first;
		*stk = (*stk)->next;
		(*stk)->prev = first;
		first->next = NULL;
	}
	else
	{
		while ((*stk)->next != last)
			*stk = (*stk)->next;
		(*stk)->next = NULL;
		last->next = first;
		last->prev = *stk;
		*stk = last;
	}
}
