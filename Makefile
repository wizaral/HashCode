CC = g++
STANDARD = -std=c++17
NAME = slice.exe

WFLAGS = -Wall -Wextra -Werror -Wpedantic
OFLAGS = -Ofast -march=native -fomit-frame-pointer -flto
CFLAGS = -pipe $(STANDARD)

SRC = 2020\\solution\\*.cpp

all: $(NAME)

$(NAME):
	@$(CC) $(WFLAGS) $(CFLAGS) $(OFLAGS) $(SRC) -o $@
