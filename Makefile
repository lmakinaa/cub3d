CC=cc
CFLAGS=  -g -fsanitize=address

HEAP_CONTROL = 	heap_control/heap_control.c\
				heap_control/utils.c

EXECUTION = execution/main.c\
			execution/minimap.c\
			execution/utils.c\
			execution/init.c

SRCS = 	$(HEAP_CONTROL)\
		$(EXECUTION)

OBJS = $(SRCS:.c=.o)

NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS) includes/cub3d.h
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $@ 

%.o: %.c includes/cub3d.h
	$(CC) $(CFLAGS) -c $< -I./includes -o $@

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean