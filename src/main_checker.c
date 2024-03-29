/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:21:56 by dcapers           #+#    #+#             */
/*   Updated: 2020/03/04 12:25:12 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			fulfil(t_stack **a, t_stack **b, char *cmd)
{
	if (cmd[0] == 's')
		swap(a, b, cmd[1], 0);
	else if (cmd[0] == 'p')
		push(a, b, cmd[1], 0);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] != '\0')
		rotate_rev(a, b, cmd[2], 0);
	else if (cmd[0] == 'r')
		rotate(a, b, cmd[1], 0);
}

void				print_stacks(t_stack *a, t_stack *b)
{
	usleep(100000);
	ft_printf("\E[H\E[2J");
	ft_printf("%-12c|%12c\n", 'A', 'B');
	ft_printf("------------------------\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("%-12d|", a->data);
			a = a->next;
		}
		else
			ft_printf("%12s|", " ");
		if (b)
		{
			ft_printf("%12d", b->data);
			b = b->next;
		}
		ft_putchar('\n');
	}
	ft_printf("------------------------\n");
}

void				run(t_list *cmd, t_stack **a, t_stack **b, int flag)
{
	while (cmd)
	{
		fulfil(a, b, (char *)cmd->content);
		if (flag)
			print_stacks(*a, *b);
		cmd = cmd->next;
	}
}

int					check_flag(char *arg)
{
	while (ft_isspace(*arg))
		arg++;
	if (*arg == '-' && *(arg + 1) == 'v')
		while (*(arg + 2))
		{
			if (!ft_isspace(*(arg + 2)) && *(arg + 2) != '\0')
				return (0);
			arg++;
		}
	else
		return (0);
	return (1);
}

int					main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_list		*cmd;
	int			flag;

	a = NULL;
	b = NULL;
	cmd = NULL;
	flag = ac > 1 ? check_flag(av[1]) : 0;
	if (!fill_stack(&a, ac - 1 - flag, av + 1 + flag, NULL)
			|| (a && !fill_cmdlist(&cmd)))
	{
		if (a)
			ft_stk_clear(&a);
		write(2, "Error\n", 6);
		exit(0);
	}
	if (flag)
		print_stacks(a, b);
	if (!a)
		exit(0);
	run(cmd, &a, &b, flag);
	ft_list_clear(&cmd);
	print_result(a, b);
	return (0);
}
