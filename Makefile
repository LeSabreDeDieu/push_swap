# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:28:59 by sgabsi            #+#    #+#              #
#    Updated: 2024/04/02 16:19:14 by sgabsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

# Directories
SRCS_SUBDIR	=	inits instruction stack tri
SRCDIR		=	./srcs
INCDIR		=	./includes
LIBDIR		=	./libs
OBJDIR		=	objs

# Sources
# init
SRCS_INIT_DIR	=	inits
SRCS_INIT_LIST	=	init_pos.c		\
					init_stack.c
SRCS_INIT		=	$(addprefix $(SRCS_INIT_DIR)/, $(SRCS_INIT_LIST))

# instruction
SRCS_INST_DIR	=	instruction
SRCS_INST_LIST	=	push_command.c	\
					rotate_command.c\
					swap_command.c
SRCS_INST		=	$(addprefix $(SRCS_INST_DIR)/, $(SRCS_INST_LIST))

# stack
SRCS_STACK_DIR	=	stack
SRCS_STACK_LIST	=	clear_nodes.c	\
					new_node.c		\
					print_stack.c	\
					push_back.c		\
					push_front.c	\
					push.c			\
					rotate.c		\
					swap.c
SRCS_STACK		=	$(addprefix $(SRCS_STACK_DIR)/, $(SRCS_STACK_LIST))

# tri
SRCS_TRI_DIR	=	tri
SRCS_TRI_LIST	=	cost_calc.c		\
					short_sort.c	\
					sort.c			\
					create_chunk.c
SRCS_TRI		=	$(addprefix $(SRCS_TRI_DIR)/, $(SRCS_TRI_LIST))

# racine
SRCS_LIST		=	error.c			\
					is_sorted.c		\
					math.c			\
					parsing.c		\
					push_swap.c		\
					$(SRCS_INIT)	\
					$(SRCS_INST)	\
					$(SRCS_STACK)	\
					$(SRCS_TRI)

SRCS			=	$(addprefix $(SRCDIR)/, $(SRCS_LIST))

# Objects
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT_DIR = $(LIBDIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Output
NAME		=	push_swap

# Compiler
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g3
OPTIONS		=	-I $(INCDIR) -I $(LIBFT_DIR)/$(INCDIR)
LFLAGS		=	-L $(LIBFT_DIR) -lft

# Progress bar
COUNT		=	1
TOTAL_FILES	=	$(shell find ./srcs -type f -name "*.c" | wc -l)

# Colors
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
NC			=	\033[0m
KL			=	\033[K

#################
##  TARGETS    ##
#################

all: pre_comp $(NAME)

pre_comp :
	@echo "$(YELLOW)********* Début de la compilation du programme $(NAME) *********$(NC)"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(OPTIONS) $(LFLAGS) -o $@
	@echo -e "\r$(GREEN)********* Compilation terminée avec succès! *********$(NC)$(KL)"
	@echo "$(GREEN)********* L'executable $(NAME) a été créée. *********$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIONS) -c $< -o $@
	@printf "$(NC)\rCompiling files: [%-50s] %3d%% (%d/%d) %s$(KL)" \
		"$(shell printf '=%.0s' $$(seq 1 $$(($(COUNT) * 50 / $(TOTAL_FILES)))))" \
		$$(($(COUNT) * 100 / $(TOTAL_FILES))) \
		$(COUNT) \
		$(TOTAL_FILES) \
		$<
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@rm -rf $(OBJDIR)
	@make -sC $(LIBFT_DIR) clean
	@echo "$(YELLOW)********* Suppression des fichiers objets *********$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean
	@echo "$(RED)********* Suppression de l'executable $(NAME) *********$(NC)"

re: fclean all

norminette:
	@echo "$(YELLOW)********* Exécution de norminette *********$(NC)"
	@norminette | grep -B 1 -e "Error" || echo "Tous les fichiers ont passé le check norminette !"

.PHONY: all clean fclean re