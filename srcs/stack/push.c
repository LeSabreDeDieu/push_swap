/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:28:35 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/02 16:18:39 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *src, t_stack *dest)
{
	if (!src->head)
		return ;
	if (dest->max == NULL || dest->min == NULL)
	{
		dest->max = src->head;
		dest->min = src->head;
	}
	else
	{
		if (src->head->value < dest->min->value)
			dest->min = src->head;
		if (src->head->value > dest->max->value)
			dest->max = src->head;
	}
	push_front(src, dest);
	src->min = min_of_stack(src);
	src->max = max_of_stack(src);
	init_pos(src);
	init_pos(dest);
}
