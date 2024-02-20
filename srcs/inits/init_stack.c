/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:08:52 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/07 16:20:40 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, char *argv[], char c)
{
	stack->name = c;
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	if (argv == NULL || (*argv) == NULL)
		return ;
	while (*argv != NULL)
	{
		push_back(stack, new_node(ft_atoi(*argv)));
		argv++;
	}
	init_pos(stack);
}
