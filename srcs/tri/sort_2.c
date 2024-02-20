/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:54:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/07 16:23:38 by sgabsi           ###   ########.fr       */
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

t_node	*cost_min_max(t_node *node, t_stack *src, t_stack *dest)
{
	if (node->value > max_of_stack(dest))
		if (cost_calc(src, dest, src->head, node_max(dest)) == 2)
			return (node);
	if (node->value < min_of_stack(dest))
		if (cost_calc(src, dest, src->head, node_min(dest)) == 2)
			return (node);
	return (NULL);
}

t_node	*find_lowest_cost(t_stack *src, t_stack *dest)
{
	t_node	*current_src;
	t_node	*current_dest;
	t_node	*lowest_node;
	int		lowest_cost;

	current_src = src->head;
	lowest_cost = src->size;
	while (current_src)
	{
		if (cost_min_max(current_src, src, dest))
			return (cost_min_max(current_src, src, dest));
		current_dest = dest->head;
		while (current_dest)
		{
			if (current_src->value > current_dest->value)
			{
				if (cost_calc(src, dest, current_src, current_dest) <= 2)
				{
					current_src->target_node = current_dest;
					return (current_src->cost = 2, current_src);
				}
				if (cost_calc(src, dest, current_src,
						current_dest) < lowest_cost)
				{
					lowest_cost = cost_calc(src, dest, current_src,
							current_dest);
					lowest_node = current_dest;
					current_src->cost = lowest_cost;
					current_src->target_node = current_dest;
				}
				else
				{
					lowest_cost = cost_calc(src, dest, current_src,
							current_dest);
					lowest_node = current_dest;
					current_src->cost = lowest_cost;
					current_src->target_node = current_dest;
				}
			}
			current_dest = current_dest->next;
		}
		current_src = current_src->next;
	}
	return (lowest_node);
}

void	moov_node(t_stack *src, t_stack *dest, t_node *node)
{
	size_t	nb_moov;

	nb_moov = (size_t)node->cost;
	while (nb_moov && src->head != node && dest->head != node->target_node)
	{
		if (node->top_of_med && node->target_node->top_of_med)
			rotate(src, dest, 'r');
		else
			rev_rotate(src, dest, 'r');
		--nb_moov;
	}
	while (nb_moov && src->head != node)
	{
		if (node->top_of_med)
			rotate(src, dest, src->name);
		else
			rev_rotate(src, dest, src->name);
		--nb_moov;
	}
	while (nb_moov && dest->head != node->target_node)
	{
		if (node->target_node->top_of_med)
			rotate(src, dest, dest->name);
		else
			rev_rotate(src, dest, dest->name);
		--nb_moov;
	}
}

void	sort(t_stack *a, t_stack *b)
{
	push(a, b, b->name);
	push(a, b, b->name);
	while (a->size > 3)
	{
		moov_node(a, b, find_lowest_cost(a, b));
		push(a, b, b->name);
	}
	short_sort(a);
}
