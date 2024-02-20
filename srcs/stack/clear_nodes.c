/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:28:13 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/07 15:20:53 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_nodes(t_stack *stack)
{
	t_node		*current;
	t_node		*next;

	if (stack == NULL)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		current->next = NULL;
		current->prev = NULL;
		free(current);
		current = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
