/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:12:07 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/14 11:59:25 by sgabsi           ###   ########.fr       */
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
	*val = num;
	return (0);
}

static void	check(char **argv, int argc, int **tab)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	is_all_num(argv);
	(*tab) = ft_calloc(argc, sizeof(int));
	while (i < argc)
	{
		if (check_overflow(argv[i], &num) == 1)
			(free((*tab)), error(INT_OVERFLOW));
		(*tab)[i] = num;
		i++;
	}
	if (verifie_double((*tab), argc))
		(free((*tab)), error(TYPE_ERROR));
}

int	*parse_string(int argc, char **argv)
{
	int	*tab;

	if (argc == 1)
	{
		argv = ft_split(*argv, ' ');
		if (!argv)
			tab_str_error(argv);
		argc = 0;
		while (argv[argc])
			argc++;
	}
	tab = NULL;
	check(argv, argc, &tab);
	return (tab);
}
