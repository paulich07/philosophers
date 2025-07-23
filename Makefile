# === Colors ===
RED     	= \033[0;31m
GREEN   	= \033[0;32m
YELLOW  	= \033[0;33m
BLUE    	= \033[0;34m
MAGENTA 	= \033[0;35m
CYAN    	= \033[0;36m
RESET   	= \033[0m
BOLD		= \033[1m
UNDERLINE 	= \033[4;32m
GREEN_BG 	= \033[42m

NAME = philo

# Paths
SRC_DIR = src
OBJ_DIR = obj
HEADERS_DIR = include

# Compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(HEADERS_DIR) -I$(SRC_DIR) -pthread

# Sources
SRCS =	\
		$(SRC_DIR)/actions.c \
		$(SRC_DIR)/common_utils.c \
		$(SRC_DIR)/free_table.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/routine.c \
		$(SRC_DIR)/simulation_one.c \
		$(SRC_DIR)/simulation.c \
		$(SRC_DIR)/time.c \
		$(SRC_DIR)/utils.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)
	@echo "$(GREEN)---- Building of $(NAME) ----$(RESET)";

$(NAME): $(OBJS)
	@echo "$(CYAN)---- Linking target $@ ---- $(RESET)using $^"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)---- Compiling $< $(RESET) ----> $@"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo "$(MAGENTA)---- Create folder $@ $(RESET)"
	mkdir -p $(OBJ_DIR)

# Remove only temporary files
clean:
	@echo "$(RED)---- Removing .o files in $(NAME)----$(RESET)"
	@rm -rf $(OBJ_DIR)

# Remove temporary files and executables
fclean: clean 
	@if [ -n "$(NAME)" ] && [ -e "$(NAME)" ]; then \
		echo "$(RED)---- Removing executable $(NAME)...$(RESET)"; \
		rm -f $(NAME); \
	fi

re: fclean all

val: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=helgrind ./$(NAME)
 
.PHONY: all clean fclean re val
