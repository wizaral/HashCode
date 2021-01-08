CC = g++
STANDARD = -std=c++17

WFLAGS = -Wall -Wextra -Werror -Wpedantic
OFLAGS = -Ofast -march=native -fomit-frame-pointer -flto
CFLAGS = -pipe $(STANDARD)

SRC = code\\*.cpp

all:
	@$(CC) $(WFLAGS) $(CFLAGS) $(OFLAGS) $(SRC)
