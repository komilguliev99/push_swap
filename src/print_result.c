/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:22:16 by dcapers           #+#    #+#             */
/*   Updated: 2020/03/04 12:24:35 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_for(char *s1, char *s2, char c)
{
	char	cmd1[3];
	char	cmd2[3];

	cmd1[1] = 'a';
	cmd1[2] = '\0';
	cmd2[1] = 'b';
	cmd2[2] = '\0';
	cmd1[0] = c;
	cmd2[0] = c;
	if ((!ft_strcmp(s1, cmd1) &&
		!ft_strcmp(s2, cmd2))
		|| (!ft_strcmp(s1, cmd2) &&
		!ft_strcmp(s2, cmd1)))
	{
		cmd1[1] = c;
		ft_printf("%s\n", cmd1);
		return (1);
	}
	return (0);
}

void			print_pushswap(t_main *st, t_stack **a, t_list *list)
{
	while (list && list->next)
	{
		if (check_for(list->content, list->next->content, 's'))
			list = list->next;
		else if (check_for(list->content, list->next->content, 'r'))
			list = list->next;
		else
		{
			ft_putstr(list->content);
			write(1, "\n", 1);
		}
		list = list->next;
	}
	if (list)
	{
		ft_putstr(list->content);
		write(1, "\n", 1);
	}
	ft_stk_clear(a);
	ft_list_clear(&st->head);
}

void			print_result(t_stack *a, t_stack *b)
{
	t_stack		*head;

	head = a;
	if (b)
	{
		ft_stk_clear(&b);
		ft_stk_clear(&a);
		write(1, "KO\n", 3);
		return ;
	}
	while (a && a->next)
	{
		if (a->data > a->next->data)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		a = a->next;
	}
	write(1, "OK\n", 3);
	ft_stk_clear(&head);
}
