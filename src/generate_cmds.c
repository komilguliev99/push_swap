/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:20:48 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 18:59:10 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_stack(t_stack **a, t_stack **b, t_main *st, char c)
{
	int			val3;
	int			val2;

	val2 = (*b)->next->order;
	val3 = (*b)->next->next->order;
	if ((*b)->order > val2 && val2 < val3 && (*b)->order > val3)
		rotate(a, b, c, st);
	else if ((*b)->order > val2 && val2 < val3 && (*b)->order < val3)
		swap(a, b, c, st);
	else if ((*b)->order < val2 && val2 > val3 && (*b)->order > val3)
		rotate_rev(a, b, c, st);
	else if ((*b)->order > val2 && val2 > val3 && (*b)->order > val3)
	{
		rotate(a, b, c, st);
		swap(a, b, c, st);
	}
	else if ((*b)->order < val2 && val2 > val3 && (*b)->order < val3)
	{
		rotate_rev(a, b, c, st);
		swap(a, b, c, st);
	}
}

void			sort_four_el(t_stack **a, t_stack **b, t_main *st)
{
	while ((*a)->order != st->next)
		rotate(a, b, 'a', st);
	push(a, b, 'b', st);
	sort_stack(b, a, st, 'a');
	push(a, b, 'a', st);
}

void			sort_five_el(t_stack **a, t_stack **b, t_main *st)
{
	while ((*a)->order != 1)
		rotate(a, b, 'a', st);
	push(a, b, 'b', st);
	st->next++;
	sort_four_el(a, b, st);
	push(a, b, 'a', st);
}

void			generate_cmds(t_stack **a, t_stack **b, t_main *st, int stop)
{
	int		max;

	if (st->a_cnt > 5)
	{
		st->mid = st->max / 2 + st->next;
		move_down(a, b, st, (*a)->flag);
		while (*b)
		{
			max = st->mid;
			st->mid = (max - st->next) / 2 + st->next;
			st->flag++;
			if (st->b_cnt == 3)
			{
				sort_stack(a, b, st, 'b');
				move_acnt(a, b, st, 3);
			}
			else if (st->b_cnt == 2)
			{
				if ((*b)->order > (*b)->next->order)
					swap(a, b, 'b', st);
				move_acnt(a, b, st, 2);
			}
			else
				move_up(b, a, st);
		}
		if (st->next <= st->cnt && (stop || stop < 0))
			generate_cmds(a, b, st, stop - 1);
	}
	else
		sort_five_el(a, b, st);
}
