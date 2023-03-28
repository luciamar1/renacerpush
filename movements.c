/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:27:02 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/03/28 18:53:39 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_dlist **stack_a)
{
    *stack_a = (*stack_a)->prev;
}

void reverse_rotate_a_b(t_dlist **stack_a, t_dlist **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}

void rotate(t_dlist **stack_a)
{
    *stack_a = (*stack_a)->next;
}

void rotate_a_and_b(t_dlist **stack_a, t_dlist **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}

int swap_a_or_b(t_dlist  **stack)
{
    
    int     swap;
    
    if(!*stack)
        return (1);
    swap = (*stack)->content;
    (*stack)->content = ((*stack)->prev->content);
    (*stack)->prev->content = swap;
    return(0);
}

void    push_x(t_dlist **stack_b, t_dlist **stack_a)
{
        t_dlist    *swap;

        swap = *stack_a;
        *stack_a = (*stack_a)->next;
        (*stack_a)->prev = NULL;

        swap->next = *stack_b;
        *stack_b = swap;
}

void    swap_a_and_b(t_dlist **stack_a, t_dlist **stack_b)
{
    swap_a_or_b(stack_a);
    swap_a_or_b(stack_b);
}