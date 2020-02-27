/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:32:22 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 22:06:46 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_array_print(int *arr, int n)
{
	ft_putchar('[');
	while (n-- > 0)
	{
		ft_putnbr(*arr++);
		if (n > 0)
			ft_putstr(",  ");
	}
	write(1, "]\n", 2);
}

void		set_order(t_stack *a, int *sorted, int n)
{
	int		i;

	while (a)
	{
		i = 0;
		while (i < n && sorted[i] != a->data)
			i++;
		if (i != n)
		{
			a->order = i + 1;
			a->flag = 0;
		}
		a = a->next;
	}
}

void		print_stack(t_stack *stk)
{
	ft_stk_print(stk, 0);
	while (stk)
	{
		ft_putnbr(stk->data);
		stk = stk->next;
	}
}

void		reset_main(t_main *st, int ac)
{
	st->next = 1;
	st->max = ac;
	st->flag = 0;
	st->b_cnt = 0;
	st->cnt = ac;
	st->last = NULL;
	st->head = NULL;
}

int			main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			*sorted;
	t_main		st;

	a = NULL;
	b = NULL;
	st.a_cnt = 0;
	if (!(sorted = (int *)malloc(sizeof(int) * (ac - 1))))
		return (0);
	if (!fill_stack(&a, ac - 1, av + 1, &(st.a_cnt)))
	{
		if (a)
			ft_stk_clear(&a);
		write(2, "Error\n", 6);
		return (0);
	}
	fill_array(a, &sorted, st.a_cnt);
	reset_main(&st, st.a_cnt);
	ft_quicksort(sorted, 0, st.a_cnt - 1);
	set_order(a, sorted, st.a_cnt);
	if (!is_stk_sorted(a))
		generate_cmds(&a, &b, &st, -1);
	print_pushswap(st.head);
	return (0);
}
