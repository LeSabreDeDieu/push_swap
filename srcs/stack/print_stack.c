/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:19:32 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/26 15:53:17 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack->head == NULL)
		ft_printf("***********************\nStack %c: \n\t(null)\n",
			stack->name);
	else
	{
		current = stack->head;
		ft_printf("***********************\nStack %c: \n", stack->name);
		while (current)
		{
			ft_printf("\t[%d] ", current->current_pos);
			ft_printf("\t%d ", current->value);
			ft_printf("| cost : %d ", current->cost);
			if (current->target_node)
				ft_printf("| target : %d \n", current->target_node->value);
			else
				ft_printf("\n");
			current = current->next;
		}
	}
	ft_printf("***********************\n");
}
