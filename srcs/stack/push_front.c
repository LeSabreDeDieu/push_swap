/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:48:41 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/22 11:32:09 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *src, t_stack *dest)
{
	t_node	*next_src;
	t_node	*head_dest;

	if (dest->head == NULL)
	{
		dest->head = src->head;
		dest->tail = src->head;
		src->head = src->head->next;
		dest->head->next = NULL;
		src->head->prev = NULL;
		dest->size = 1;
		--src->size;
		return ;
	}
	next_src = src->head->next;
	head_dest = dest->head;
	dest->head = src->head;
	dest->head->next = head_dest;
	head_dest->prev = dest->head;
	src->head = next_src;
	if (src->head != NULL)
		src->head->prev = NULL;
	++dest->size;
	--src->size;
}
