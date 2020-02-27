# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcapers <dcapers@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 11:31:41 by dcapers           #+#    #+#              #
#    Updated: 2020/02/27 15:51:39 by dcapers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

CHECKER_N = checker
PUSHSWAP_N = push_swap

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = src

DIR_O = objects

HEADER = includes

CHECKER_SOURCES = ft_stk_create.c ft_stk_push.c ft_stk_pop.c ft_stk_clear.c \
		  		  ft_stk_print.c ft_stk_swap.c ft_stk_rotate.c ft_stk_add.c \
				  operations.c main_checker.c ft_list_push.c fill_stack.c
PUSHSWAP_SOURCES = ft_stk_create.c ft_stk_push.c ft_stk_pop.c ft_stk_clear.c \
		  		  ft_stk_print.c ft_stk_swap.c ft_stk_rotate.c ft_stk_add.c \
				  operations.c main_pushswap.c ft_list_push.c fill_stack.c   \
				  ft_quicksort.c generate_cmds.c is_stk_sorted.c move_commands.c \
				  fill_array.c

CHECKER_SRCS = $(addprefix $(DIR_S)/,$(CHECKER_SOURCES))
PUSHSWAP_SRCS = $(addprefix $(DIR_S)/,$(PUSHSWAP_SOURCES))

CHECKER_OBJS = $(addprefix $(DIR_O)/,$(CHECKER_SOURCES:.c=.o))
PUSHSWAP_OBJS = $(addprefix $(DIR_O)/,$(PUSHSWAP_SOURCES:.c=.o))

all: $(CHECKER_N) $(PUSHSWAP_N)

$(CHECKER_N): $(CHECKER_OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./
	@gcc $(FLAGS) -I $(HEADER) $(CHECKER_OBJS) libft.a -o $(CHECKER_N)

$(PUSHSWAP_N): $(PUSHSWAP_OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./
	@gcc $(FLAGS) -I $(HEADER) $(PUSHSWAP_OBJS) libft.a -o $(PUSHSWAP_N)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p objects
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(CHECKER_N)
	@rm -f $(PUSHSWAP_N)
	@rm -f libft.a
	@make fclean -C $(LIBFT)

re: fclean all