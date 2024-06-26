SHELL		= /bin/sh

NAME		:= RayCast3D

CC			= clang
CFLAGS		:= -Wextra -Wall -Werror \
#	-Wunreachable-code -g -fsanitize=address,undefined \

## LIBS ##
LIBMLX		:= ./lib/MLX42
LIBFT		:= ./lib/libft
LINKER		:= -L "$(HOME)/.brew/opt/glfw/lib/" -ldl -lglfw -pthread -lm
LIBS		= ${LINKER} ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a

## HEADERS ##
HEADER_SRCS	:=	raycast3d.h structures.h
HEADER_DIR	:=	inc/
HEADERS		= -I  $(HEADER_DIR) -I ${LIBMLX}/include -I ${LIBFT}

## SOURCE ##
SRCS		:= main.c free.c print.c exit.c \
	initialise.c initialise_animated_textures.c \
	file_load.c file_elements.c file_elements_utils.c \
	user_input.c user_input_move.c user_input_check_corner.c\
	file_map.c utils_valid_map.c utils_ray_casting.c\
	minimap.c minimap_player.c user_input_minimap.c \
	ray_casting.c \
	world.c world_walls.c world_walls_colour.c \
	utils_joinfree.c utils_fill_map.c utils_move_player.c\
	doors.c doors_input.c\
	world_door_colour.c user_input_mouse.c \
	world_walls_utils.c \

SRC_DIR	:= src
BUILD_DIR	:= build
SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS		:= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,\
	$(SRCS))

## TARGET ##
all	: libmlx libft $(NAME)
	@echo "${BMAG}Build successful!${NC}"

libmlx:
	@echo "${MAG}Building ${BMAG}MLX42...${NC}"
	@${MAKE} -C ${LIBMLX}
	@echo "${MAG}MLX42 build complete.${NC}"

libft:
	@echo "${MAG}Building ${BMAG}libft...${NC}"
	@${MAKE} -C ${LIBFT}
	@echo "${MAG}libft build complete.${NC}"

$(NAME): $(OBJS)
	@echo "${BCYA}Creating executable: $(NAME)${NC}"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "${MAG}$(NAME) build complete.${NC}"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix $(HEADER_DIR), $(HEADER_SRCS))
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@echo "${BGRE}Compiling:${NC} $(notdir $<) \
		${MAG}for ${BMAG}$(NAME)${NC} "

clean	:
	@echo "$(RED)Cleaning$(NC)"
	rm -f $(OBJS)
	rm -rf $(BUILD_DIR)
	${MAKE} -C ${LIBMLX} fclean
	${MAKE} -C ${LIBFT} fclean

fclean	: clean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all, clean, fclean, re, libmlx, libft
.DEFAULT_GOAL := all

## Colors ##
RED		:= \033[0;31m
BRED	:= \033[1;31m
GRE		:= \033[0;32m
BGRE	:= \033[1;32m
YEL		:= \033[0;33m
BYEL	:= \033[1;33m
BLU		:= \033[0;34m
BBLU	:= \033[1;34m
MAG		:= \033[0;35m
BMAG	:= \033[1;35m
CYA		:= \033[0;36m
BCYA	:= \033[1;36m
BWHI	:= \033[1;37m
NC		:= \033[0m
