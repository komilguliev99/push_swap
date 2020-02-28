/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:22:13 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/28 15:22:16 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_stack.h"

typedef struct	s_main
{
	int			max;
	int			next;
	int			cnt;
	int			flag;
	int			mid;
	int			b_cnt;
	int			a_cnt;
	t_list		*last;
	t_list		*head;
}				t_main;

void			ft_list_push(t_list **lst, char *data);
t_list			*ft_list_create(char *data);
void			ft_list_clear(t_list **lst);
void			swap(t_stack **a, t_stack **b, char c, t_main *st);
void			push(t_stack **a, t_stack **b, char c, t_main *st);
void			rotate(t_stack **a, t_stack **b, char c, t_main *st);
void			rotate_rev(t_stack **a, t_stack **b, char c, t_main *st);
int				fill_stack(t_stack **a, int ac, char **av, int *count);
void			fill_array(t_stack *stk, int **sorted, int cnt);
int				fill_cmdlist(t_list **cmd);
void			print_stacks(t_stack *a, t_stack *b);
void			ft_quicksort(int *numbers, int left, int right);
void			generate_cmds(t_stack **a, t_stack **b, t_main *st, int stop);
int				is_stk_sorted(t_stack *stk);
void			move_acnt(t_stack **a, t_stack **b, t_main *st, int n);
void			move_down(t_stack **a, t_stack **b, t_main *st, int flag);
void			move_up(t_stack **b, t_stack **a, t_main *st);
void			sort_stack(t_stack **a, t_stack **b, t_main *st, char c);
void			sort_part(t_stack **a, t_stack **b, t_main *st);
void			print_pushswap(t_main *st, t_stack **a, t_list *list);
void			print_result(t_stack *a, t_stack *b);

#endif
