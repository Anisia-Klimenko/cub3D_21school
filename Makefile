# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acristin <acristin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 09:16:01 by trurgot           #+#    #+#              #
#    Updated: 2022/04/07 08:34:45 by acristin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
NAME_BONUS	=	cub3d_bonus

LIBFT		=	libft/libft.a
# MINILIBX	=	minilibx/libmlx.dylib
MINILIBX	=	minilibx/libmlx.a

OBJDIR			=	./obj/
OBJDIR_BONUS	=	./obj_bonus/
SRCDIR			=	./src/
SRCDIR_BONUS	=	./src_bonus/
LIBDIR			=	libft

SRCS_LIST	= 	check_map.c \
				cub3d.c \
				free_all.c \
				game_loop.c \
				main.c \
				pars_map.c \
				pars_textures1.c \
				pars_textures2.c \
				play_game.c \
				raycasting.c

SRCS_L_BONUS	= 	check_map_bonus.c \
					cub3d_bonus.c \
					free_all_bonus.c \
					game_loop_bonus.c \
					key_hook_bonus.c \
					main_bonus.c \
					pars_map_bonus.c \
					pars_textures1_bonus.c \
					pars_textures2_bonus.c \
					play_game_bonus.c \
					print_minimap_bonus.c \
					raycasting_bonus.c \
					store_imgs_bonus.c

SRCS		= $(addprefix $(SRCDIR), $(SRCS_LIST))
SRCS_BONUS	= $(addprefix $(SRCDIR_BONUS), $(SRCS_L_BONUS))

OBJS		= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))
OBJS_BONUS 	= $(addprefix $(OBJDIR_BONUS), $(notdir $(SRCS_BONUS:.c=.o)))

HEAD		=	src/cub3d.h
HEAD_BONUS	=	src_bonus/cub3d_bonus.h
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -g3
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

GRN  = \033[0;32m
RED  = \033[0;31m
YEL  = \033[1;33m
END  = \033[0m
TICK = \xE2\x9C\x94

.PHONY		:	all clean fclean re libfta 

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(MINILIBX) $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -Lminilibx -lmlx -framework OpenGL -framework AppKit -lz
				@echo "\n\t$(GRN) $(TICK) $(NAME) was compiled!$(END)\n\n\t$(YEL) try it: ./$(NAME) maps/map.cub$(END)\n"
#				@echo "\n\t$(GRN) $(TICK) CUB_3D compiled!$(END)\n"
#				$(CC) $(CFLAGS) $(OBJS) -o $@ -lft -Llibft/ -lmlx -Lminilibx/ -Iminilibx/ -framework OpenGL -framework AppKit -lz 

bonus		:	$(LIBFT) $(MINILIBX) $(OBJS_BONUS)
				@make NAME="$(NAME_BONUS)" OBJS="$(OBJS_BONUS)" HEAD="$(HEAD_BONUS)" SRCDIR="$(SRCDIR_BONUS)" all

# %.o			:	%.c $(HEAD) Makefile
$(OBJDIR)%.o:  $(SRCDIR)%.c $(HEAD) Makefile
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)	:
				@mkdir $@
$(OBJS) 	: | $(OBJDIR)

$(OBJDIR_BONUS)%.o	:  $(SRCDIR_BONUS)%.c $(HEAD_BONUS) Makefile
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_BONUS)	:
				@mkdir $@
$(OBJS_BONUS) 	: | $(OBJDIR_BONUS)

$(LIBFT)	:
				@make -C libft

# $(MINILIBX)	:
# 				@make -C minilibx
# 				cp $(MINILIBX) .

$(MINILIBX)	:
				@$(MAKE) -C minilibx/ CFLAGS=-DSTRINGPUTX11\ -Ofast\ -g\ -Wno-deprecated
				@cp $(MINILIBX) .

clean		:
				@echo "$(RED)clean ...$(END)"
				@rm -rf $(OBJDIR) libmlx.a
				@rm -rf $(OBJDIR_BONUS)
				@rm -rf libmlx.a
				@make -C minilibx clean
				@make -C libft clean
	
fclean		:	clean
				@echo "$(RED)fclean ...$(END)"
				@rm -f cub3d cub3d_bonus libft/libft.a libmlx.dylib 

re			:	fclean all
