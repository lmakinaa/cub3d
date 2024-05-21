CC=cc
CFLAGS=-Werror -Wextra -Wall # -g -fsanitize=address

SRCS = execution/main.c

OBJS = $(SRCS:.c=.o)

NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) $< -I./includes -o $@