/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:25:30 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/08 16:00:35 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_stack *a, t_stack *b)
{
	int size;
	int pivot;
	int i;

	if (is_sorted_ascending(a))
		return;
	size = a->size;
	pivot = mediane_des_medianes(stack_to_tab(a), size);
	i = 0;
	while (i < size)
	{
		if (a->head->value < pivot)
		{
			if (a->name == 'a')
				push(b, a, 'a');
			if (a->name == 'b')
				push(b, a, 'b');
		}
		else
		{
			if (a->name == 'a')
				rotate(b, a, 'a');
			if (a->name == 'b')
				rotate(b, a, 'b');
		}
		i++;
	}
	sort(a, b);
	sort(b, a);
	while (!(b->head))
	{
		if (b->name == 'a')
			push(b, a, 'a');
		if (b->name == 'b')
			push(b, a, 'b');
	}
}
