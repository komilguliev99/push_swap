/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:56:33 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/23 10:38:17 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack         *ft_stk_create(int data)
{
    t_stack         *stk;

    if (!(stk = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    stk->next = NULL;
    stk->data = data;
    stk->flag = 0;
    stk->order = 0;
    return (stk);
}