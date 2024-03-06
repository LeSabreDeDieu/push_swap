/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:54:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/27 16:36:30 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moov_node(t_stack *src, t_stack *dest, t_node *node)
{
	while (node->cost > 1 && src->head != node
		&& dest->head != node->target_node)
	{
		if (node->top_of_med && node->target_node->top_of_med)
			rotate(src, dest, 'r');
		else if (!(node->top_of_med && node->target_node->top_of_med))
			rev_rotate(src, dest, 'r');
		--node->cost;
	}
	while (node->cost > 1 && src->head != node)
	{
		if (node->top_of_med)
			rotate(src, dest, src->name);
		else if (!(node->top_of_med))
			rev_rotate(src, dest, src->name);
		--node->cost;
	}
	while (node->cost > 1 && dest->head != node->target_node)
	{
		if (node->target_node->top_of_med)
			rotate(src, dest, dest->name);
		else if (!(node->target_node->top_of_med))
			rev_rotate(src, dest, dest->name);
		--node->cost;
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
		else if (current->cost <= lowest_cost)
		{
			lowest_cost_node = current;
			lowest_cost = current->cost;
		}
		current = current->next;
	}
	return (lowest_cost_node);
}

void	sort(t_stack *a, t_stack *b)
{
	t_node	*lowest;

	push(a, b, b->name);
	push(a, b, b->name);
	while (a->size > 3)
	{
		set_cost(a, b, false);
		lowest = find_lowest_cost(a);
		if (lowest != b->head && lowest != b->tail)
			moov_node(a, b, lowest);
		push(a, b, b->name);
	}
	short_sort(a);
	/*while (b->head)
	{
		set_cost(b, a, true);
		lowest = find_lowest_cost(a);
		if (lowest != b->head && lowest != b->tail)
			moov_node(b, a, lowest);
		push(a, b, a->name);
	}*/
}
