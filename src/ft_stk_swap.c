/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:19:35 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 12:20:27 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_stk_swap(t_stack **stk)
{
	t_stack		*head;

	if (!stk || !*stk || !(*stk)->next)
		return ;
	head = *stk;
	*stk = (*stk)->next;
	if (head->prev == *stk)
		(*stk)->prev = head;
	else
		(*stk)->prev = head->prev;
	head->next = (*stk)->next;
	if ((*stk)->next)
		(*stk)->next->prev = head;
	head->prev = *stk;
	(*stk)->next = head;
}
