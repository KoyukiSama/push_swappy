NAME		:= push_swap
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
INCLUDE		:= -I./include
DFLAGS		:= -g -fsanitize=leak

DIR_LBFT	:= ./libft
DIR_LBFT_A	:= $(DIR_LBFT)/libft.a

DIR_SRC		:= ./src
MAIN		:= $(DIR_SRC)/main.c
SRC			:= push_swap_manage.c push_swap_operations.c \
				push_swap_operations1.c push_swap_operations2.c \
				push_swap_parse_bigstr.c push_swap_parse_smlstr.c \
				push_swap_parse_dupes.c \
				ring_buffer_manage.c ring_buffer_manage2.c \
				ring_buffer_modify.c ring_buffer_modify2.c

DIR_OBJ		:= ./obj
OBJ			:= $(addprefix obj/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(DIR_MLX_A) $(DIR_LBFT_A) $(OBJ)
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) $(OBJ) $(MAIN) \
		$(DIR_LBFT)/libft.a -o $(NAME)

$(DIR_LBFT_A):
	@$(MAKE) -C $(DIR_LBFT)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -r -f $(DIR_OBJ)
	@$(MAKE) -C $(DIR_LBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(DIR_LBFT_A)

re: fclean all

test: all
	@norminette ./include ./libft ./src | grep "Error" || echo "success"
	./$(NAME)

.PHONY: all clean fclean re test