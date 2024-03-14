# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:28:59 by sgabsi            #+#    #+#              #
#    Updated: 2024/03/14 12:19:15 by sgabsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

# Directories
SRCDIR		=	./srcs
INCDIR		=	./includes
LIBDIR		=	./libs
OBJDIR		=	objs

# Sources
SRCS_SUBDIR	=	inits instruction stack tri
SRCS		=	$(SRCDIR)/push_swap.c $(SRCDIR)/parsing.c $(SRCDIR)/is_sorted.c $(SRCDIR)/math.c $(SRCDIR)/error.c \
				$(SRCDIR)/inits/init_pos.c $(SRCDIR)/inits/init_stack.c \
				$(SRCDIR)/instruction/push_command.c $(SRCDIR)/instruction/swap_command.c $(SRCDIR)/instruction/rotate_command.c \
				$(SRCDIR)/stack/clear_nodes.c $(SRCDIR)/stack/new_node.c $(SRCDIR)/stack/print_stack.c $(SRCDIR)/stack/push_back.c \
					$(SRCDIR)/stack/push_front.c $(SRCDIR)/stack/push.c $(SRCDIR)/stack/swap.c $(SRCDIR)/stack/rotate.c \
				$(SRCDIR)/tri/short_sort.c $(SRCDIR)/tri/sort.c $(SRCDIR)/tri/cost_calc.c $(SRCDIR)/tri/three_biggest.c

# Objects
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT_DIR = $(LIBDIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Output
NAME		=	push_swap

# Compiler
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
OPTIONS		=	-I $(INCDIR) -I $(LIBFT_DIR)/$(INCDIR)
LFLAGS		=	-L $(LIBFT_DIR) -lft

#Progress bar
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
	
$(NAME):$(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(OPTIONS) $(LFLAGS) -o $@
	@echo "\r$(GREEN)********* Compilation terminée avec succès! *********$(NC)$(KL)"
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
	@/bin/rm -f $(NAMESO) a.out
	@make -sC $(LIBFT_DIR) fclean
	@echo "$(RED)********* Suppression de l'executable $(NAME) *********$(NC)"

re: fclean all

.PHONY: all clean fclean re