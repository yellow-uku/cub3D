# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 18:18:12 by pkayleen          #+#    #+#              #
#    Updated: 2020/11/28 00:01:35 by pkayleen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
FLAG = -Wall -Wextra -Werror
OPTION = -c
FUNCTIONS = ft_atoi \
	  ft_isalnum \
	  ft_isalpha \
	  ft_isascii \
	  ft_isdigit \
	  ft_isprint \
	  ft_strlen \
	  ft_strncmp \
	  ft_tolower \
	  ft_toupper \
	  ft_strlcpy \
	  ft_strchr \
	  ft_strrchr \
	  ft_strlcat \
	  ft_strnstr \
	  ft_memset \
	  ft_memcpy \
	  ft_memchr \
	  ft_memcmp \
	  ft_memccpy \
	  ft_memmove \
	  ft_bzero \
	  ft_calloc \
	  ft_strdup \
	  ft_substr \
	  ft_strjoin \
	  ft_putchar_fd \
	  ft_putstr_fd \
	  ft_putendl_fd \
	  ft_putnbr_fd \
	  ft_itoa \
	  ft_strmapi \
	  ft_strtrim \
	  ft_split

FUNCTIONS_BONUS = ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstiter \
		ft_lstdelone \
		ft_lstclear \
		ft_lstmap

OBJ = $(patsubst %,%.o,$(FUNCTIONS))
SRC = $(patsubst %,%.c,$(FUNCTIONS))
OBJ_BONUS = $(patsubst %,%.o,$(FUNCTIONS_BONUS))
SRC_BONUS = $(patsubst %,%.c,$(FUNCTIONS_BONUS))

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(FLAG) $(OPTION) $(SRC)
		ar rc $(NAME) $(OBJ)
bonus:	$(NAME)
		gcc $(FLAG) $(OPTION) $(SRC_BONUS)
		ar rc $(NAME) $(OBJ_BONUS)
clean:
		@rm -f $(OBJ)
		@rm -f $(OBJ_BONUS)
		@echo "Removed objects..."
fclean:	clean
		@rm -f $(NAME)
		@echo "Removed library..."

re:	fclean all

norm:
	@norminette ft_*.c

.PHONY: all, clean, fclean, re, bonus
