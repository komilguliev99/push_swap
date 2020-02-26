/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:31:36 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/25 10:12:43 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        sort_stack(t_stack **a, t_stack **b, int val2, t_state *st)
{
    int         val3;

    val3 = (*b)->next->next->order;
    if ((*b)->order > val2 && val2 < val3 && (*b)->order > val3)
        rotate(a, b, "rb", st);
    else if ((*b)->order > val2 && val2 < val3 && (*b)->order < val3)
        swap(a, b, "sb", st);
    else if ((*b)->order < val2 && val2 > val3 && (*b)->order > val3)
        rotate_rev(a, b, "rrb", st);
    else if ((*b)->order > val2 && val2 > val3 && (*b)->order > val3)
    {
        rotate(a, b, "rb", st);
        swap(a, b, "sb", st);
    }
    else if ((*b)->order < val2 && val2 > val3 && (*b)->order < val3)
    {
        rotate_rev(a, b, "rrb", st);
        swap(a, b, "sb", st);
    }
}

void        generate_cmds(t_stack **a, t_stack **b, t_state *st, int stop)
{
    int         max;

    st->mid = st->max / 2 + st->next;
    move_down(a, b, st, (*a)->flag);
    while (*b)
    {
        max = st->mid;
        st->mid = (max - st->next) / 2 + st->next;
        st->flag++;
        if (st->b_cnt == 3)
        {
            sort_stack(a, b, (*b)->next->order, st);
            move_acnt(a, b, st, 3);
        }
        else if (st->b_cnt == 2)
        {
            if ((*b)->order > (*b)->next->order)
                swap(a, b, "sb", st);
            move_acnt(a, b, st, 2);
        }
        else
            move_up(b, a, st);
    }
    if (st->next <= st->cnt && (stop || stop < 0))
        generate_cmds(a, b, st, stop - 1);
}