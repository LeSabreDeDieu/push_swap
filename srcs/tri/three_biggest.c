/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_biggest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:46:40 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/08 14:05:49 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_three_biggest(int tab[3], t_stack *a)
{
	t_node	*current;

	current = a->head->next;
	tab[0] = a->head->value;
	tab[1] = INT_MIN;
	tab[2] = INT_MIN;
	while (current != NULL)
	{
		if (current->value > tab[0])
		{
			tab[2] = tab[1];
			tab[1] = tab[0];
			tab[0] = current->value;
		}
		else if (current->value > tab[1])
		{
			tab[2] = tab[1];
			tab[1] = current->value;
		}
		else if (current->value > tab[2])
			tab[2] = current->value;
		current = current->next;
	}
}

bool	check_three_biggest(int tab[3], int value)
{
	return (tab[0] == value || tab[1] == value || tab[2] == value);
}
