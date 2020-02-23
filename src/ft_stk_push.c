/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:00:42 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/21 16:39:02 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void         ft_stk_push(t_stack **stk, int data)
{
    t_stack         *new;

    if (stk == NULL)
        return ;
    if (!(new = ft_stk_create(data)))
        return ;
    new->next = *stk;
    *stk = new;
}