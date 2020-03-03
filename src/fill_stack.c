/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:14:32 by dcapers           #+#    #+#             */
/*   Updated: 2020/03/03 15:21:45 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			check_arg(char *arg, int *exist, int *len)
{
	while (*len >= 0 && ft_isspace(arg[*len]))
		(*len)--;
	while (*len >= 0)
	{
		if (!ft_isdigit(arg[*len]))
		{
			if (!ft_isdigit(arg[*len + 1]))
				return (0);
			if (arg[*len] == '-' || arg[*len] == '+')
				(*len)--;
			while (*len >= 0 && ft_isspace(arg[*len]))
				(*len)--;
			if (*len < 0 || ft_isdigit(arg[*len]))
				return (1);
			else
				return (0);
		}
		else
			(*len)--;
		*exist = 1;
	}
	return (1);
}

static int			has_duplicates(t_stack *stk)
{
	t_stack		*iter;

	while (stk)
	{
		iter = stk->next;
		while (iter)
		{
			if (iter->data == stk->data)
				return (1);
			iter = iter->next;
		}
		stk = stk->next;
	}
	return (0);
}

static int			check_diplicate(t_stack **a)
{
	if (has_duplicates(*a))
	{
		ft_stk_clear(a);
		return (0);
	}
	return (1);
}

int					fill_stack(t_stack **a, int ac, char **av, int *count)
{
	long int		num;
	int				exist;
	int				len;

	while (ac-- > 0)
	{
		len = ft_strlen(av[ac]) - 1;
		while (len >= 0)
		{
			exist = 0;
			if (!check_arg(av[ac], &exist, &len))
				return (0);
			num = ft_atoi(av[ac] + (len < 0 ? 0 : len + 1));
			if (num < -2147483648 || num > 2147483647)
				return (0);
			if (exist)
			{
				ft_stk_push(a, num);
				if (count)
					(*count)++;
			}
		}
	}
	return (check_diplicate(a));
}
