/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_link_circ_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:12:19 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/27 20:35:41 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_dlist(t_dlist **saltarina, int data)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
	{
		ft_clear_dlist(saltarina);
		return (1);
	}
	new->content = data;
	new->index = -1;
	new->prev = *saltarina;
	new->next = NULL;
	if (*saltarina != NULL)
	{
		(*saltarina)->next = new;
	}
	*saltarina = new ;
	return (0);
}

void	ft_printf_dlist(t_dlist *list)
{
	t_dlist	*head;

	head = list;
	printf("\n\n\n");
	printf("content list == %d\n", list->content);
	list = list->next;
	while (list != head)
	{
		printf("content list == %d\n", list->content);
		list = list->next;
	}
}

int	ft_len_dlist(t_dlist *stack)
{
	int		len;
	t_dlist	*init;

	if (!stack)
		return (0);
	len = 1;
	init = stack;
	stack = stack->next;
	while (stack != init)
	{
		len ++;
		stack = stack->next;
	}
	return (len);
}

void	ft_printf_dlist_ind(t_dlist *list)
{
	t_dlist	*start;

	start = list;
	printf("ind list == %d\n", list->index);
	list = list->next;
	while (list->content != start->content)
	{
		printf("ind list  ==  %d\n", list->index);
		list = list->next;
	}
	printf("\n\n");
}

int	ft_clear_dlist(t_dlist **list)
{
	t_dlist	*aux;
	t_dlist	*next_aux;

	if (!*list)
		return (1);
	aux = *list;
	next_aux = (*list)->next;
	while (next_aux != *list)
	{
		free(aux);
		aux = next_aux;
		next_aux = aux->next;
	}
	free(aux);
	*list = NULL;
	return (0);
}
