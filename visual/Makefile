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

NAME = visual

FLAGS = -Wall -Wextra -Werror

DIR_S = ./

DIR_O = obj

HEADER = visual.h

SOURCES =	visual.c\

LIB = ./../libft/libft.a

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	$(C) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	@norminette $(HEADER)
	@norminette $(SOURCES)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
