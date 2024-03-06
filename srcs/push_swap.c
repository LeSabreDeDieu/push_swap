/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:56:58 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/26 15:22:25 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	usage(void)
{
	ft_printf("Usage : ./push_swap \"[list of int]\" or ");
	ft_printf("./push_swap [list of int]\n");
	exit(FAILURE);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc < 2 || !argv[1][0])
		usage();
	argv++;
	argv = parse_string(argc, argv);
	init_stack(&a, argv, 'a');
	init_stack(&b, NULL, 'b');
	if (!is_sorted_ascending(&a))
	{
		if (a.size <= 3)
			short_sort(&a);
		else if (a.size <= 5)
			short_sort_five(&a, &b);
		else
			sort(&a, &b);
	}
	clear_nodes(&a);
	clear_nodes(&b);
	return (SUCCESS);
}
