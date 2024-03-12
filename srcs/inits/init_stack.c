/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:08:52 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/11 11:34:18 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_stack(t_stack *stack, int *tab, int size, char c)
{
	int	i;

	stack->name = c;
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = size;
	if (tab == NULL || size == 0)
		return ;
	i = 0;
	while (i < size)
		push_back(stack, new_node(tab[i++]));
	init_pos(stack);
}
