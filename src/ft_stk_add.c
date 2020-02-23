/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:25:22 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/22 01:33:05 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        ft_stk_add(t_stack **dest, t_stack *src)
{
    if (!dest || !src)
        return ;
    src->next = *dest;
    *dest = src;
}