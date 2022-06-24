.PHONY := clean

CPPFLAGS := -g -std=c++17 -Wall -Wextra -pedantic
LDFLAGS :=
OBJECTS := main.o board.o move.o player.o game.o

main: $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

clean:
	@rm -f main $(OBJECTS) > /dev/null 2>&1
