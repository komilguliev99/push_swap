/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:20:48 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/28 14:29:15 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			generate_second(t_stack **a, t_stack **b, t_main *st)
{
	int		max;

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

static void		sorting(t_stack **a, t_stack **b, t_main *st, int stop)
{
	st->mid = st->max / 2 + st->next;
	move_down(a, b, st, (*a)->flag);
	while (*b)
		generate_second(a, b, st);
	if (st->next <= st->cnt && (stop || stop < 0))
		sorting(a, b, st, stop - 1);
}

void			generate_cmds(t_stack **a, t_stack **b, t_main *st, int stop)
{
	if (st->a_cnt > 5)
		sorting(a, b, st, stop);
	else
		sort_part(a, b, st);
}
