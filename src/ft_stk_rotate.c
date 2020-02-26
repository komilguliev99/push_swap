/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:27:22 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/24 17:14:08 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        ft_stk_rotate(t_stack **stk, int rev)
{
    t_stack     *first;
    t_stack     *last;

    if (!stk || !*stk || !(*stk)->next)
        return ;
    first = *stk;
    last = first->prev;
    if (!rev)
    {
        last->next = first;
        *stk = (*stk)->next;
        (*stk)->prev = first;
        first->next = NULL;
    }
    else
    {
        while ((*stk)->next != last)
            *stk = (*stk)->next;
        (*stk)->next = NULL;
        last->next = first;
        last->prev = *stk;
        *stk = last;
    } 
}