CC = g++
STANDARD = -std=c++17

2020 = slice.exe
2021 = pizza.exe

WFLAGS = -Wall -Wextra -Werror -Wpedantic
OFLAGS = -Ofast -march=native -fomit-frame-pointer -flto
DFLAGS = -g3 -O0 -fno-omit-frame-pointer -ftrapv
CFLAGS = -pipe $(STANDARD)

INC20 = -I 2020/solution/inc
INC21 = -I 2021/solution/inc

SRC20 = $(wildcard 2020/solution/src/*.cpp)
SRC21 = $(wildcard 2021/solution/src/*.cpp)

all: $(2020) $(2021)

$(2020): $(SRC20)
	@$(CC) $(CFLAGS) $(WFLAGS) $(OFLAGS) $(INC20) $^ -o $@

$(2021): $(SRC21)
	@$(CC) $(CFLAGS) $(WFLAGS) $(OFLAGS) $(INC21) $^ -o $@
