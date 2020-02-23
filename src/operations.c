/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:02:17 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/23 15:37:34 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        swap(t_stack **a, t_stack **b, char *cmd, int print)
{
    if (cmd[1] == 'a')
        ft_stk_swap(a);
    else if (cmd[1] == 'b')
        ft_stk_swap(b);
    else if (cmd[1] == 's')
    {
        ft_stk_swap(a);
        ft_stk_swap(b);
    }
    if (print)
    {
        ft_putstr(cmd);
        write(1, "\n", 1);
    }
}

void         push(t_stack **a, t_stack **b, char *cmd, int print)
{
    if (cmd[1] == 'a' && *b)
        ft_stk_add(a, ft_stk_pop(b));
    else if (cmd[1] == 'b' && *a)
        ft_stk_add(b, ft_stk_pop(a));
    if (print)
    {
        ft_putstr(cmd);
        write(1, "\n", 1);
    }
}

void         rotate(t_stack **a, t_stack **b, char *cmd, int print)
{
    if (cmd[1] == 'a')
        ft_stk_rotate(a, 0);
    else if (cmd[1] == 'b')
        ft_stk_rotate(b, 0);
    else if (cmd[1] == 'r')
    {
        ft_stk_rotate(a, 0);
        ft_stk_rotate(b, 0);
    }
    if (print)
    {
        ft_putstr(cmd);
        write(1, "\n", 1);
    }
}

void         rotate_rev(t_stack **a, t_stack **b, char *cmd, int print)
{
    if (cmd[1] == 'r' && cmd[2] == 'a')
        ft_stk_rotate(a, 1);
    else if (cmd[1] == 'r' && cmd[2] == 'b')
        ft_stk_rotate(b, 1);
    else if (cmd[1] == 'r' && cmd[2] == 'r')
    {
        ft_stk_rotate(a, 1);
        ft_stk_rotate(b, 1);
    }
    if (print)
    {
        ft_putstr(cmd);
        write(1, "\n", 1);
    }
}