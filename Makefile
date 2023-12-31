# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 15:10:33 by vzayas-s          #+#    #+#              #
#    Updated: 2023/11/22 14:07:27 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# RULES #
# NAME #
NAME = cub3D

# FLAGS #
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MLXFLAGS = -framework OpenGL -framework AppKit

#ifeq ($(UNAME), Linux)
#	MLXFLAGS = -lmlx -lXext -lX11 -lm
#endif

# INCLUDES #
INCDIR = includes/
INCLUDES = -I $(INCDIR)

# LIBRARIES #
LIBFT = libft/libft.a
MLX = mlx/libmlx.a

# OBJS #
OBJDIR := objs/
SRCDIR := src/

# SRCS #
ERROR = error exit
MAIN = main initial
MAP = get_map check_map check_attrb
TEXTURE = get_texture check_texture mlx_img
RAYCAST = distance line_fixer raycaster
DRAW = draw_columns player_poss
MLX_SRC = keyhooks posible_move

PLAIN_SRCS =	$(addsuffix .c, $(addprefix error/, $(ERROR)))\
				$(addsuffix .c, $(addprefix main/, $(MAIN)))\
				$(addsuffix .c, $(addprefix map/, $(MAP)))\
				$(addsuffix .c, $(addprefix texture/, $(TEXTURE)))\
				$(addsuffix .c, $(addprefix raycast/, $(RAYCAST)))\
				$(addsuffix .c, $(addprefix draw/, $(DRAW)))\
				$(addsuffix .c, $(addprefix mlx/, $(MLX_SRC)))

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
define FISH

                         _.'.__
                      _.'      .
':'.               .''   __ __  .
  '.:._          ./  _ ''     "-'.__
.'''-: """-._    | .                "-"._
 '.     .    "._.'                       "
    '.   "-.___ .        .'          .   :o'.
      |   .----  .      .           .'      :
       '|  ----. '   ,.._                _-'
        .' .---  |.""  .-:;.. _____.----'
        |   .-""""    |      '
      .'  _'         .'    _'		 swiming away with all objects...
     |_.-'            '-.'

endef
export FISH

# COMPILATION #
# remove compilation message from cli
.SILENT:

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	echo "$(CYAN)making directories...$(END)"
	make -C libft all
	make -C mlx all 2> /dev/null
	$(CC) $(CFLAGS) $^ $(LIBFT) $(MLXFLAGS) $(MLX) -o $(NAME)
	echo "$(BLUE)༺ Program compiled༻$(END)"
	echo "$$CUB3D"

# delete all objects
clean:
	make -C libft clean
	make -C mlx clean
	rm -rf $(OBJDIR)
	echo "$(RED)༺ Objs deleted༻$(END)"
	echo "$$FISH"

# delete executable
fclean: clean
	make -C libft fclean
	rm $(NAME)
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re
