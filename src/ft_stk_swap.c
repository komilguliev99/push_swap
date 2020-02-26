/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:22:52 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/24 17:50:07 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        ft_stk_swap(t_stack **stk)
{
    t_stack     *head;

    if (!stk || !*stk || !(*stk)->next)
        return ;
    head = *stk;
    *stk = (*stk)->next;
    if (head->prev == *stk)
        (*stk)->prev = head;
    else
        (*stk)->prev = head->prev;
    head->next = (*stk)->next;
    if ((*stk)->next)
        (*stk)->next->prev = head;
    head->prev = *stk;
    (*stk)->next = head;
}