/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:12:07 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/07 17:01:13 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_in_tab(int *tab, int size, int val)
{
	int	i;

	if (tab == NULL)
		return (false);
	i = 0;
	while (i < size)
	{
		if (tab[i] == val)
			return (true);
		else
			return (tab[i] = val, false);
		i++;
	}
	return (false);
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

int	verifie_double(char **argv, int argc)
{
	int		*tab;
	size_t	i;

	i = 0;
	tab = ft_calloc(argc, sizeof(int));
	while (tab[i])
	{
		if (is_in_tab(tab, argc, atoi(argv[i])))
			return (free(tab), true);
		i++;
	}
	return (free(tab), false);
}

char	**parse_string(int argc, char **argv)
{
	if (argc == 1)
	{
		argv = ft_split(*argv, ' ');
		if (!argv)
			tab_str_error(argv);
		argc = 0;
		while (argv[argc++])
			;
	}
	is_all_num(argv);
	if (verifie_double(argv, argc))
		error(TYPE_ERROR);
	return (argv);
}
