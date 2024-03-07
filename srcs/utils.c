/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:19:55 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/07 10:52:41 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	tab_size(int *tab)
{
	size_t	size;

	size = 0;
	while (tab[size++])
		;
	return (size);
}

bool	is_in_tab(int *tab, int val)
{
	size_t	i;

	if (tab == NULL)
		return (false);
	i = 0;
	while (tab[i])
	{
		if (tab[i] == val)
			return (true);
		i++;
	}
	return (false);
}
