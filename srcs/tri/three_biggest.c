/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_biggest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:44:23 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/26 16:20:01 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_three_biggest(t_stack *stack)
{
	int		*tab;
	t_node	*current;

	tab = (int *)ft_calloc(3, sizeof(int));
	tab[0] = min_of_stack(stack);
	tab[1] = tab[0];
	current = stack->head;
	while (current)
	{
		if (current->value > tab[0])
		{
			tab[2] = tab[1];
			tab[1] = tab[0];
			tab[0] = current->value;
		}
		if (current->value > tab[1] && current->value != tab[0])
		{
			tab[2] = tab[1];
			tab[1] = current->value;
		}
		if (current->value > tab[2] && current->value != tab[1])
			tab[2] = current->value;
		current = current->next;
	}
	return (tab);
}

bool	is_in_list(int value, int *tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (tab[i++] == value)
			return (true);
	}
	return (false);
}
