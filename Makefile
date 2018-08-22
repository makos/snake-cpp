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
_DEPS=Entity.hpp Game.hpp Player.hpp PlayerPart.hpp Point.hpp Render.hpp State.hpp StateMenu.hpp StatePlaying.hpp
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

# Object files here
_OBJ=main.o Game.o Player.o PlayerPart.o Point.o Render.o StateMenu.o StatePlaying.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_TESTOBJ=test_Main.o test_Point.o test_Player.o Player.o Point.o
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