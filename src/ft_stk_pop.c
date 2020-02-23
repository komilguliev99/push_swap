/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:05:33 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/21 21:13:14 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack         *ft_stk_pop(t_stack **stk)
{
    t_stack     *el;

    if (!stk || !*stk)
        return (NULL);
    el = *stk;
    *stk = (*stk)->next;
    el->next = NULL;
    return (el);
}