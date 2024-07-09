# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 22:10:59 by mintan            #+#    #+#              #
#    Updated: 2024/07/07 20:03:21 by mintan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler + compile flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Definitions
NAME = push_swap
SRCDIR = src
LIBFT_LIB = $(SRCDIR)/libft/libft.a
LIBFT_SRCS = $(SRCDIR)/libft/ft_atoi.c $(SRCDIR)/libft/ft_lstiter.c $(SRCDIR)/libft/ft_puthexa.c $(SRCDIR)/libft/ft_strlcpy.c $(SRCDIR)/libft/ft_bzero.c $(SRCDIR)/libft/ft_lstlast.c $(SRCDIR)/libft/ft_putnbr.c $(SRCDIR)/libft/ft_strlen.c $(SRCDIR)/libft/ft_calloc.c $(SRCDIR)/libft/ft_lstmap.c $(SRCDIR)/libft/ft_putnbr_fd.c $(SRCDIR)/libft/ft_strmapi.c $(SRCDIR)/libft/ft_isalnum.c $(SRCDIR)/libft/ft_lstnew.c $(SRCDIR)/libft/ft_putptr.c $(SRCDIR)/libft/ft_strncmp.c $(SRCDIR)/libft/ft_isalpha.c $(SRCDIR)/libft/ft_lstsize.c $(SRCDIR)/libft/ft_putstr.c $(SRCDIR)/libft/ft_strnstr.c $(SRCDIR)/libft/ft_isascii.c $(SRCDIR)/libft/ft_memchr.c $(SRCDIR)/libft/ft_putstr_fd.c $(SRCDIR)/libft/ft_strrchr.c $(SRCDIR)/libft/ft_isdigit.c $(SRCDIR)/libft/ft_memcmp.c $(SRCDIR)/libft/ft_putunsignednbr.c $(SRCDIR)/libft/ft_strtrim.c $(SRCDIR)/libft/ft_isprint.c $(SRCDIR)/libft/ft_memcpy.c $(SRCDIR)/libft/ft_split.c $(SRCDIR)/libft/ft_substr.c $(SRCDIR)/libft/ft_itoa.c $(SRCDIR)/libft/ft_memmove.c $(SRCDIR)/libft/ft_strchr.c $(SRCDIR)/libft/ft_tolower.c $(SRCDIR)/libft/ft_lstadd_back.c $(SRCDIR)/libft/ft_memset.c $(SRCDIR)/libft/ft_strdup.c $(SRCDIR)/libft/ft_toupper.c $(SRCDIR)/libft/ft_lstadd_front.c $(SRCDIR)/libft/ft_printf.c $(SRCDIR)/libft/ft_striteri.c $(SRCDIR)/libft/ft_lstclear.c $(SRCDIR)/libft/ft_putchar_fd.c $(SRCDIR)/libft/ft_strjoin.c $(SRCDIR)/libft/ft_lstdelone.c $(SRCDIR)/libft/ft_putendl_fd.c $(SRCDIR)/libft/ft_strlcat.c

#COMEBACK AND CHANGE THIS AFTER ALL THE FILES ARE SETTLED
PUSHSWAP_SRCS = $(wildcard $(SRCDIR)/push_swap/*.c)
LIBFT_OBJ = $(LIBFT_SRCS:.c=.o)
PUSHSWAP_OBJ = $(PUSHSWAP_SRCS:.c=.o)

# Target to make using Make all
all: $(NAME)

# Generate the programme by compiling the objects with libft.a
$(NAME): $(LIBFT_LIB) $(PUSHSWAP_OBJ)
	$(CC) $(CFLAGS) $(PUSHSWAP_OBJ) $(LIBFT_LIB) -o $@

# Build the libft.a library
$(LIBFT_LIB): $(LIBFT_OBJ)
	ar rcs $@ $^

# Generate all the .o files from the .c files for both libft and push_swap
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Clear the build files
clean:
	rm -f $(LIBFT_OBJ) $(PUSHSWAP_OBJ)

fclean: clean
	rm -f $(NAME) $(LIBFT_LIB)

# Rule to rebuild the target
re:	fclean all

# Phony targets
.PHONY: all clean re fclean
