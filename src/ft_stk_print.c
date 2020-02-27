/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:59:37 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 12:15:49 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_reverse(t_stack *stk)
{
	t_stack		*first;

	first = stk;
	stk = stk->prev;
	while (stk && stk != first)
	{
		ft_putnbr((int)stk->data);
		write(1, " => ", 4);
		stk = stk->prev;
	}
	ft_putnbr(first->data);
	write(1, " => (NULL)\n", 11);
}

void			ft_stk_print(t_stack *stk, int rev)
{
	t_stack		*first;

	if (!stk)
	{
		write(1, "(NULL)\n", 7);
		return ;
	}
	if (!rev)
		while (stk)
		{
			ft_putnbr((int)stk->data);
			if (stk->next)
				write(1, " => ", 4);
			else
				write(1, " => (NULL)\n", 11);
			stk = stk->next;
		}
	else
		print_reverse(stk);
}
