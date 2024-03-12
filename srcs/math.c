/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:44:42 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/08 14:40:01 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*min_of_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	current = stack->head;
	min_node = NULL;
	while (current)
	{
		if (!min_node || current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_node	*max_of_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	current = stack->head;
	max_node = NULL;
	while (current)
	{
		if (!max_node || current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

bool	is_new_min_max(int value, t_stack *stack)
{
	if (value < min_of_stack(stack)->value
		|| value > max_of_stack(stack)->value)
		return (true);
	return (false);
}
