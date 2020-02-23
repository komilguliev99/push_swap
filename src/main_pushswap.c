/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:57:51 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/24 00:07:51 by dcapers          ###   ########.fr       */
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
    st.b_cnt = 0;
    st.cnt = ac - 1;
    ft_quicksort(sorted, 0, ac - 2);
    set_order(a, sorted, ac - 1);
    if (!is_stk_sorted(a))
        generate_cmds(&a, &b, &st, -1);
    return (0);
}