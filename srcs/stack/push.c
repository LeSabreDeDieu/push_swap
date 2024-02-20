/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:28:35 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/07 16:00:03 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *src, t_stack *dest)
{
	t_node	*tmp;

	if (!src)
		return ;
	push_front(dest, new_node(src->head->value));
	if (src->head->next == NULL)
		tmp = NULL;
	else
		tmp = src->head->next;
	free(src->head);
	src->head = tmp;
	src->size--;
	init_pos(src);
	init_pos(dest);
}
