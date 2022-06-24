.PHONY := clean

CPPFLAGS := -std=c++17 -Wall -Wextra -pedantic
LDFLAGS :=
OBJECTS := main.o board.o move.o player.o

main: $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

clean:
	@rm -f main $(OBJECTS) > /dev/null 2>&1
