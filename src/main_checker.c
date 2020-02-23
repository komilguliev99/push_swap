/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:24:22 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/22 18:26:15 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void             fulfil(t_stack **a, t_stack **b, char *cmd)
{
    if (cmd[0] == 's')
        swap(a, b, cmd);
    else if (cmd[0] == 'p')
        push(a, b, cmd);
    else if (cmd[0] == 'r' && cmd[1] == 'r')
        rotate_rev(a, b, cmd);
    else if (cmd[0] == 'r')
        rotate(a, b, cmd);
}

void             print_stacks(t_stack *a, t_stack *b)
{
    write(1, "A: ", 3);
    ft_stk_print(a);
    write(1, "B: ", 3);
    ft_stk_print(b);
    write(1, "____________________\n", 21);
}

int                     fill_cmdlist(t_list **cmd)
{
    char        *command;

    command = NULL;
    *cmd = NULL;
    while (get_next_line(0, &command) > 0)
    {
        if (!(ft_strcmp(command, "sa") == 0 || ft_strcmp(command, "sb") == 0 || ft_strcmp(command, "ss") == 0 ||
                ft_strcmp(command, "pa") == 0 || ft_strcmp(command, "pb") == 0 || ft_strcmp(command, "ra") == 0 ||
                ft_strcmp(command, "rb") == 0 || ft_strcmp(command, "rr") == 0 || ft_strcmp(command, "rra") == 0 ||
                ft_strcmp(command, "rrb") == 0 || ft_strcmp(command, "rrr") == 0))
        {
            ft_list_clear(cmd);
            return (0);
        }
        ft_list_push(cmd, command);
        command = NULL;
    }
    if (*cmd)
        return (1);
    return (0);
}

void                    print_result(t_stack *a, t_stack *b)
{
    if (b)
    {
        ft_stk_clear(&b);
        write(1, "KO\n", 3);
        return ;
    }
    while (a && a->next)
    {
        if (a->data > a->next->data)
        {
            write(1, "KO\n", 3);
            return ;
        }
        a = a->next;
    }
    write(1, "OK\n", 3);
}

int                     main(int ac, char **av)
{
    t_stack     *a;
    t_stack     *b;
    t_list      *cmd;
    t_list      *head_cmd;

    a = NULL;
    b = NULL;
    if (!fill_stack(&a, ac, av, NULL) || !fill_cmdlist(&cmd))
    {
        if (a)
            ft_stk_clear(&a);
        write(2, "Error\n", 6);
        return (0);
    }
    print_stacks(a, b);
    head_cmd = cmd;
    while (cmd)
    {
        fulfil(&a, &b, (char *)cmd->content);
        print_stacks(a, b);
        cmd = cmd->next;
    }
    ft_list_clear(&head_cmd);
    print_result(a, b);
    ft_stk_clear(&a);
    return (0);
}