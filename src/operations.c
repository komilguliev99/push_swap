/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:39:07 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 19:00:11 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		update_state(t_main *st, char *cmd)
{
	if (!st->head)
	{
		st->head = ft_lstnew(cmd, 5);
		st->last = st->head;
	}
	else
	{
		st->last->next = ft_lstnew(cmd, 5);
		st->last = st->last->next;
	}
}

void			swap(t_stack **a, t_stack **b, char c, t_main *st)
{
	char	cmd[3];

	cmd[2] = '\0';
	cmd[1] = c;
	cmd[0] = 's';
	if (cmd[1] == 'a')
		ft_stk_swap(a);
	else if (cmd[1] == 'b')
		ft_stk_swap(b);
	else if (cmd[1] == 's')
	{
		ft_stk_swap(a);
		ft_stk_swap(b);
	}
	if (st)
		update_state(st, cmd);
}

void			push(t_stack **a, t_stack **b, char c, t_main *st)
{
	char	cmd[3];

	cmd[2] = '\0';
	cmd[1] = c;
	cmd[0] = 'p';
	if (cmd[1] == 'a' && *b)
		ft_stk_add(a, ft_stk_pop(b));
	else if (cmd[1] == 'b' && *a)
		ft_stk_add(b, ft_stk_pop(a));
	if (st)
		update_state(st, cmd);
}

void			rotate(t_stack **a, t_stack **b, char c, t_main *st)
{
	char	cmd[3];

	cmd[2] = '\0';
	cmd[1] = c;
	cmd[0] = 'r';
	if (cmd[1] == 'a')
		ft_stk_rotate(a, 0);
	else if (cmd[1] == 'b')
		ft_stk_rotate(b, 0);
	else if (cmd[1] == 'r')
	{
		ft_stk_rotate(a, 0);
		ft_stk_rotate(b, 0);
	}
	if (st)
		update_state(st, cmd);
}

void			rotate_rev(t_stack **a, t_stack **b, char c, t_main *st)
{
	char	cmd[4];

	cmd[3] = '\0';
	cmd[2] = c;
	cmd[1] = 'r';
	cmd[0] = 'r';
	if (cmd[1] == 'r' && cmd[2] == 'a')
		ft_stk_rotate(a, 1);
	else if (cmd[1] == 'r' && cmd[2] == 'b')
		ft_stk_rotate(b, 1);
	else if (cmd[1] == 'r' && cmd[2] == 'r')
	{
		ft_stk_rotate(a, 1);
		ft_stk_rotate(b, 1);
	}
	if (st)
		update_state(st, cmd);
}
