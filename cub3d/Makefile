# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 15:10:33 by vzayas-s          #+#    #+#              #
#    Updated: 2023/09/29 11:51:20 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# RULES #

# NAME #
NAME = cub3D

# FLAGS #
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# INCLUDES #
INCDIR = includes/
INCLUDES = -I $(INCDIR)

# LIBFT #
LIBFT = libft/libft.a

# OBJS #
OBJDIR := objs/
SRCDIR := src/

# SRCS #
ERROR = error
MAIN = main initial
MAP = get_map check_map
TEXTURE = check_texture

PLAIN_SRCS =	$(addsuffix .c, $(addprefix error/, $(ERROR)))\
				$(addsuffix .c, $(addprefix main/, $(MAIN)))\
				$(addsuffix .c, $(addprefix map/, $(MAP)))\
				$(addsuffix .c, $(addprefix texture/, $(TEXTURE)))\

SRCS := $(addprefix $(SRCDIR), $(PLAIN_SRCS))
OBJS := $(addprefix $(OBJDIR), $(PLAIN_SRCS:.c=.o))

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
$(CYAN)

 ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ 
██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗
██║     ██║   ██║██████╔╝ █████╔╝██║  ██║
██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║
╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝
 ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ 
                                                                         
$(END)
endef
export CUB3D

# COMPILATION #
# remove compilation message from cli
.SILENT:

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft all
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $(NAME)
	echo "$(BLUE)༺ Program compiled༻$(END)"
	echo "$$CUB3D"

# delete all objects
clean:
	make -C libft clean
	rm -rf $(OBJDIR)
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

# delete executable
fclean: clean
	make -C libft fclean
	$(RM) $(NAME)
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re
