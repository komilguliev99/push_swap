/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:16:12 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 12:17:10 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_stk_push(t_stack **stk, int data)
{
	t_stack			*new;
	t_stack			*last;

	if (stk == NULL)
		return ;
	if (!(new = ft_stk_create(data)))
		return ;
	last = *stk;
	while (last && last->next)
		last = last->next;
	new->next = *stk;
	new->prev = last;
	if (*stk)
		(*stk)->prev = new;
	*stk = new;
}
