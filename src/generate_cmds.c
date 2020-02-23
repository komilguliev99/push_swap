/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:31:36 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/24 00:36:55 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        move_down(t_stack **a, t_stack **b, t_state *st)
{
    t_stack     *it;
    int         flag;
    int         counter;

    it = NULL;
    counter = 0;
    flag = (*a)->flag;
    while (it != *a && flag == (*a)->flag)
    {
        if ((*a)->order <= st->mid)
        {
            push(a, b, "pb", 1);
            st->b_cnt++;
        }
        else
        {
            if (!it)
                it = *a;
            counter++;
            rotate(a, b, "ra", 1);
        } 
    }
    while (counter-- > 0)
    {
        if ((*b)->order != st->next && st->b_cnt > 3)
            rotate_rev(a, b, "rrr", 1);
        else
            rotate_rev(a, b, "rra", 1);        
    }
}

void        move_up(t_stack **b, t_stack **a, t_state *st)
{
    t_stack     *it;

    it = NULL;
    while (it != *b && *b)
    {
        if ((*b)->order >= st->mid)
        {
            (*b)->flag = st->flag;
            push(a, b, "pa", 1);
            st->b_cnt--;
            if ((*a)->order == st->next)
            {
                rotate(a, b, "ra", 1);
                st->next++;
            }
        }
        else
        {
            if (!it)
                it = *b;
            rotate(a, b, "rb", 1);
        }     
    }
}

void        move_acnt(t_stack **a, t_stack **b, t_state *st, int n)
{
    int     i;

    i = n;
    while (n-- > 0)
    {
        (*b)->flag = st->flag;
        st->next++;
        push(a, b, "pa", 1);
        rotate(a, b, "ra", 1);
    }
    st->b_cnt -= i;
}

void        sort_stack(t_stack **a, t_stack **b, int val2, int val3)
{
    if ((*b)->order > val2 && val2 < val3 && (*b)->order > val3)
        rotate(a, b, "rb", 1);
    else if ((*b)->order > val2 && val2 < val3 && (*b)->order < val3)
        swap(a, b, "sb", 1);
    else if ((*b)->order < val2 && val2 > val3 && (*b)->order > val3)
        rotate_rev(a, b, "rrb", 1);
    else if ((*b)->order > val2 && val2 > val3 && (*b)->order > val3)
    {
        rotate(a, b, "rb", 1);
        swap(a, b, "sb", 1);
    }
    else if ((*b)->order < val2 && val2 > val3 && (*b)->order < val3)
    {
        rotate_rev(a, b, "rrb", 1);
        swap(a, b, "sb", 1);
    }
}

void        generate_cmds(t_stack **a, t_stack **b, t_state *st, int stop)
{
    st->mid = st->max / 2 + st->next;
    move_down(a, b, st);
    while (*b)
    {
        st->max = st->mid;
        st->mid = (st->max - st->next) / 2 + st->next;
        st->flag++;
        if (st->b_cnt == 3)
        {
            sort_stack(a, b, (*b)->next->order, (*b)->next->next->order);
            move_acnt(a, b, st, 3);
        }
        else if (st->b_cnt == 2)
        {
            if ((*b)->order > (*b)->next->order)
                swap(a, b, "sb", 1);
            move_acnt(a, b, st, 2);
        }
        else
            move_up(b, a, st);
    }
    if (st->next <= st->cnt && (stop || stop < 0))
        generate_cmds(a, b, st, stop - 1);
}