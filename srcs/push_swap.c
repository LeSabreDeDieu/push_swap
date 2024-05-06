/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:56:58 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/03 08:53:01 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_array	parsed;

	if (argc < 2 || !argv[1][0])
		return (FAILURE);
	argv++;
	parsed = parse_string(argc - 1, argv);
	init_stack(&a, parsed.tab, parsed.size);
	free(parsed.tab);
	init_stack(&b, NULL, 0);
	if (!is_sorted_ascending(&a))
		sort(&a, &b);
	clear_nodes(&a);
	clear_nodes(&b);
	return (SUCCESS);
}
