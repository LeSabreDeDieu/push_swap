/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:12:07 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/19 08:46:34 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_all_num(char **tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (!ft_isdigit(tab[i][0]) && !(tab[i][0] == '-' || tab[i][0] == '+'))
			error(TYPE_ERROR);
		if (tab[i][0] == '-')
			j++;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				error(TYPE_ERROR);
			if (ft_isdigit(tab[i][j]) && !ft_isdigit(tab[i][j + 1]) && tab[i][j
				+ 1] != '\0')
				error(TYPE_ERROR);
			j++;
		}
		i++;
	}
}

static int	verifie_double(int *tab, int argc)
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

static int	check_overflow(const char *str, int *val)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		if (sign * num > INT_MAX || sign * num < INT_MIN)
			return (1);
		i++;
	}
	*val = (int) num;
	if (sign < 0)
		(*val) *= sign;
	return (0);
}

static void	check(char **tab_char, int size, int **tab_int)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	is_all_num(tab_char);
	(*tab_int) = ft_calloc(size, sizeof(int));
	while (i < size)
	{
		if (check_overflow(tab_char[i], &num) == 1)
			(free((*tab_int)), error(INT_OVERFLOW));
		(*tab_int)[i] = num;
		i++;
	}
	if (verifie_double((*tab_int), size))
		(free((*tab_int)), error(TYPE_ERROR));
}

t_array	parse_string(int argc, char **argv)
{
	t_array	parse;
	char	**tab;

	parse.tab = NULL;
	tab = NULL;
	if (argc == 1)
	{
		parse.size = 0;
		tab = ft_split(*argv, ' ');
		if (!tab)
			tab_str_error(argv);
		while (tab[parse.size])
			parse.size++;
	}
	else
		parse.size = argc;
	check(tab, parse.size, &(parse.tab));
	return (parse);
}
