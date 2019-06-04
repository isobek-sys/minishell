#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/05/28 17:41:01 by blukasho          #+#    #+#             *#
#*   Updated: 2019/06/04 18:16:09 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = minishell.c print_start_msg.c get_argv.c read_line.c clear_argv.c\
	   get_t_minishell.c check_builtins.c get_bin_paths.c clear.c exit.c\
	   error.c get_bin_path.c is_way.c is_dir.c is_file.c

SRCS_DIR = srcs/

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

OBJ_DIR = obj/

LIBFT_PATH = libft/

CURR_PATH = .

LIB_NAME = libft/libft.a

MINISHELL = minishell

FLAGS = -Wall -Wextra -Werror -I includes

DEBUG_FLAGS = -g3 -fsanitize=address

MINISHELL_MAIN = srcs/main.c

all: make_objs_dir make_lib $(MINISHELL)

$(MINISHELL): $(LIB_NAME) $(MINISHELL_MAIN)
	gcc $(FLAGS) $(MINISHELL_MAIN) $(LIB_NAME) -o $(MINISHELL)

$(LIB_NAME): $(OBJ)
	ar -rv $(LIB_NAME) $^
	ranlib $(LIB_NAME)

set_debug_flags:
	$(eval FLAGS=$(FLAGS) $(DEBUG_FLAGS))

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	gcc $(FLAGS) -c $< -o $@

debug: fclean make_debug_lib set_debug_flags all

make_debug_lib:
	make debug -C $(LIBFT_PATH)

make_objs_dir:
	mkdir -p $(OBJ_DIR)

make_lib:
	make -C $(LIBFT_PATH)

make_re_lib:
	make re -C $(LIBFT_PATH)

make_clean_lib:
	make clean -C $(LIBFT_PATH)

make_fclean_lib:
	make fclean -C $(LIBFT_PATH)

clean: make_clean_lib
	rm -rf $(OBJ_DIR)

fclean: make_fclean_lib clean
	rm -rvf minishell.dSYM
	rm -rvf $(NAME)

re: fclean all

.PHONY: all clean fclean re
