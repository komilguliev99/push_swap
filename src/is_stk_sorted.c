/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stk_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:35:30 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/23 15:35:41 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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