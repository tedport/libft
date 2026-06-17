# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 19:35:48 by vtarasov          #+#    #+#              #
#    Updated: 2026/06/17 22:27:39 by vtarasov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_is_functions.c ft_memmove.c ft_memset.c ft_strlcat.c ft_memcpy.c ft_bzero.c ft_strchr.c ft_strncmp.c ft_strnstr.c ft_strlcpy.c ft_strlen.c ft_switchcase.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME).a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re