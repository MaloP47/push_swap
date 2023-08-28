# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 15:19:55 by mpeulet           #+#    #+#              #
#    Updated: 2023/08/28 14:31:36 by mpeulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors / base 16 / Bright

DEF_COLOR		= \033[0;39m
GREY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

#Colors / Perso / Bright

ORANGE			= \033[38;5;214m

#Libft

LIBFT_DIR		= libft/
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_DIR)$(LIBFT_NAME)

#Variables

BONUS			= checker
NAME			= push_swap
CC				= cc
FLAGS			= -Wall -Werror -Wextra -g3
RM				= rm -rf
TXT				= *txt
VCF				= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
ERR				= 2>> error.txt
MESS			= 3>> message.txt
AR				= ar rcs
NORM			= ./includes\
					./libft/include/\
					./libft/src_lib
INCLUDE			= 	-I ./includes/\
					-I ./libft/include/

#Sources

OBJ_DIR_P 		= obj/
SRC_DIR_P		= src/
SRC_FUNCTIONS_P	= is_input_correct movements move_stack_a move_stack_b \
					move_both_stacks parse_string radix_sort sort super_sort_utils \
					super_sort utils

PUSH_SRC		= $(addprefix $(SRC_DIR_P), $(addsuffix .c, $(SRC_FUNCTIONS_P)))
PUSH_OBJ		= $(addprefix $(OBJ_DIR_P), $(addsuffix .o, $(SRC_FUNCTIONS_P)))

IFMAKE_DIR_P	= .cache_exists

all:			$(NAME)

$(IFMAKE_DIR_P):
					@mkdir -p $(OBJ_DIR_P)

$(LIBFT):
					@echo "$(GREY)Getting libft ready...$(DEF_COLOR)"
					@make -sC $(LIBFT_DIR)

$(OBJ_DIR_P)%.o: $(SRC_DIR_P)%.c | $(IFMAKE_DIR_P)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): 		$(LIBFT) $(PUSH_OBJ)
					@echo "$(GREY)Compiling push_swap...$(DEF_COLOR)"
					@$(CC) $(FLAGS) -o $(NAME) src/main.c $(PUSH_OBJ) $(LIBFT) $(INCLUDE)
					@echo "$(GREEN)Push_swap ready.$(DEF_COLOR)"

bonus:			$(LIBFT) $(BONUS)

$(BONUS): 		$(PUSH_OBJ) $(LIBFT)
					@$(CC) $(FLAGS) -o $(BONUS) src/checker_bonus.c $(PUSH_OBJ) $(LIBFT) $(INCLUDE)
					@echo "$(GREEN)Checker ready.$(DEF_COLOR)"

clean:
					@echo "$(MAGENTA)push_swap objects files cleaned!$(DEF_COLOR)"
					@$(RM) $(OBJ_DIR_P)
					@make -s clean -C $(LIBFT_DIR)
					
fclean:			clean
					@echo  "$(RED)push_swap removed.$(DEF_COLOR)"
					@$(RM) $(NAME) $(BONUS)
					@$(RM) $(LIBFT_DIR)$(LIBFT_NAME)
					@$(RM) $(TXT)

re:				fclean all
					@echo "$(BLUE)Cleaned and rebuilt everything for push_swap$(DEF_COLOR)"

test2:		$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-2 -n 2))
					@echo $(ARG)
					$(VCF) ./push_swap $(ARG) $(ERR) $(MESS)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)

test3:		$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-3 -n 3))
					@echo $(ARG)
					$(VCF) ./push_swap $(ARG) $(ERR) $(MESS)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)

test4:		$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-4 -n 4))
					@echo $(ARG)
					@$(VCF) ./push_swap $(ARG) $(ERR) $(MESS)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)

test5:		$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-5 -n 5))
					@echo $(ARG)
					@$(VCF) ./push_swap $(ARG) $(ERR) $(MESS)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)

test10:		$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-10 -n 10))
					@echo $(ARG)
					@$(VCF) ./push_swap $(ARG) $(ERR) $(MESS)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)

test100:	$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-100 -n 100))
					@$(VCF) ./push_swap $(ARG) $(ERR) $(MESS)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo $(ARG)

test500:	$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-500 -n 500))
					@$(VCF) ./push_swap $(ARG) $(ERR) $(MESS)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo $(ARG)

norm:
					@norminette $(SRC_DIR_P) $(NORM) $(LIBFT_DIR) | grep -v Norme -B1 || true
					@echo "Norminet the cat says : $(RED)M$(ORANGE)e$(YELLOW)o$(GREEN)w$(CYAN) !$(BLUE)!$(MAGENTA)!$(DEF_COLOR)"

.PHONY: all re clean fclean norm bonus test2 test3 test4 test5 test10 test100 test500
