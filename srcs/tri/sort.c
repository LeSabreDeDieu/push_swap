/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:49:14 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/02 16:28:02 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	moov_node(t_stack *a, t_stack *b, t_node *node)
{
	while (b->head != node && a->head != node->target_node
		&& node->top_of_med == node->target_node->top_of_med
		&& node->cost-- > 1)
	{
		if (node->top_of_med && node->target_node->top_of_med)
			rotate(a, b, 'r');
		else if (!(node->top_of_med || node->target_node->top_of_med))
			rev_rotate(a, b, 'r');
	}
	while (b->head != node && node->cost-- > 1)
	{
		if (node->top_of_med)
			rotate(a, b, 'b');
		else if (!(node->top_of_med))
			rev_rotate(a, b, 'b');
	}
	while (a->head != node->target_node && node->cost-- > 1)
	{
		if (node->target_node->top_of_med)
			rotate(a, b, 'a');
		else if (!(node->target_node->top_of_med))
			rev_rotate(a, b, 'a');
	}
}

void	sort(t_stack *a, t_stack *b)
{
	t_node	*lowest;

	create_chunk(a, b);
	short_sort(a);
	a->min = min_of_stack(a);
	a->max = max_of_stack(a);
	while (b->head)
	{
		lowest = find_lowest_cost(b, a);
		if (lowest != a->head && lowest != a->tail)
			moov_node(a, b, lowest);
		push(a, b, 'a');
	}
	while (a->head != a->min)
	{
		if (a->min->top_of_med)
			rotate(a, b, 'a');
		else
			rev_rotate(a, b, 'a');
	}
}
