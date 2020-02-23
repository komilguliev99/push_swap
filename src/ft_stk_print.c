/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:27:33 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/21 23:52:33 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        ft_stk_print(t_stack *stk)
{
    if (!stk)
        write(1, "(NULL)\n", 7);
    while (stk)
    {
        ft_putnbr((int)stk->data);
        if (stk->next)
            write(1, " => ", 4);
        else
            write(1, " => (NULL)\n", 11);
        stk = stk->next;
    }
}