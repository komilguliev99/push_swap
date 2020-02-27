/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:58:36 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 11:59:18 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*ft_stk_pop(t_stack **stk)
{
	t_stack		*el;

	if (!stk || !*stk)
		return (NULL);
	el = *stk;
	*stk = (*stk)->next;
	if (*stk)
		(*stk)->prev = el->prev;
	el->next = NULL;
	el->prev = NULL;
	return (el);
}
