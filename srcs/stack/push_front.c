/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:48:41 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/07 15:17:49 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *stack, t_node *new)
{
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
		stack->size = 1;
		return ;
	}
	new->next = stack->head;
	stack->head->prev = new;
	stack->head = new;
	stack->size++;
}
