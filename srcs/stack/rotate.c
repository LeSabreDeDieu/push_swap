/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:44:53 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/09 22:45:00 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_stack(t_stack *stack)
{
	t_node	*last;

	if (stack->size <= 1)
		return ;
	last = stack->tail;
	last->prev->next = NULL;
	last->next = stack->head;
	stack->tail = last->prev;
	last->prev = NULL;
	stack->head->prev = last;
	stack->head = last;
	init_pos(stack);
}

void	rotate_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*next;

	if (stack->size <= 1)
		return ;
	last = stack->tail;
	next = stack->head->next;
	last->next = stack->head;
	stack->tail = last->next;
	next->prev = NULL;
	stack->head->prev = last;
	stack->head->next = NULL;
	stack->head = next;
	init_pos(stack);
}
