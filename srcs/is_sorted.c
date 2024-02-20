/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:43:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/07 13:18:31 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted_ascending(t_stack *stack)
{
	t_node	*current;

	current = stack->head->next;
	while (current)
	{
		if (current->prev->value > current->value)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	is_sorted_descending(t_stack *stack)
{
	t_node	*current;

	current = stack->head->next;
	while (current)
	{
		if (current->prev->value < current->value)
			return (false);
		current = current->next;
	}
	return (true);
}
