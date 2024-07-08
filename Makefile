# Variables
CC = cc
CFLAGS = -Werror -Wall

MINILIBX_URL = https://github.com/42Paris/minilibx-linux.git
MINILIBX_FOLDER = minilibx-linux
MINILIBX_COMMAND = -L$(MINILIBX_FOLDER) -lmlx_Linux -lX11 -lXext

NAME = fractol

HEADER = fractol.h
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(MINILIBX_FOLDER) $(NAME)

# Clone and build minilibx
$(MINILIBX_FOLDER):
	git clone $(MINILIBX_URL)
	cd $(MINILIBX_FOLDER) && $(MAKE)
	clear

# Link the object files to create the executable
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MINILIBX_COMMAND) $(CFLAGS) -o $(NAME)
	clear

# Compile each source file into an object file
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	clear

# Clean
clean:
	rm -f $(OBJS)
	clear

# Full clean
fclean: clean
	rm -rf $(MINILIBX_FOLDER) $(NAME)
	clear

# Rebuild target
re: fclean all

.PHONY: all clean fclean re
