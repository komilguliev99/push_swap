/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:22:52 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/21 20:26:15 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        ft_stk_swap(t_stack **stk)
{
    t_stack     *prev;

    if (!stk || !*stk || !(*stk)->next)
        return ;
    prev = *stk;
    *stk = (*stk)->next;
    prev->next = (*stk)->next;
    (*stk)->next = prev;
}