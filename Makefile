# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 19:35:48 by vtarasov          #+#    #+#              #
#    Updated: 2026/07/02 18:18:32 by vtarasov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_lstiter.c ft_substr.c ft_atoi.c ft_lstnew.c ft_is_functions.c ft_lstadd.c ft_memmove.c ft_striteri.c ft_put_fd.c ft_strmapi.c ft_memset.c ft_itoa.c ft_split.c ft_strtrim.c ft_lstdel.c ft_strjoin.c ft_lstlast.c ft_strlcat.c ft_strdup.c ft_memcpy.c ft_bzero.c ft_strchr.c ft_strncmp.c ft_strnstr.c ft_lstsize.c ft_strlcpy.c ft_strlen.c ft_calloc.c ft_switchcase.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft-test

re: fclean $(NAME)

debug: CFLAGS += -g
debug: $(NAME)

redebug: CFLAGS += -g
redebug: re

tests: debug
	cc -g testcases.c -lft -L. -lbsd -o libft-test

retests: redebug tests

.PHONY: all clean fclean re tests retests debug redebug