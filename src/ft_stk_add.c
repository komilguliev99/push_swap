/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:25:22 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/24 16:39:08 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        ft_stk_add(t_stack **dest, t_stack *src)
{
    t_stack     *last;

    if (!dest || !src)
        return ;
    last = *dest;
    while (last && last->next)
        last = last->next;
    src->next = *dest;
    src->prev = last;
    *dest = src;
}