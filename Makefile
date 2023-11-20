S_NAME = server
C_NAME = client

S_NAME_BONUS = server_bonus
C_NAME_BONUS = client_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -I ./libft/

S_SRC = server.c
S_SRC_BONUS = server_bonus.c

S_OBJ = $(S_SRC:%.c=%.o)
S_OBJ_BONUS = $(S_SRC_BONUS:%.c=%.o)

C_SRC = client.c
C_SRC_BONUS = client_bonus.c

C_OBJ = $(C_SRC:%.c=%.o)
C_OBJ_BONUS = $(C_SRC_BONUS:%.c=%.o)

all: libft $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJ) | libft
	$(CC) $(FLAGS) $(S_OBJ) ./libft/libft.a -o $(S_NAME)

$(C_NAME): $(C_OBJ) | libft
	$(CC) $(FLAGS) $(C_OBJ) ./libft/libft.a -o $(C_NAME)

bonus: libft $(S_NAME_BONUS) $(C_NAME_BONUS) 
	@echo "BONUS MODE ACTIVATED"

$(S_NAME_BONUS): $(S_OBJ_BONUS)
	$(CC) $(FLAGS) $(S_OBJ_BONUS) ./libft/libft.a -o $(S_NAME_BONUS)

$(C_NAME_BONUS): $(C_OBJ_BONUS)
	$(CC) $(FLAGS) $(C_OBJ_BONUS) ./libft/libft.a -o $(C_NAME_BONUS)

libft:
	@make -C ./libft

clean:
	@rm -f $(S_OBJ) $(C_OBJ) $(S_OBJ_BONUS) $(C_OBJ_BONUS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(S_NAME) $(C_NAME) $(S_NAME_BONUS) $(C_NAME_BONUS)
	@make fclean -C ./libft
	@echo "$(S_NAME) && $(C_NAME) removed."

re: fclean all

.PHONY: all clean fclean re libft bonus 
