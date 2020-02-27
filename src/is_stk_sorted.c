/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stk_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:24:04 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 12:24:31 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_stk_sorted(t_stack *stk)
{
	while (stk && stk->next)
	{
		if (stk->order >= stk->next->order)
			return (0);
		stk = stk->next;
	}
	return (1);
}
