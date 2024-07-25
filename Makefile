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
PSDIR = $(SRCDIR)/push_swap
LIBFT_LIB = $(LIBDIR)/libft.a
PUSHSWAP_SRCS = $(PSDIR)/circular_array_utils_1.c $(PSDIR)/main.c $(PSDIR)/operations_utils.c $(PSDIR)/ps_sorting_functions.c $(PSDIR)/ps_turk_sort_pushb_1.c $(PSDIR)/circular_array_utils_2.c $(PSDIR)/operations_1.c $(PSDIR)/ps_input_validation_2.c $(PSDIR)/ps_turk_sort.c $(PSDIR)/ps_turk_sort_pushb_2.c $(PSDIR)/circular_array_utils_3.c $(PSDIR)/operations_2.c $(PSDIR)/ps_input_validation.c $(PSDIR)/ps_turk_sort_pusha_1.c $(PSDIR)/ps_turk_sort_pushb_3.c
PUSHSWAP_OBJ = $(PUSHSWAP_SRCS:.c=.o)

# Target to make using Make all
all: $(NAME) print_art

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

print_art:
	@echo "______          _              _"
	@echo "| ___ \\        | |            | |"
	@echo "| |_/ /   _ ___| |__   ___  __| |"
	@echo "|  __/ | | / __| '_ \\ / _ \\/ _\` |"
	@echo "| |  | |_| \\__ \\ | | |  __/ (_| |"
	@echo "\\_|   \\__,_|___/_| |_|\\___|\\__,_|"
	@echo ""
	@echo ""
	@echo ""
	@echo " ___"
	@echo "( _ )"
	@echo "/ _ \\/\\"
	@echo "|(_>  <"
	@echo "\\___/\\/"
	@echo ""
	@echo ""
	@echo " _____                                    _"
	@echo "/  ___|                                  | |"
	@echo "\\ \`--.__      ____ _ _ __  _ __   ___  __| |"
	@echo " \`--. \\ \\ /\\ / / _\` | '_ \\| '_ \\ / _ \\/ _\` |"
	@echo "/\\__/ /\\ V  V / (_| | |_) | |_) |  __/ (_| |"
	@echo "\\____/  \\_/\\_/ \\__,_| .__/| .__/ \\___|\\__,_|"
	@echo "                    | |   | |"
	@echo "                    |_|   |_|"