NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g3 -I $(INC) -I $(LIBFT_DIR)inc/ -I $(MLX_DIR)
MLXFLAGS	=	-framework OpenGL -framework AppKit
INC			=	inc/

LIBFT_DIR	=	$(INC)libft/
LIBFT		=	$(LIBFT_DIR)libft.a

MLX_DIR		=	$(INC)minilibx/
MLX			=	$(MLX_DIR)libmlx.a

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_FILES))
OBJS_FILES	=	$(SRCS_FILES:%.c=%.o)
SRCS_FILES	=	main.c init_map.c check_exit.c
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/

## Colors

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m
DEF_COLOR 	= 	\033[0;39m
GRAY 		=	\033[0;90m
RED 		=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW 		=	\033[0;93m
BLUE 		=	\033[0;94m
MAGENTA 	=	\033[0;95m
CYAN 		=	\033[0;96m
WHITE		=	\033[0;97m

all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
	echo "\nCompiling $(BLUE)$(NAME)$(DEF_COLOR)"
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT) $(MLX) $(OBJS) -o $(NAME)
	echo "$(BLUE)\n------------\n| Done! 👌 |\n------------\$(DEF_COLOR)"

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
	[ -d $(OBJS_DIR) ] | mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	printf "\33[2K\r$(GRAY)$(CC) $(CFLAGS) -c $< -o $@$(DEF_COLOR)"

$(LIBFT):
	echo "\nCompiling $(BLUE)libft$(DEF_COLOR)"
	make -C $(LIBFT_DIR)

$(MLX):
	echo "\nCompiling $(BLUE)mlx$(DEF_COLOR)"
	make -C $(MLX_DIR)

clean:
	echo "\nCleaning$(BLUE)...$(DEF_COLOR)"
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)
	rm -rf $(OBJS_DIR)
	find . -name "*.swap" -delete
	find . -name ".DS_Store" -delete
	find . -name "*.gch" -delete
	find . -name "*._." -delete
	echo "$(BLUE)\n------------\n|  clean   |\n| Done! 👌 |\n------------$(DEF_COLOR)"

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.SILENT: all clean fclean re $(NAME) $(LIBFT) $(MLX) $(OBJS)
.PHONY: all clean fclean re
