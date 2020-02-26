/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:32:44 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/25 10:14:27 by dcapers          ###   ########.fr       */
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
    t_list              *lst;
}                       t_state;

void        ft_list_push(t_list **lst, char *data);
t_list      *ft_list_create(char *data);
void        ft_list_clear(t_list **lst);
void        swap(t_stack **a, t_stack **b, char *cmd, t_state *st);
void        push(t_stack **a, t_stack **b, char *cmd, t_state *st);
void        rotate(t_stack **a, t_stack **b, char *cmd, t_state *st);
void        rotate_rev(t_stack **a, t_stack **b, char *cmd, t_state *st);
int         fill_stack(t_stack **a, int ac, char **av, int *sorted);
void        print_stacks(t_stack *a, t_stack *b);
void        ft_quicksort(int *numbers, int left, int right);
void        generate_cmds(t_stack **a, t_stack **b, t_state *st, int stop);
int         is_stk_sorted(t_stack *stk);
void        move_acnt(t_stack **a, t_stack **b, t_state *st, int n);
void        move_down(t_stack **a, t_stack **b, t_state *st, int flag);
void        move_up(t_stack **b, t_stack **a, t_state *st);







#endif