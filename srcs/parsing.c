/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:12:07 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/08 15:43:56 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	static int	nombre_occurrences[1000] = {0};
	int			i;
	int			nombre;
	int			j;

	i = 0;
	while (tab[i] != NULL)
	{
		nombre = ft_atoi(tab[i]);
		nombre_occurrences[nombre]++;
		i++;
	}
	j = 0;
	while (j < 1000)
	{
		if (nombre_occurrences[j] > 1)
		{
			return (1);
		}
		j++;
	}
	return (0);
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
