# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# VARIABLES #
NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
CFLAGS += -I ./$(INC_PATH) -I ./$(LIBFT_PATH)

# PATHs #
SRC_PATH    = srcs
INCLUDES_PATH  = srcs/includes
ENEMY_PATH = srcs/enemy
INC_PATH    = includes -pthread
OBJ_PATH    = objects

# SOURCES #
SRC =   main.c  declare_struct.c start_thread.c

SRC_INCLUDE = ft_atoi.c ft_calloc.c ft_count_forks.c


# RULES #
all: $(NAME)

OBJ_NAME = $(SRC:%.c=%.o)
OBJ_INCLUDES = $(SRC_INCLUDE:%.c=%.o)

SRCS = $(addprefix $(SRC_PATH)/, $(SRC))
SRCS_INCLUDES = $(addprefix $(INCLUDES_PATH)/, $(SRC))

OBJS =  $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJS_INCLUDES =  $(addprefix $(OBJ_PATH)/, $(OBJ_INCLUDES))

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o: $(INCLUDES_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
            
$(NAME): $(OBJS) $(OBJS_INCLUDES) | $(LIBFT_NAME)
	$(CC) $(CFLAGS) $(OBJS_INCLUDES) $(OBJS) -o $(NAME)

##RULES
$(MAKE): make

norminette:
	norminette $(SRCS)
	norminette $(INCLUDES_PATH)

clean:
	$(PURPLE) CLEANING OBJECTS $(RESET)
	rm -rf $(OBJS)
	rm -rf $(OBJS_INCLUDES)
	
fclean: clean
	$(PURPLE) CLEANING DIRECTORY AND EXEC $(RESET)
	rm -rf $(NAME)
	rm -rf $(OBJ_PATH)

re: fclean all

PHONY.: all clean fclean re norminette