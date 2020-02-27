/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:46:43 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 16:02:39 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fill_array(t_stack *stk, int **sorted, int cnt)
{
	int		i;

	if (!(*sorted = (int *)malloc(sizeof(int) * cnt)))
		return ;
	i = 0;
	while (stk)
	{
		(*sorted)[i] = stk->data;
		i++;
		stk = stk->next;
	}
}
