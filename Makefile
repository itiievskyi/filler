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

SOURCES =	filler.c\
			struct.c\
			solver.c\


SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(FLAGS) -o $(NAME) $(OBJS)\
	 ./libft/libft.a ./libft/ft_printf/libftprintf.a

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	$(C) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette $(HEADER)
	@echo
	norminette $(SOURCES)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
