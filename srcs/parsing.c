/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:12:07 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/07 10:52:56 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_push_back(int *tab, int val)
{
	int		*temp_tab;
	size_t	i;

	if (tab == NULL)
	{
		temp_tab = ft_calloc(1, sizeof(int));
		if (!temp_tab)
			error(MALLOC_ERROR);
		temp_tab[0] = val;
	}
	else
	{
		i = 0;
		temp_tab = ft_calloc(tab_size(tab) + 1, sizeof(int));
		if (!temp_tab)
			error(MALLOC_ERROR);
		while (i < tab_size(tab))
		{
			temp_tab[i] = tab[i];
			i++;
		}
		free(tab);
		temp_tab[i] = val;
	}
	return (temp_tab);
}

void	is_all_num(char **tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				error(TYPE_ERROR);
			j++;
		}
		i++;
	}
}

int	verifie_double(char **tab)
{
	int		*tab_verif;
	size_t	i;

	tab_verif = NULL;
	i = 0;
	while (tab[i])
	{
		if (is_in_tab(tab_verif, atoi(tab[i])))
			return (free(tab_verif), true);
		else
			tab_verif = ft_push_back(tab_verif, atoi(tab[i]));
		i++;
	}
	return (free(tab_verif), false);
}

char	**parse_string(int argc, char **argv)
{
	if (argc == 2)
	{
		argv = ft_split(*argv, ' ');
		if (!argv)
			tab_str_error(argv);
	}
	is_all_num(argv);
	if (verifie_double(argv))
		error(TYPE_ERROR);
	return (argv);
}
