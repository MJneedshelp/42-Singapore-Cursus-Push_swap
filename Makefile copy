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
LIBDIR = $(SRCDIR)/libft
LIBFT_LIB = $(LIBDIR)/libft.a

#COMEBACK AND CHANGE THIS AFTER ALL THE FILES ARE SETTLED
PUSHSWAP_SRCS = $(wildcard $(SRCDIR)/push_swap/*.c)
PUSHSWAP_OBJ = $(PUSHSWAP_SRCS:.c=.o)

# Target to make using Make all
all: $(NAME)

# Generate the programme by compiling the objects with libft.a
$(NAME): $(LIBFT_LIB) $(PUSHSWAP_OBJ)
	$(CC) $(CFLAGS) $(PUSHSWAP_OBJ) $(LIBFT_LIB) -o $@

# Build the libft.a library
$(LIBFT_LIB):
	cd $(LIBDIR) && make all

# Generate all the .o files from the .c files for push_swap
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Clear the build files
clean:
	rm -f $(PUSHSWAP_OBJ)
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

# Rule to rebuild the target
re:	fclean all

# Phony targets
.PHONY: all clean re fclean
