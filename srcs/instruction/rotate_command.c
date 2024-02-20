/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:45:02 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/08 11:33:41 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *a, t_stack *b, char c)
{
	if (!(c == 'a' || c == 'b' || c == 'r'))
		return ;
	if (c == 'a' || c == 'r')
		rotate_stack(a);
	if (c == 'b' || c == 'r')
		rotate_stack(b);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	rev_rotate(t_stack *a, t_stack *b, char c)
{
	if (!(c == 'a' || c == 'b' || c == 'r'))
		return ;
	if (c == 'a' || c == 'r')
		rev_rotate_stack(a);
	if (c == 'b' || c == 'r')
		rev_rotate_stack(b);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}
