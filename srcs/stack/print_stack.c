/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:19:32 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/02 10:36:14 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char c)
{
	t_node	*current;

	if (stack->head == NULL)
		ft_printf("***********************\nStack %c: \n\t(null)\n",
			c);
	else
	{
		current = stack->head;
		ft_printf("***********************\nStack %c: \n", c);
		while (current)
		{
			ft_printf("\t[%d] ", current->current_pos);
			ft_printf("\t%d ", current->value);
			ft_printf("\t| cost : %d ", current->cost);
			if (current->target_node)
				ft_printf("| target : %d \n", current->target_node->value);
			else
				ft_printf("\n");
			current = current->next;
		}
	}
	ft_printf("***********************\n");
}
