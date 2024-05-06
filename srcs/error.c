/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:24:04 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/03 08:41:09 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int erreur)
{
	(void) erreur;
	ft_putstr_fd("Error\n", 2);
	exit(FAILURE);
}

void	free_str_tab(char **tab, int argc)
{
	size_t	i;

	if (argc == 1)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

void	free_int_tab(int *tab)
{
	free(tab);
}

void	free_all_tabs(char **str, int *tab, int argc)
{
	free_int_tab(tab);
	free_str_tab(str, argc);
}
