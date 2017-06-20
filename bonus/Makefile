CC = gcc

RM = rm -f

CFLAGS += -W -Wall -Wextra -LLib -llist -Iinc -lm -lc_graph_prog
CFLAGS += -g3

SRC = 	parsing.c \
		tools.c \
		create_map_tab.c \
		framebuffer_create.c \
		graphics.c \
		src/my_put_pixel.c \
		src/my_draw_line.c \
		src/raycast.c \
		move.c \
		draw_sky_and_floor.c \
		raycast_FOV.c \
		draw_wall.c \
		set_struct.c \
		collide.c \
		main.c

OBJ = $(SRC:.c=.o)

NAME = wolf3d

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
