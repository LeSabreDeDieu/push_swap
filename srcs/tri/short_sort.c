/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:35:01 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/26 15:14:57 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack *stack)
{
	int	max;
	int	size;

	max = max_of_stack(stack);
	size = stack->size;
	if (stack->head->value == max && size > 2)
		rotate(stack, NULL, 'a');
	else if (stack->head->next->value == max && size > 2)
		rev_rotate(stack, NULL, 'a');
	if (stack->head->value > stack->head->next->value)
		swap(stack, NULL, 'a');
}

void	insert_min_max(t_stack *a, t_stack *b)
{
	int	temp;
	int	temp_max;

	temp = b->head->value;
	temp_max = max_of_stack(a);
	while (!is_sorted_ascending(a))
		rotate(a, b, a->name);
	push(a, b, 'a');
	if (temp > temp_max)
		rotate(a, b, 'a');
}

void	short_sort_five(t_stack *a, t_stack *b)
{
	size_t	nb_push;

	nb_push = 2;
	while (a->size > 3)
	{
		push(a, b, b->name);
	}
	short_sort(a);
	while (nb_push)
	{
		if (is_new_min_max(b->head->value, a))
			insert_min_max(a, b);
		else if (b->head->value < a->head->value)
			(push(a, b, 'a'), nb_push--);
		else
			rotate(a, b, 'a');
	}
	while (!is_sorted_ascending(a))
	{
		if (node_max(a)->top_of_med)
			rotate(a, b, 'a');
		else
			rev_rotate(a, b, 'a');
	}
}
