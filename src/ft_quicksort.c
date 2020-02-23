/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:40:13 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/22 19:39:28 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

static void     iterate(int *numbers, int *left, int *right, int pivot)
{
    while (*left < *right)
    {
        while ((numbers[*right] >= pivot) && (*left < *right))
            (*right)--;
        if (*left != *right)
        {
            numbers[*left] = numbers[*right];
            (*left)++;
        }
        while ((numbers[*left] <= pivot) && (*left < *right))
            (*left)++;
        if (*left != *right)
        {
            numbers[*right] = numbers[*left];
            (*right)--;
        }
    }
}

void            ft_quicksort(int *numbers, int left, int right)
{
    int     pivot;
    int     l_hold;
    int     r_hold;

    pivot = numbers[left];
    l_hold = left;
    r_hold = right;
    iterate(numbers, &left, &right, pivot);
    numbers[right] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        ft_quicksort(numbers, left, pivot - 1);
    if (right > pivot)
        ft_quicksort(numbers, pivot + 1, right);
}