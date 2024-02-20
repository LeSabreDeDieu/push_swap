/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:24:04 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/08 15:44:40 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int erreur)
{
	write(2, "Error\n", 6);
	if (erreur == FAILURE)
		write(2, "Erreur inconnu\n", 15);
	if (erreur == MALLOC_ERROR)
		write(2, "Erreur de malloc\n", 17);
	if (erreur == TAB_ERROR)
		write(2, "Erreur lors de la creation du tableau\n", 38);
	if (erreur == TYPE_ERROR)
		write(2, "Erreur lors de la saisie\n", 25);
	exit(FAILURE);
}

void	tab_str_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	error(TAB_ERROR);
}

void	tab_int_error(int *tab)
{
	free(tab);
	error(TAB_ERROR);
}
