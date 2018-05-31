# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 14:51:09 by itiievsk          #+#    #+#              #
#    Updated: 2018/04/24 14:51:11 by itiievsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = itiievsk.filler

FLAGS = -Wall -Wextra -Werror

DIR_S = ./

DIR_O = obj

HEADER = filler.h

LIB = libft/libft.a

SOURCES =	filler.c\
			struct.c\
			solver.c\
			testers.c\

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft/
	$(MAKE) -C ./visual/
	$(C) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	$(C) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	@norminette $(HEADER)
	@norminette $(SOURCES)
	@cd ./libft/ && make norme
	@cd ./visual/ && make norme

clean:
	@cd ./libft/ && make clean
	@cd ./visual/ && make clean
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@cd ./libft/ && make fclean
	@cd ./visual/ && make fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
