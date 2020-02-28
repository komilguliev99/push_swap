/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:26:07 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/28 16:09:25 by dcapers          ###   ########.fr       */
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

void			sort_part(t_stack **a, t_stack **b, t_main *st)
{
	if (st->a_cnt == 3)
		sort_stack(b, a, st, 'a');
	else if (st->a_cnt == 2)
		swap(a, b, 'a', st);
	else if (st->a_cnt == 4)
		sort_four_el(a, b, st);
	else
		sort_five_el(a, b, st);
}
