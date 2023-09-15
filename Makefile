# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 15:40:14 by leoda-lu          #+#    #+#              #
#    Updated: 2023/09/13 15:40:14 by leoda-lu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    :=	fdf
CC      :=	cc
LINKS   :=	-lm -lz -lXext -lX11 -lmlx -L libft/ -lft
CFLAGS  :=	-g3 -Wall -Wextra -Werror
LIBFT   :=	./libft/libft.a
BUILD   :=	./objs/
VPATH   :=	./src/

SRC     :=	bresenham.c color.c free.c \
			image.c init.c keys.c read.c \
			fdf.c mouse.c projection.c \
			reproject.c rotate.c try.c \

GREEN   := \033[1;32m
RED     := \033[1;31m
WHT     := \033[1;37m
EOC     := \033[1;0m

OBJ     := $(addprefix $(BUILD), $(SRC:.c=.o))

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
		@echo "$(WHT)Compiling FDF...$(EOC)"
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LINKS)
		@echo "$(GREEN)Compiling complete."

$(BUILD)%.o:%.c
		@mkdir -p $(BUILD)
		@$(CC) $(CFLAGS) -I ./include -c $< -o $@

$(LIBFT) :
		@echo "$(WHT)Compiling libft...$(EOC)"
		@make -C libft
		@echo "$(GREEN)Compiling complete."

clean:
		@echo "$(WHT)Removing objts...$(EOC)"
		@rm -rf $(BUILD)
		@make -C libft clean
		@echo "$(GREEN)Removing complete.$(EOC)"

fclean: clean
		@echo "$(WHT)Removing all files.$(EOC)"
		@rm -f $(NAME)
		@make -C libft fclean
		@echo "$(GREEN)All files are removed.$(EOC)"

valgrind: all
		@echo "$(WHT)Removing old log.$(EOC)"
		@rm -f valgrind-out.txt
		@echo "$(WHT)Old log removed.$(EOC)"
		@echo "$(WHT)Executing Valgrind.$(EOC)"
		@valgrind --leak-check=full --show-leak-kinds=reachable --track-origins=yes \
		--log-file=valgrind-out.txt \
		./$(NAME) ./test_maps/42.fdf
		@echo "$(GREEN)Valgrind-log created.$(EOC)"

re: fclean all

.PHONY: all clean fclean re