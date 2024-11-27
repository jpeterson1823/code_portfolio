#https://cs.colby.edu/maxwell/courses/tutorials/maketutor/ 

IDIR = ./include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR = ./src/obj
LDIR = ./lib

LIBS=-lm

_DEPS = nodes.h
DEPS = $(patsubst %, $(IDIR)/%,$(_DEPS))

_OBJ = main.o nodes.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

SRCDIR = ./src

$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~
