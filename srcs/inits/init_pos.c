/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:28:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/14 12:02:15 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_top_of_med(t_stack *stack)
{
	int		med;
	t_node	*current;

	med = (stack->size / 2) + (stack->size % 2 != 0);
	current = stack->head;
	while (current)
	{
		if (current->current_pos < med)
			current->top_of_med = true;
		else
			current->top_of_med = false;
		current = current->next;
	}
}

static void	init_current_pos(t_stack *stack)
{
	size_t	index;
	t_node	*current;

	index = 0;
	current = stack->head;
	while (current)
	{
		current->current_pos = index;
		index++;
		current = current->next;
	}
}

void	init_pos(t_stack *stack)
{
	init_current_pos(stack);
	init_top_of_med(stack);
}
