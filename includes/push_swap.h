/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:41:58 by sgabsi            #+#    #+#             */
/*   Updated: 2024/03/14 12:04:18 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>

# include "libft.h"

// EXIT ERROR
enum e_error
{
	SUCCESS,
	FAILURE,
	MALLOC_ERROR,
	TAB_ERROR,
	TYPE_ERROR,
	INT_OVERFLOW
};

// ===================================================

/**les structures utilisees par les stacks
 * et leurs fonctions : 
*/
typedef struct s_node
{
	int				value;
	int				current_pos;
	int				cost;
	bool			top_of_med;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	char	name;
	t_node	*head;
	t_node	*tail;
	size_t	size;
}			t_stack;

void	clear_nodes(t_stack *stack);
void	print_stack(t_stack *stack);
void	push_back(t_stack *stack, t_node *new);
void	push_front(t_stack *stack, t_node *new);
void	push_stack(t_stack *src, t_stack *dest);
void	rotate_stack(t_stack *stack);
void	rev_rotate_stack(t_stack *stack);
void	swap_stack(t_stack *stack);
t_node	*new_node(int content);

//====================== instructions ======================

void	push(t_stack *a, t_stack *b, char c);
void	swap(t_stack *a, t_stack *b, char c);
void	rotate(t_stack *a, t_stack *b, char c);
void	rev_rotate(t_stack *a, t_stack *b, char c);

//========================= utils ==========================

int		*parse_string(int argc, char **argv);
void	get_three_biggest(int tab[3], t_stack *a);
bool	is_sorted_ascending(t_stack *stack);
bool	is_sorted_descending(t_stack *stack);
bool	is_in_tab(int *tab, int size, int val);
bool	check_three_biggest(int tab[3], int value);

//========================= inits =========================

void	init_stack(t_stack *stack, int *tab, int size, char c);
void	init_nodes(t_stack *a, t_stack *b);
void	init_pos(t_stack *stack);
void	reset_cost(t_stack *stack);

//========================= math ==========================

t_node	*min_of_stack(t_stack *stack);
t_node	*max_of_stack(t_stack *stack);
bool	is_new_min_max(int value, t_stack *stack);

//========================= tri ===========================

void	short_sort(t_stack *stack);
void	short_sort_five(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
void	set_cost(t_stack *src, t_stack *dest);
t_node	*find_lowest_cost(t_stack *src, t_stack *dest, int tab[3]);

//========================= errors ========================

void	error(int erreur);
void	tab_str_error(char **tab);
void	tab_int_error(int *tab);

//========================= free ==========================

void	free_str_tab(char **tab);
void	free_int_tab(int *tab);

#endif