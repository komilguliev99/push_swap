/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:57:51 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/23 14:07:18 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        ft_array_print(int *arr, int n)
{
    ft_putchar('[');
    while (n-- > 0)
    {
        ft_putnbr(*arr++);
        if (n > 0)
            ft_putstr(",  ");
    }
    write(1, "]\n", 2);
}

void        set_order(t_stack *a, int *sorted, int n)
{
    int         i;

    while (a)
    {
        i = 0;
        while (i < n && sorted[i] != a->data)
            i++;
        if (i != n)
        {
            a->order = i + 1;
            a->flag = 0;
        }
        a = a->next;
    }
}

int         is_sorted(t_stack *a, int *sorted, int n)
{
    while (a && n-- > 0)
    {
        if (a->data != *sorted)
            return (0);
        a = a->next;
        sorted++;
    }
    return (1);
}

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
            push(a, b, "pb");
            write(1, "pb\n", 3);
        }
        else
        {
            if (!it)
                it = *a;
            counter++;
            rotate(a, b, "ra");
            write(1, "ra\n", 3);
        } 
    }
    while (counter-- > 0)
    {
        if ((*b)->order != st->next)
        {
            rotate_rev(a, b, "rrr");
            write(1, "rrr\n", 4);
        }
        else
        {
            rotate_rev(a, b, "rra");
            write(1, "rra\n", 4);
        }
        
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
            push(a, b, "pa");
            write(1, "pa\n", 3);
            if ((*a)->order == st->next)
            {
                rotate(a, b, "ra");
                write(1, "ra\n", 3);
                st->next++;
            }
        }
        else
        {
            if (!it)
                it = *b;
            rotate(a, b, "rb");
            write(1, "rb\n", 3);
        }     
    }
}

int        is_stk_sorted(t_stack *stk)
{
    while (stk && stk->next)
    {
        if (stk->order >= stk->next->order)
            return (0);
        stk = stk->next;
    }
    return (1);
}

void        generate_cmds(t_stack **a, t_stack **b, t_state *st)
{
    st->mid = st->max / 2 + st->next;
    move_down(a, b, st);
    while (*b)
    {
        st->max = st->mid;
        st->mid = (st->max - st->next) / 2 + st->next;
        st->flag++;
        move_up(b, a, st);
    }
    if (!is_stk_sorted(*a))
        generate_cmds(a, b, st);
}

void        print_stack(t_stack *stk)
{
    ft_stk_print(stk);
    while (stk)
    {
        ft_putnbr(stk->data);
        stk = stk->next;
    }
}

int         main(int ac, char **av)
{
    t_stack     *a;
    t_stack     *b;
    int         *sorted;
    t_state     st;

    a = NULL;
    b = NULL;
    if (!(sorted = (int *)malloc(sizeof(int) * (ac - 1))))
        return (0);
    if (!fill_stack(&a, ac, av, sorted))
    {
        if (a)
            ft_stk_clear(&a);
        write(2, "Error\n", 6);
        return (0);
    }
    st.next = 1;
    st.max = ac - 1;
    st.flag = 0;
    ft_quicksort(sorted, 0, ac - 2);
    set_order(a, sorted, ac - 1);
    if (!is_stk_sorted(a))
        generate_cmds(&a, &b, &st);
    return (0);
}