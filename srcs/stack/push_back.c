/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/07 15:17:41 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
		stack->size = 1;
		return ;
	}
	last = stack->tail;
	last->next = new;
	new->prev = last;
	stack->tail = new;
	stack->size++;
}
