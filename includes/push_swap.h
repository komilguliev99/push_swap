/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:32:44 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/24 00:07:28 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_stack.h"

typedef struct          s_state
{
    int                 max;
    int                 next;
    int                 cnt;
    int                 flag;
    int                 mid;
    int                 b_cnt;
}                       t_state;

void        ft_list_push(t_list **lst, char *data);
t_list      *ft_list_create(char *data);
void        ft_list_clear(t_list **lst);
void        swap(t_stack **a, t_stack **b, char *cmd, int print);
void        push(t_stack **a, t_stack **b, char *cmd, int print);
void        rotate(t_stack **a, t_stack **b, char *cmd, int print);
void        rotate_rev(t_stack **a, t_stack **b, char *cmd, int print);
int         fill_stack(t_stack **a, int ac, char **av, int *sorted);
void        print_stacks(t_stack *a, t_stack *b);
void        ft_quicksort(int *numbers, int left, int right);
void        generate_cmds(t_stack **a, t_stack **b, t_state *st, int stop);
int         is_stk_sorted(t_stack *stk);







#endif