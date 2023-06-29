# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-der <avan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/16 10:29:51 by avan-der      #+#    #+#                  #
#    Updated: 2023/06/22 14:49:45 by avan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# CONFIG
NAME		=	minishell
CC			=	cc
CFLAGS		=	-Wall -Wextra -g3 -fsanitize=address

# DIRECTORIES
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

LIBFT_DIR	=	libft/
LIBFT		=	$(LIBFT_DIR)libft.a

HEADER		=	-I $(INC_DIR)			\
				-I $(LIBFT_DIR)include	\
				-lreadline

# SOURCES
SRC_NAMES	=	minishell				\
				shell_interactive		\
				utils					\
				lexer					\
				parser

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_NAMES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_NAMES)))

# COLORS
DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

###

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ) 
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(HEADER) $(LIBFT) $(OBJ) -o $(NAME)
	@echo "$(ORANGE)[minishell]\t\t$(DEF_COLOR)$(GREEN)\t=> Compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

clean :
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "$(BLUE)[libft]\t\tobject files$(DEF_COLOR)$(GREEN)\t=> Cleaned!$(DEF_COLOR)"
	@echo "$(BLUE)[minitalk]\tobject files$(DEF_COLOR)$(GREEN)\t=> Cleaned!$(DEF_COLOR)"

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	@echo "$(CYAN)[libft]\t\texecutables$(DEF_COLOR)$(GREEN)\t=> Cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)[minishell]\texecutables$(DEF_COLOR)$(GREEN)\t=> Cleaned!$(DEF_COLOR)"

re : fclean all
	@echo "$(GREEN)Everything cleaned and rebuilt!$(DEF_COLOR)"
.PHONY: all clean fclean re