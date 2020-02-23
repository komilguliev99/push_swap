/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:07:39 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/21 16:39:29 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        ft_stk_clear(t_stack **stk)
{
    t_stack     *del;

    if (!stk || !*stk)
        return ;
    while (*stk)
    {
        del = *stk;
        *stk = (*stk)->next;
        free(del);
    }
}