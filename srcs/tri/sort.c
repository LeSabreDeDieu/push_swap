/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:54:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/14 12:57:54 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	moov_node(t_stack *src, t_stack *dest, t_node *node)
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

static void	traitment(t_stack *a, t_stack *b, int tab[3])
{
	t_node	*lowest;

	while (a->size > 3)
	{
		lowest = find_lowest_cost(a, b, tab);
		if (lowest != b->head && lowest != b->tail)
			moov_node(a, b, lowest);
		push(a, b, b->name);
	}
	while (b->head && !is_sorted_descending(b))
	{
		if (max_of_stack(b)->top_of_med)
			rotate(a, b, 'b');
		else
			rev_rotate(a, b, 'b');
	}
	short_sort(a);
	while (b->head)
		push(a, b, a->name);
}

void	sort(t_stack *a, t_stack *b)
{
	size_t	i;
	int		three_biggest[3];

	i = 0;
	get_three_biggest(three_biggest, a);
	while (a->size > 3 && i < 2)
	{
		if (check_three_biggest(three_biggest, a->head->value))
		{
			rotate(a, b, a->name);
			continue ;
		}
		push(a, b, b->name);
		i++;
	}
	traitment(a, b, three_biggest);
}
