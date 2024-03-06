/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:44:42 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/26 11:34:02 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_of_stack(t_stack *stack)
{
	int		min;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (INT_MIN);
	current = stack->head;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	max_of_stack(t_stack *stack)
{
	int		max;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (INT_MAX);
	current = stack->head;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

bool	is_new_min_max(int value, t_stack *stack)
{
	if (value < min_of_stack(stack)
		|| value > max_of_stack(stack))
		return (true);
	return (false);
}

t_node	*node_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	current = stack->head;
	min = NULL;
	while (current)
	{
		if (current->value == min_of_stack(stack))
		{
			min = current;
			break ;
		}
		current = current->next;
	}
	return (min);
}

t_node	*node_max(t_stack *stack)
{
	t_node	*current;
	t_node	*max;

	current = stack->head;
	max = NULL;
	while (current)
	{
		if (current->value == max_of_stack(stack))
		{
			max = current;
			break ;
		}
		current = current->next;
	}
	return (max);
}
