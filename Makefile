LIBDIRS=. ./lib
INCDIRS=./include
COMP=clang++
CFLAGS=-Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer -O0 -std=c++17
BIN=bin
BUILDDIR=.build

CFILES=$(foreach D,$(LIBDIRS),$(wildcard $(D)/*.cpp))

OBJS=$(patsubst %.cpp,%.o,$(CFILES))

.DEFAULT_GOAL:all

all:$(BIN)

$(BIN):$(OBJS)	
	$(COMP) $(CFLAGS) -g $^ -o $@


%.o:%.cpp
	$(COMP) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BIN) $(OBJS)


