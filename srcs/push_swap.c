/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:56:58 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/12 10:13:18 by sgabsi           ###   ########.fr       */
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
	int		*parsed;

	if (argc < 2 || !argv[1][0])
		usage();
	argv++;
	parsed = parse_string(argc - 1, argv);
	init_stack(&a, parsed, argc - 1, 'a');
	init_stack(&b, NULL, 0, 'b');
	free(parsed);
	if (!is_sorted_ascending(&a))
		sort(&a, &b);
	clear_nodes(&a);
	clear_nodes(&b);
	return (SUCCESS);
}
