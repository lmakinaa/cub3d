CC=cc
CFLAGS=-Werror -Wextra -Wall  -g -fsanitize=address

HEAP_CONTROL = 	heap_control/heap_control.c\
				heap_control/utils.c

EXECUTION = execution/main.c\
			execution/cast_rays.c

SRCS = 	$(HEAP_CONTROL)\
		$(EXECUTION)

OBJS = $(SRCS:.c=.o)

NAME = cub3D

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I./includes -o $@

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean