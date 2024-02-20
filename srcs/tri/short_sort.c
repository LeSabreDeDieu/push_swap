/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:35:01 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/07 15:42:52 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack *stack)
{
	int	max;
	int	size;

	max = max_of_stack(stack);
	size = stack->size;
	if (stack->head->value == max && size > 2)
		rotate(stack, NULL, 'a');
	else if (stack->head->next->value == max && size > 2)
		rev_rotate(stack, NULL, 'a');
	if (stack->head->value > stack->head->next->value)
		swap(stack, NULL, 'a');
}
