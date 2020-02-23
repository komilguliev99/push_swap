/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:44:54 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/22 18:13:16 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <unistd.h>
# include <stdlib.h>

typedef struct          s_stack
{
    int                 data;
    int                 order;
    int                 flag;
    struct s_stack      *next;
}                       t_stack;

t_stack                 *ft_stk_create(int data);
void                    ft_stk_push(t_stack **stack, int data);
void                    ft_stk_add(t_stack **dest, t_stack *src);
t_stack                 *ft_stk_pop(t_stack **stack);
void                    ft_stk_clear(t_stack **stack);
void                    ft_stk_print(t_stack *stack);
void                    ft_stk_swap(t_stack **stack);
void                    ft_stk_rotate(t_stack **stack, int reverse);

#endif