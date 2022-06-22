.PHONY := clean

CPPFLAGS := -Wall -Wextra -pedantic
LDFLAGS :=
OBJECTS := main.o board.o

main: $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

clean:
	@rm -f main $(OBJECTS) > /dev/null 2>&1
