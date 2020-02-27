/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:33:31 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 20:06:42 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		reverse_rotate(t_stack **a, t_stack **b,
		t_main *st, int counter)
{
	while (counter-- > 0)
	{
		if ((*b)->order != st->next)
			rotate_rev(a, b, 'r', st);
		else
			rotate_rev(a, b, 'a', st);
	}
}

void			move_acnt(t_stack **a, t_stack **b, t_main *st, int n)
{
	int		i;

	i = n;
	while (n-- > 0)
	{
		(*b)->flag = st->flag;
		(*b)->sorted = 1;
		st->next++;
		push(a, b, 'a', st);
		rotate(a, b, 'a', st);
	}
	st->b_cnt -= i;
}

void			move_down(t_stack **a, t_stack **b, t_main *st, int flag)
{
	t_stack		*it;
	int			counter;

	it = NULL;
	counter = 0;
	while (it != *a && flag == (*a)->flag && !(*a)->sorted)
		if ((*a)->order == st->next && (*a)->prev->order == st->next - 1)
		{
			(*a)->sorted = 1;
			rotate(a, b, 'a', st);
			st->next++;
		}
		else if ((*a)->order <= st->mid)
		{
			push(a, b, 'b', st);
			st->b_cnt++;
		}
		else
		{
			if (!it)
				it = *a;
			counter++;
			rotate(a, b, 'a', st);
		}
	if (st->next != 1)
		reverse_rotate(a, b, st, counter);
}

void			move_up(t_stack **b, t_stack **a, t_main *st)
{
	int		i;

	i = st->b_cnt;
	while (i-- > 0 && *b)
	{
		if ((*b)->order == st->next)
			move_acnt(a, b, st, 1);
		else if ((*b)->order >= st->mid)
		{
			(*b)->flag = st->flag;
			push(a, b, 'a', st);
			st->b_cnt--;
		}
		else
			rotate(a, b, 'b', st);
	}
}
