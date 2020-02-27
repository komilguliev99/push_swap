/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stk_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:24:04 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 20:24:52 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_stk_sorted(t_stack *stk)
{
	while (stk && stk->next)
	{
		if (stk->data >= stk->next->data)
			return (0);
		stk = stk->next;
	}
	return (1);
}
