/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/04/28 17:07:57 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_printf_dlist_ind(t_dlist *list)
{
    t_dlist *start;
    
    start = list;
    printf("print list == %d\n", list->index);
    list = list->next;
    while(list->content != start->content)
    {
        printf("print list == %d\n", list->index);
        list = list->next;
    }
    printf("\n\n");
}

int    ft_len_dlist(t_dlist *stack)
{
    int len;
    t_dlist *init;

    if (!stack)
        return (0);
    len = 1;
    init = stack;
    stack = stack->next;
    while(stack != init)
    {
        len ++;
        stack = stack->next;
    }
    return(len);
}

void    put_indice(t_dlist *list)
{
    t_dlist *min;
    int     ind;
    int     len;
    int     l;
   
    len = ft_len_dlist(list);
    min = list;
    ind = 0;
    l = ft_len_dlist(list);
    while(len --)
    {
        l = ft_len_dlist(list);
        while(l-- && (list)->index != -1)
            list = (list)->next;
        min = (list);
        l = ft_len_dlist(list);
        while(l--)
        {
            if((list)->content < min->content && (list)->index == -1)   
                min = list;
            list = (list)->next;
        }
        if(min->index == -1)
            min->index = ind;
        ind ++;
    }
}

int choose(int len)
{
    int max;

    if(len < 100)
        max = 2;
    if(len >= 100 && len < 300)
        max = 4;
    else
        max = 8;
    max = len/max;
    return(max);
}

void    push_20(t_dlist **stack_a, t_dlist **stack_b)
{
    int len;
    int head;
    int max;
    int optim;
    int op;
    
    len = ft_len_dlist(*stack_a);
    printf("   leeeeen %d\n", len);
    max = choose(len);
    head = 1;
    int cont = 0;
    optim = 0;
    if (max == 0)
        max = 1;
    ft_printf_dlist(*stack_a);
    while(*stack_a) 
    {
        while(len --)
        {
            if((*stack_a)->index <= max)
            {
                op = optim;
                while(op --)
                    *stack_a = (*stack_a)->prev;
                while(optim --)
                    rotate(stack_a, 'a');
                if(head == 1)
                {
                    cont ++;
                    push_x(&(*stack_b), &(*stack_a), 'b');
                    head = 0;
                }
                else 
                {
                    cont++;
                    push_x(&(*stack_b), &(*stack_a), 'b');
                    rotate(stack_b, 'b');
                    head = 1;
                }
                optim = 0;
            }
            else
            {
                optim ++;
                if (*stack_a)
                    (*stack_a) = (*stack_a)->next;
            }
        }
        if (*stack_a)
            len = ft_len_dlist(*stack_a);
        max += max;
    }
    printf("\n\n\n");
    ft_printf_dlist_ind(*stack_b);
}

int ft_optim(int index, t_dlist *stack_next)
{
    t_dlist *stack_prev;
    int     verif_next;
    int     verif_prev;
    
    stack_prev = stack_next;
    verif_next = 0;
    verif_prev = 0;
    while(stack_next->index != index && stack_prev->index != index)
    {
        stack_next = stack_next->next;
        if (stack_next->index != index )
            verif_next++;
        if (stack_prev->index != index )
            verif_prev++;
    }
    if(verif_prev < verif_next)
        return(0);
    else
        return(1);
}

void    order_nums(t_dlist **stack_b, t_dlist **stack_a)
{
    int len;
    int ind;
    int l;
    int saltarin;
    t_dlist *list;

    l = ft_len_dlist(*stack_b);
    ind = l-1;
    list = *stack_b;
    while(l--)
    {
        len = ft_len_dlist(list);
        saltarin = 0;
        while(list->index != ind)
        {
            list = list->next;
            saltarin ++;
        }
       if (list->index == ind && (saltarin / 2) < (len / 2))
       {
           while(saltarin --)
           {
               rotate(stack_b, 'b');
               
           }
       }
       else if (list->index == ind && saltarin / 2 >= len / 2)
       {
            saltarin = ft_len_dlist(*stack_b)-saltarin;
           while(saltarin --)
               reverse_rotate(stack_b, 'b');
       }
       push_x(stack_a, stack_b, 'a');
        if(*stack_b)
            list = *stack_b;
       ind --;
    }
}

void algorithm(t_dlist **stack_a, t_dlist **stack_b)
{
    int len;

    len = ft_len_dlist(*stack_a);
    put_indice(*stack_a);
    if(len <= 5)
        select_algorithm(stack_a, stack_b);
    else
    {
        push_20(stack_a, stack_b);
        order_nums(stack_b, stack_a);
    }
    
}

