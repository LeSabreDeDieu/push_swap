/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:05:59 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/02 17:34:30 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_calc(t_stack *src, t_stack *dest, t_node *node, t_node *target_node)
{
	size_t	cost;

	cost = 0;
	if (node->top_of_med)
		cost += node->current_pos;
	else
		cost += src->size - node->current_pos;
	if (target_node->top_of_med)
		cost += target_node->current_pos;
	else
		cost += dest->size - target_node->current_pos;
	return (cost + 1);
}

void	set_cost_min_max(t_stack *src, t_stack *dest, t_node *current_src)
{
	t_node	*min;

	min = min_of_stack(dest);
	current_src->cost = cost_calc(src, dest, current_src, min);
	current_src->target_node = min;
}

void	set_cost_target(t_stack *src, t_stack *dest,
		t_node *current_src, t_node *current_dest)
{
	if (current_src->cost > 2)
	{
		if (current_src->value < current_dest->next->value
			&& current_src->value > current_dest->value)
		{
			current_src->cost = cost_calc(src, dest, current_src,
					current_dest->next);
			current_src->target_node = current_dest->next;
		}
		else if (current_src->value > dest->tail->value
			&& current_src->value < dest->head->value)
		{
			current_src->cost = cost_calc(src, dest, current_src,
					dest->head);
			current_src->target_node = dest->head;
		}
	}
}

int	calculate_cost(t_stack *src, t_stack *dest, t_node *current_src)
{
	int			lowest_cost;
	t_node		*current_dest;

	if (current_src->cost != INT_MAX)
		return (current_src->cost);
	lowest_cost = INT_MAX;
	current_dest = dest->head;
	while (current_dest && current_dest->next)
	{
		if (is_new_min_max(current_src->value, dest))
		{
			set_cost_min_max(src, dest, current_src);
			return (current_src->cost = current_src->cost, current_src->cost);
		}
		set_cost_target(src, dest, current_src, current_dest);
		if (current_src->cost <= 2)
			return (current_src->cost = current_src->cost, current_src->cost);
		if (current_src->cost < lowest_cost)
			lowest_cost = current_src->cost;
		current_dest = current_dest->next;
	}
	current_src->cost = lowest_cost;
	return (lowest_cost);
}

t_node	*find_lowest_cost(t_stack *src, t_stack *dest)
{
	t_node	*current_src;
	t_node	*lowest_cost_node;
	int		lowest_cost;
	int		current_cost;

	current_src = src->head;
	lowest_cost_node = NULL;
	lowest_cost = INT_MAX;
	while (current_src)
	{
		current_src->cost = INT_MAX;
		current_cost = calculate_cost(src, dest, current_src);
		if (current_cost < lowest_cost)
		{
			lowest_cost = current_cost;
			lowest_cost_node = current_src;
		}
		current_src = current_src->next;
	}
	return (lowest_cost_node);
}
