/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:35:01 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/08 15:41:31 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack *stack)
{
	t_node	*max;
	int		size;

	max = max_of_stack(stack);
	size = stack->size;
	if (stack->head->value == max->value && size > 2)
		rotate(stack, NULL, 'a');
	else if (stack->head->next->value == max->value && size > 2)
		rev_rotate(stack, NULL, 'a');
	if (stack->head->value > stack->head->next->value)
		swap(stack, NULL, 'a');
}

void	insert_min_max(t_stack *a, t_stack *b)
{
	int	temp;
	int	temp_max;

	temp = b->head->value;
	temp_max = max_of_stack(a)->value;
	while (!is_sorted_ascending(a))
		rotate(a, b, a->name);
	push(a, b, 'a');
	if (temp > temp_max)
		rotate(a, b, 'a');
}

void	short_sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		push(a, b, b->name);
	}
	short_sort(a);
	while (b->head)
	{
		if (is_new_min_max(b->head->value, a))
			insert_min_max(a, b);
		else if (b->head->value < a->head->value)
			push(a, b, 'a');
		else
			rotate(a, b, 'a');
	}
	while (!is_sorted_ascending(a))
	{
		if (max_of_stack(a)->top_of_med)
			rotate(a, b, 'a');
		else
			rev_rotate(a, b, 'a');
	}
}
