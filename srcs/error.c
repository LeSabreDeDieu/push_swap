/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:24:04 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/19 08:25:44 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int erreur)
{
	ft_putstr_fd("Error\n", 2);
	(void) erreur;
	if (erreur == FAILURE)
		ft_putstr_fd("Erreur inconnu\n", 1);
	if (erreur == MALLOC_ERROR)
		ft_putstr_fd("Erreur de malloc\n", 1);
	if (erreur == TAB_ERROR)
		ft_putstr_fd("Erreur lors de la creation du tableau\n", 1);
	if (erreur == TYPE_ERROR)
		ft_putstr_fd("Erreur lors de la saisie\n", 1);
	if (erreur == INT_OVERFLOW)
		ft_putstr_fd("Erreur : un des nombre saisie depasse la valeur de INT\n",
			1);
	exit(FAILURE);
}

void	free_str_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	tab_str_error(char **tab)
{
	free_str_tab(tab);
	error(TAB_ERROR);
}

void	free_int_tab(int *tab)
{
	free(tab);
}

void	tab_int_error(int *tab)
{
	free_int_tab(tab);
	error(TAB_ERROR);
}
