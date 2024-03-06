/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:34:22 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/06 13:38:38 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_cost(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		current->cost = 0;
		current = current->next;
	}
}
