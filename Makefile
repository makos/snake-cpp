CC=g++
# .c files here
SRCDIR=./src
# .h files here
IDIR=./include
# compiled .o files here
ODIR=./src/obj

CFLAGS=-I$(IDIR) -Wall -std=c++17 -fpermissive

# Header files here
_DEPS=player.hpp point.hpp entity.hpp render.hpp
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

# Object files here
_OBJ=main.o player.o point.o render.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

# Required libraries here
LIBS=-l:pdcurses.a

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.exe $(ODIR)/*.o