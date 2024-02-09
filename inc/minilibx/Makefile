# Colors

DEF_COLOR 	= \033[0;39m
GRAY 		= \033[0;90m
GREEN		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -w

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

%.o:	%.c
	@cc $(CFLAGS) -c $< -o $@
	@printf "\33[2K\r$(GRAY)cc $(CFLAGS) -c -o $@$(DEF_COLOR)"

$(NOM):	$(OBJ)
	@echo "$(GRAY)\n"
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "\n$(GREEN)libmlx.a compiled!$(DEF_COLOR)"

clean:
	rm -f $(OBJ) *~ ._*
	rm -f mlx_app
	echo "\nlibmlx$(YELLOW) cleaned$(DEF_COLOR)"

fclean:	clean
	rm -rf $(NOM)

re: clean all

.PHONY: all clean fclean re
.SILENT: clean fclean $(NOM) $(OBJ)
