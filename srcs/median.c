/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:14 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/26 11:34:23 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_insertion(int sous_tableau[], int taille)
{
	int	i;
	int	cle;
	int	j;

	i = 1;
	while (i < taille)
	{
		cle = sous_tableau[i];
		j = i - 1;
		while (j >= 0 && sous_tableau[j] > cle)
		{
			sous_tableau[j + 1] = sous_tableau[j];
			j = j - 1;
		}
		sous_tableau[j + 1] = cle;
		i++;
	}
}

int	mediane_sous_tableau(int sous_tableau[], int taille)
{
	tri_insertion(sous_tableau, taille);
	return (sous_tableau[taille / 2]);
}

int	*calcul_medianes(int tableau[], int taille, int *num_sous_tableaux)
{
	int	*medianes;
	int	i;
	int	debut;
	int	fin;

	*num_sous_tableaux = (taille + 4) / 5;
	medianes = (int *)malloc(*num_sous_tableaux * sizeof(int));
	i = 0;
	debut = 0;
	while (i < *num_sous_tableaux)
	{
		fin = debut + 5;
		if (fin > taille)
		{
			fin = taille;
		}
		medianes[i] = mediane_sous_tableau(&tableau[debut], fin - debut);
		debut = fin;
		i++;
	}
	return (medianes);
}

int	*stack_to_tab(t_stack *stack)
{
	int		*tab;
	int		i;
	t_node	*current;

	tab = (int *)ft_calloc(stack->size, sizeof(int));
	if (!tab)
		tab_int_error(tab);
	current = stack->head;
	i = 0;
	while (current)
	{
		tab[i++] = current->value;
		current = current->next;
	}
	return (tab);
}

int	mediane_des_medianes(int *tableau, int taille)
{
	int	num_sous_tableaux;
	int	*medianes;
	int	mediane;

	if (taille <= 5)
	{
		return (mediane_sous_tableau(tableau, taille));
	}
	else
	{
		medianes = calcul_medianes(tableau, taille, &num_sous_tableaux);
		mediane = mediane_des_medianes(medianes, num_sous_tableaux);
		free(medianes);
		return (mediane);
	}
	free(tableau);
}
