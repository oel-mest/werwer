# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

# Directories
SRCS_DIR = srcs
OBJS_DIR = objs

# Source files
SRCS = $(SRCS_DIR)/main.c \
       $(SRCS_DIR)/cleaning/clean_1.c \
       $(SRCS_DIR)/cleaning/clean_2.c \
       $(SRCS_DIR)/debug/print.c \
       $(SRCS_DIR)/env/expander.c \
       $(SRCS_DIR)/env/parse_env.c \
       $(SRCS_DIR)/env/toberemoved.c \
       $(SRCS_DIR)/parsing/command_utils.c \
       $(SRCS_DIR)/parsing/command.c \
       $(SRCS_DIR)/parsing/helpers.c \
       $(SRCS_DIR)/parsing/logical.c \
       $(SRCS_DIR)/parsing/pipe.c \
       $(SRCS_DIR)/parsing/subshell_utils.c \
       $(SRCS_DIR)/parsing/subshell.c \
       $(SRCS_DIR)/parsing/utils.c \
       $(SRCS_DIR)/tokenizer/helpers.c \
       $(SRCS_DIR)/tokenizer/quotes.c \
       $(SRCS_DIR)/tokenizer/special_tokens.c \
       $(SRCS_DIR)/tokenizer/tokenize.c \
       $(SRCS_DIR)/tokenizer/utils.c \
       $(SRCS_DIR)/tokenizer/words.c \
       $(SRCS_DIR)/utils/utils_1.c

# Object files
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# Executable name
NAME = minishell

# Default target
all: $(NAME)

# Rule to compile the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) -lreadline

# Rule to compile object files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJS_DIR)

# Full clean rule (clean + remove executable)
fclean: clean
	rm -f $(NAME)

# Rebuild rule
re: fclean all

# Phony targets
.PHONY: all clean fclean re