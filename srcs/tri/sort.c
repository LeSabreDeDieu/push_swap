/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:54:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/07 13:30:20 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moov_node_ascend(t_stack *src, t_stack *dest, t_node *node)
{
	while (src->head != node && dest->head != node->target_node
		&& node->top_of_med == node->target_node->top_of_med
		&& node->cost-- > 1)
	{
		if (node->top_of_med && node->target_node->top_of_med)
			rotate(dest, src, 'r');
		else if (!(node->top_of_med || node->target_node->top_of_med))
			rev_rotate(dest, src, 'r');
	}
	while (src->head != node && node->cost-- > 1)
	{
		if (node->top_of_med)
			rotate(dest, src, src->name);
		else if (!(node->top_of_med))
			rev_rotate(dest, src, src->name);
	}
	while (dest->head != node->target_node && node->cost-- > 1)
	{
		if (node->target_node->top_of_med)
			rotate(dest, src, dest->name);
		else if (!(node->target_node->top_of_med))
			rev_rotate(dest, src, dest->name);
	}
}

void	moov_node_descend(t_stack *src, t_stack *dest, t_node *node)
{
	while (src->head != node && dest->head != node->target_node
		&& node->top_of_med == node->target_node->top_of_med
		&& node->cost-- > 1)
	{
		if (node->top_of_med && node->target_node->top_of_med)
			rotate(src, dest, 'r');
		else if (!(node->top_of_med || node->target_node->top_of_med))
			rev_rotate(src, dest, 'r');
	}
	while (src->head != node && node->cost-- > 1)
	{
		if (node->top_of_med)
			rotate(src, dest, src->name);
		else if (!(node->top_of_med))
			rev_rotate(src, dest, src->name);
	}
	while (dest->head != node->target_node && node->cost-- > 1)
	{
		if (node->target_node->top_of_med)
			rotate(src, dest, dest->name);
		else if (!(node->target_node->top_of_med))
			rev_rotate(src, dest, dest->name);
	}
}

t_node	*find_lowest_cost(t_stack *stack)
{
	t_node	*current;
	t_node	*lowest_cost_node;
	int		lowest_cost;

	current = stack->head;
	lowest_cost = INT_MAX;
	while (current)
	{
		if (current->cost <= 2)
			return (current);
		else if (current->cost < lowest_cost)
		{
			lowest_cost_node = current;
			lowest_cost = current->cost;
		}
		current = current->next;
	}
	return (lowest_cost_node);
}

void	traitment(t_stack *a, t_stack *b)
{
	t_node	*lowest;

	while (a->size > 3)
	{
		reset_cost(a);
		set_cost(a, b, false);
		lowest = find_lowest_cost(a);
		if (lowest != b->head && lowest != b->tail)
			moov_node_descend(a, b, lowest);
		push(a, b, b->name);
	}
	short_sort(a);
	while (b->head)
	{
		reset_cost(b);
		set_cost(b, a, true);
		lowest = find_lowest_cost(b);
		if (lowest != a->head && lowest != a->tail)
			moov_node_ascend(b, a, lowest);
		push(a, b, a->name);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	push(a, b, b->name);
	push(a, b, b->name);
	traitment(a, b);
	while (!is_sorted_ascending(a))
	{
		if (node_max(a)->top_of_med)
			rotate(a, b, 'a');
		else
			rev_rotate(a, b, 'a');
	}
}
