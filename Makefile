# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/23 20:23:04 by sdatskov          #+#    #+#              #
#    Updated: 2019/06/24 20:18:14 by sdatskov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
INC_PATH = ./includes/ $(LIB_PATH)/includes/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/
LIB_LNK	= -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -lpthread

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_NAME = main.c\
	  fr_check.c\
	  fr_error.c\
	  fr_initial.c\
	  fr_draw.c\
	  fr_hook.c\
	  fr_color.c\
	  fractol.c\
	  fractol2.c\
	  fr_manipulation.c\
	  fr_manipulation2.c\
	  fr_menu.c\

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIB_LNK)
	@echo "Compiling..." [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo "Linking..." [ $< ]

clean:
	@make -C $(LIB_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning objects..."

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "Remove fractol..." [ $(NAME) ]

re: fclean all
