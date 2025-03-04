NAME = minishell
CC = cc
CFLAGSE = -Wall -Wextra -Werror #-g3 -fsanitize=address 

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FLAGS = -lreadline

SRC = 	minishell.c \
		manage_signal.c \
		ft_lestnew.c  \
		allocate_sdata.c \
		exec_cmd.c \
		dealocate_sdata.c \
		free_arr.c 

READLINE_INC = -I/usr/include/readline
# Linker flags for readline
READLINE_LIB = -L/usr/lib -lreadline
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGSE) $(OBJ) $(LIBFT) $(READLINE_LIB) -o $(NAME) 

clean :
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all