NAME = minishell
CC = cc
CFLAGSE = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = minishell.c get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGSE) $(OBJ) $(LIBFT) -o $(NAME)

clean :
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all