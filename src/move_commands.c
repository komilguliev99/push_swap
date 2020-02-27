/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:33:31 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 12:38:51 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		reverse_rotate(t_stack **a, t_stack **b,
		t_state *st, int counter)
{
	while (counter-- > 0)
	{
		if ((*b)->order != st->next)
			rotate_rev(a, b, "rrr", st);
		else
			rotate_rev(a, b, "rra", st);
	}
}

void			move_acnt(t_stack **a, t_stack **b, t_state *st, int n)
{
	int		i;

	i = n;
	while (n-- > 0)
	{
		(*b)->flag = st->flag;
		(*b)->sorted = 1;
		st->next++;
		push(a, b, "pa", st);
		rotate(a, b, "ra", st);
	}
	st->b_cnt -= i;
}

void			move_down(t_stack **a, t_stack **b, t_state *st, int flag)
{
	t_stack		*it;
	int			counter;

	it = NULL;
	counter = 0;
	while (it != *a && flag == (*a)->flag && !(*a)->sorted)
		if ((*a)->order == st->next && (*a)->prev->order == st->next - 1)
		{
			(*a)->sorted = 1;
			rotate(a, b, "ra", st);
			st->next++;
		}
		else if ((*a)->order <= st->mid)
		{
			push(a, b, "pb", st);
			st->b_cnt++;
		}
		else
		{
			if (!it)
				it = *a;
			counter++;
			rotate(a, b, "ra", st);
		}
	reverse_rotate(a, b, st, counter);
}

void			move_up(t_stack **b, t_stack **a, t_state *st)
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
			push(a, b, "pa", st);
			st->b_cnt--;
		}
		else
			rotate(a, b, "rb", st);
	}
}
