CC=g++
# .c files here
SRCDIR=./src
# .h files here
IDIR=./include
# compiled .o files here
ODIR=./src/obj

TESTDIR=./tests
# TESTOBJDIR=./tests/obj

CFLAGS=-I$(IDIR) -Wall -std=c++17 

# Header files here
_DEPS=player.hpp point.hpp entity.hpp render.hpp game.hpp
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

# Object files here
_OBJ=main.o player.o point.o render.o game.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_TESTOBJ=test_Main.o test_Point.o test_Player.o player.o point.o
TESTOBJ=$(patsubst %,$(ODIR)/%,$(_TESTOBJ))

# Required libraries here
LIBS=-l:pdcurses.a

# Default build
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Test suite compilation
test: $(TESTOBJ) 
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(TESTDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean test-clean

clean:
	rm -f *.exe $(ODIR)/*.o

test-clean:
	rm -f *.exe $(TESTOBJDIR)/*.o