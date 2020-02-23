/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:14:32 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/22 18:37:38 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int              check_arg(char *arg)
{
    int     i;

    i = 0;
    while (arg[i] != '\0')
    {
        if (!ft_isdigit(arg[i]))
            return (0);
        i++;
    }
    return (1);
}

static int              has_duplicates(t_stack *stk)
{
    t_stack     *iter;

    while (stk)
    {
        iter = stk->next;
        while (iter)
        {
            if (iter->data == stk->data)
                return (1);
            iter = iter->next;
        }
        stk = stk->next;
    }
    return (0);
}

int              fill_stack(t_stack **a, int ac, char **av, int *sorted)
{
    while (ac > 1)
    {
        if (!check_arg(av[ac - 1]))
        {
            ft_stk_clear(a);
            return (0);
        }
        ft_stk_push(a, ft_atoi(av[ac - 1]));
        if (sorted)
            sorted[ac - 2] = (*a)->data;
        ac--;
    }
    if (has_duplicates(*a))
    {
        ft_stk_clear(a);
        if (sorted)
            free(sorted);
        return (0);
    }
    return (1);
}