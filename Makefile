# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:28:59 by sgabsi            #+#    #+#              #
#    Updated: 2024/03/06 13:36:21 by sgabsi           ###   ########.fr        #
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
SRCS		=	$(SRCDIR)/push_swap.c $(SRCDIR)/parsing.c $(SRCDIR)/median.c\
				$(SRCDIR)/is_sorted.c $(SRCDIR)/math.c $(SRCDIR)/error.c \
				$(SRCDIR)/inits/init_pos.c $(SRCDIR)/inits/init_stack.c $(SRCDIR)/inits/init_cost.c\
				$(SRCDIR)/stack/clear_nodes.c $(SRCDIR)/stack/new_node.c \
				$(SRCDIR)/stack/print_stack.c $(SRCDIR)/stack/push_back.c \
				$(SRCDIR)/stack/push_front.c $(SRCDIR)/stack/push.c \
				$(SRCDIR)/stack/swap.c $(SRCDIR)/stack/rotate.c \
				$(SRCDIR)/instruction/push_command.c $(SRCDIR)/instruction/swap_command.c\
				$(SRCDIR)/instruction/rotate_command.c \
				$(SRCDIR)/tri/short_sort.c $(SRCDIR)/tri/sort.c $(SRCDIR)/tri/cost_calc.c \
				$(SRCDIR)/tri/three_biggest.c

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

#Progress bar
COUNT		=	1
TOTAL_FILES	=	$(shell find ./srcs -type f -name "*.c" | wc -l)

# Colors
GREEN		=	$(echo -e "\033[0;32m")
YELLOW		=	$(echo -e "\033[0;33m")
RED			=	$(echo -e "\033[0;31m")
NC			=	$(echo -e "\033[0m")

#################
##  TARGETS    ##
#################

all: pre_comp $(NAME)

pre_comp :
	@echo "$(YELLOW)********* Début de la compilation du programme $(NAME) *********$(NC)"
	
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(CFLAGS) $(OPTIONS) $(LFLAGS) -o $@
	@echo "$(GREEN)********* Compilation terminée avec succès! *********$(NC)"
	@echo "$(GREEN)********* L'executable $(NAME) a été créée. *********$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIONS) -c $< -o $@

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