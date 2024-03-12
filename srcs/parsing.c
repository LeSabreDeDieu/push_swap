/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:12:07 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/11 12:37:41 by sgabsi           ###   ########.fr       */
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
			if (!ft_isdigit(tab[i][j])
			&& tab[i][j] != '-'
			&& tab[i][j] != '+')
				error(TYPE_ERROR);
			j++;
		}
		i++;
	}
}

int	verifie_double(int *tab, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (tab[i] == tab[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	*parse_string(int argc, char **argv)
{
	int	*tab;
	int	i;

	if (argc == 1)
	{
		argv = ft_split(*argv, ' ');
		if (!argv)
			tab_str_error(argv);
		argc = 0;
		while (argv[argc])
			argc++;
	}
	i = 0;
	is_all_num(argv);
	tab = ft_calloc(argc, sizeof(int));
	while (i < argc)
	{
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	if (verifie_double(tab, argc))
		(free(tab), error(TYPE_ERROR));
	return (tab);
}
