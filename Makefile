CC = g++
STANDARD = -std=c++17

2020 = slice.exe
2021 = pizza.exe

WFLAGS = -Wall -Wextra -Werror -Wpedantic
OFLAGS = -Ofast -march=native -fomit-frame-pointer -flto
DFLAGS = -g3 -O0 -fno-omit-frame-pointer -ftrapv
CFLAGS = -pipe $(STANDARD)

SRC20 = $(wildcard 2020/solution/*.cpp)
SRC21 = $(wildcard 2021/solution/*.cpp)

all: $(2020) $(2021)

$(2020): $(SRC20)
	@$(CC) $(CFLAGS) $(WFLAGS) $(OFLAGS) $^ -o $@

$(2021): $(SRC21)
	@$(CC) $(CFLAGS) $(WFLAGS) $(OFLAGS) $^ -o $@
