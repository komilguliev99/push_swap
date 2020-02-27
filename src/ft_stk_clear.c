/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:56:19 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 11:57:08 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_stk_clear(t_stack **stk)
{
	t_stack		*del;

	if (!stk || !*stk)
		return ;
	while (*stk)
	{
		del = *stk;
		*stk = (*stk)->next;
		free(del);
	}
}
