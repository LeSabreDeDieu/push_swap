/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:05:59 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/06 14:40:46 by sgabsi           ###   ########.fr       */
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

void	set_cost_min_max(t_stack *src, t_stack *dest, t_node *current_src,
		bool ascend)
{
	if (current_src->value > max_of_stack(dest) && !ascend)
	{
		current_src->cost = cost_calc(src, dest, current_src, node_max(dest));
		current_src->target_node = node_max(dest);
	}
	else if (current_src->value < min_of_stack(dest) && !ascend)
	{
		current_src->cost = cost_calc(src, dest, current_src, node_max(dest));
		current_src->target_node = node_max(dest);
	}
	else if (current_src->value > max_of_stack(dest) && ascend)
	{
		current_src->cost = cost_calc(src, dest, current_src, node_max(dest));
		current_src->target_node = node_min(dest);
	}
	else if (current_src->value < min_of_stack(dest) && ascend)
	{
		current_src->cost = cost_calc(src, dest, current_src, node_min(dest));
		current_src->target_node = node_min(dest);
	}
}

void	set_cost_target_ascend(t_stack *src, t_stack *dest, t_node *current_src,
		t_node *current_dest)
{
	if (current_src->cost > 2 || current_src->cost == 0)
	{
		if (current_src->value < dest->head->value
			&& current_src->value > dest->tail->value)
		{
			current_src->cost = cost_calc(src, dest, current_src, dest->head);
			current_src->target_node = dest->head;
		}
		else if (current_src->value < current_dest->next->value
			&& current_src->value > current_dest->value)
		{
			current_src->cost = cost_calc(src, dest, current_src,
					current_dest->next);
			current_src->target_node = current_dest->next;
		}
	}
}

void	set_cost_target_descend(t_stack *src, t_stack *dest,
		t_node *current_src, t_node *current_dest)
{
	if (current_src->cost > 2 || current_src->cost == 0)
	{
		if (current_src->value > dest->head->value
			&& current_src->value < dest->tail->value)
		{
			current_src->cost = cost_calc(src, dest, current_src, dest->head);
			current_src->target_node = dest->head;
		}
		else if (current_src->value > current_dest->next->value
			&& current_src->value < current_dest->value)
		{
			current_src->cost = cost_calc(src, dest, current_src,
					current_dest->next);
			current_src->target_node = current_dest->next;
		}
	}
}

void	set_cost(t_stack *src, t_stack *dest, bool ascend)
{
	t_node	*current_src;
	t_node	*current_dest;

	current_src = src->head;
	while (current_src)
	{
		current_dest = dest->head;
		while (current_dest && current_dest->next)
		{
			if (is_new_min_max(current_src->value, dest))
			{
				set_cost_min_max(src, dest, current_src, ascend);
				break ;
			}
			if (ascend)
				set_cost_target_ascend(src, dest, current_src, current_dest);
			else
				set_cost_target_descend(src, dest, current_src, current_dest);
			current_dest = current_dest->next;
		}
		current_src = current_src->next;
	}
}
