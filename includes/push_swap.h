/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:41:58 by sgabsi            #+#    #+#             */
/*   Updated: 2024/02/08 15:47:50 by sgabsi           ###   ########.fr       */
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
	TYPE_ERROR
};

//stack struct with his functions
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

//instructions
//push
void	push(t_stack *a, t_stack *b, char c);
//swap
void	swap(t_stack *a, t_stack *b, char c);
//rotate
void	rotate(t_stack *a, t_stack *b, char c);
//reverse rotate
void	rev_rotate(t_stack *a, t_stack *b, char c);

//utils
void	usage(void);
bool	is_sorted_ascending(t_stack *stack);
bool	is_sorted_descending(t_stack *stack);
char	**parse_string(int argc, char **argv);
int		mediane_des_medianes(int *tableau, int taille);
int		*stack_to_tab(t_stack *stack);

//inits
void	init_stack(t_stack *stack, char *argv[], char c);
void	init_nodes(t_stack *a, t_stack *b);
void	init_pos(t_stack *stack);

//math
int		min_of_stack(t_stack *stack);
int		max_of_stack(t_stack *stack);
t_node	*node_min(t_stack *stack);
t_node	*node_max(t_stack *stack);

//tri
void	short_sort(t_stack *stack);
void	sort(t_stack *a, t_stack *b);

//errors
void	error(int erreur);
void	tab_str_error(char **tab);
void	tab_int_error(int *tab);

#endif