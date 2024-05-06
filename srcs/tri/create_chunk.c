/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:17:19 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/02 17:04:06 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_chunk(t_stack *stack_a, t_stack *stack_b)
{
	int	palier;
	int	nb_elem;

	palier = 100;
	nb_elem = 0;
	if (stack_a->size > 100)
		palier = 100;
	while (stack_a->size > 3)
	{
		if (stack_a->head->value < palier * ((stack_a->min->value / palier)
				+ 1))
		{
			push(stack_a, stack_b, 'b');
			nb_elem++;
			if (((stack_a->min->value / palier) + 1) % 2 == 0)
				rotate(stack_a, stack_b, 'b');
		}
		else
			rotate(stack_a, stack_b, 'a');
		if (nb_elem == palier)
			nb_elem = 0;
		if (nb_elem == palier - 1)
			nb_elem = 0;
	}
}
