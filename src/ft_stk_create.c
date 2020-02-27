/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:57:30 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 11:58:13 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*ft_stk_create(int data)
{
	t_stack		*stk;

	if (!(stk = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stk->next = NULL;
	stk->prev = NULL;
	stk->data = data;
	stk->flag = 0;
	stk->order = 0;
	stk->sorted = 0;
	return (stk);
}
