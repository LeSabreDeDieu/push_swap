/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:08:52 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/02 12:23:56 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_stack(t_stack *stack, int *tab, int size)
{
	int	i;

	stack->head = NULL;
	stack->tail = NULL;
	stack->max = NULL;
	stack->min = NULL;
	stack->size = size;
	if (tab == NULL || size == 0)
		return ;
	i = 0;
	while (i < size)
		push_back(stack, new_node(tab[i++]));
	stack->max = max_of_stack(stack);
	stack->min = min_of_stack(stack);
	init_pos(stack);
}
