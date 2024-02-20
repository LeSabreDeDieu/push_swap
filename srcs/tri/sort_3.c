/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:44:23 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/09 23:05:33 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_three_biggest(t_stack *stack)
{
	int		*tab;
	t_node	*current;

	tab = (int *)ft_calloc(3, sizeof(int));
	tab[0] = min_of_stack(stack);
	tab[1] = tab[0];
	current = stack->head;
	while (current)
	{
		if (current->value > tab[0])
		{
			tab[2] = tab[1];
			tab[1] = tab[0];
			tab[0] = current->value;
		}
		if (current->value > tab[1] && current->value != tab[0])
		{
			tab[2] = tab[1];
			tab[1] = current->value;
		}
		if (current->value > tab[2] && current->value != tab[1])
			tab[2] = current->value;
		current = current->next;
	}
	return (tab);
}

bool	is_in_list(int value, int *tab)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (tab[i++] == value)
			return (true);
	}
	return (false);
}

void	insert_val(t_stack *src, t_stack *dest)
{
	t_node *current;

	if (src->head->value < dest->tail->value)
	{
		rev_rotate(src, dest, dest->name);
		push(src, dest, dest->name);
	}
	else if (src->head->value > dest->head->value)
	{
		push(src, dest, dest->name);
	}
	else
	{
		current = dest->head;
		if (src->head->value < current->value &&
			src->head->value > current->next->value)
		{
			(rotate(src, dest, dest->name), push(src, dest, dest->name));
		}
		else
			rotate(src, dest, dest->name);
		while (!is_sorted_descending(dest))
		{
			rotate(src, dest, dest->name);
		}
		current = current->next;
	}
}

void	insert_sort(t_stack *src, t_stack *dest)
{
	int min;
	int max;

	if (dest->head == NULL)
		return (push(src, dest, dest->name));
	min = min_of_stack(dest);
	max = max_of_stack(dest);
	if (src->head->value < min)
	{
		push(src, dest, dest->name); 
		rotate(src, dest, dest->name);
	}
	else if (src->head->value > max)
		push(src, dest, dest->name);
	else
		insert_val(src, dest);
}

void	sort(t_stack *a, t_stack *b)
{
	int *max_values;

	max_values = get_three_biggest(a);
	while (a->size > 3)
	{
		if (!is_in_list(a->head->value, max_values))
			insert_sort(a, b);
		else
			rotate(a, b, 'a');
	}
	short_sort(a);
	while (b->head)
		push(a, b, a->name);
	free(max_values);
}
