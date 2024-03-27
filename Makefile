BIN=main
CC=gcc
SRC=main.c
INC=inc/
CFLAGS = -Wall -Wextra -Werror	-g -fsanitize=address


all:
	$(CC) $(CFLAGS) -I$(INC) $(SRC) -o $(BIN)

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ) $(BIN)
re: fclean all
