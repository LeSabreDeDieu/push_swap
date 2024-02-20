/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:29 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/08 11:33:50 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a, t_stack *b, char c)
{
	if (!(c == 'a' || c == 'b' || c == 's'))
		return ;
	if (c == 'a' || c == 's')
		swap_stack(a);
	if (c == 'b' || c == 's')
		swap_stack(b);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}
