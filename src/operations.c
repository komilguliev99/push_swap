/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:02:17 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/25 10:24:58 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        swap(t_stack **a, t_stack **b, char *cmd, t_state *st)
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
    if (st)
        ft_lstadd(&(st->lst), ft_lstnew(cmd, 5));
}

void         push(t_stack **a, t_stack **b, char *cmd, t_state *st)
{
    if (cmd[1] == 'a' && *b)
        ft_stk_add(a, ft_stk_pop(b));
    else if (cmd[1] == 'b' && *a)
        ft_stk_add(b, ft_stk_pop(a));
    if (st)
        ft_lstadd(&(st->lst), ft_lstnew(cmd, 5));
}

void         rotate(t_stack **a, t_stack **b, char *cmd, t_state *st)
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
    if (st)
        ft_lstadd(&(st->lst), ft_lstnew(cmd, 5));
}

void         rotate_rev(t_stack **a, t_stack **b, char *cmd, t_state *st)
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
    if (st)
        ft_lstadd(&(st->lst), ft_lstnew(cmd, 5));
}