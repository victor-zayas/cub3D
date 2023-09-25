
# RULES #

# NAME #
NAME = cub3D

# FLAGS #
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

# INCLUDES #
INCDIR = includes/
INCLUDES = $(INCDIR)

# OBJS #
OBJS = $(SRCS:.c=.o)

OBJDIR := objs/
SRCDIR := src/

# SRC #
SRCS =	main.c			\
		
SRC := $(addprefix $(SRCDIR), $(SRCS))
OBJS := $(addprefix $(OBJDIR), $(OBJS))

# ASCII COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m

# MAKEFILE ART #
define CUB3D
$(INSERT_COLOR)
 
$(END)
endef
export CUB3D

# COMPILATION #
remove compilation message from cli
.SILENT:

all: $(NAME) $(INCLUDES)

# make all *.c have the same name as *.o 
$(OBJDIR)%.o: $(SRCDIR)%.c
# make a new directory objects for *.o
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@
# compile
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)
# message for compilation finished
	echo "$(BLUE)༺ Program compiled༻$(END)"
# show ascii art with env variable
	echo "$$CUB3D"

# delete all objects
clean:
	$(RM) -rf $(OBJDIR)
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

# call clean and delete executable
fclean: clean
	$(RM) $(NAME)
		echo "$(YELLOW)༺ Executable deleted༻$(END)"

# delete the executable, objects and recompile
re: fclean all

.PHONY: all clean fclean re
