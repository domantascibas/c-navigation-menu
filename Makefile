IDIR =include
CC=g++
CFLAGS=-I$(IDIR)

SRCDIR=src
BINDIR=bin
ODIR=bin/obj
LDIR =lib

LIBS=-lm

_DEPS =
DEPS = $(patsubst %,$(IDIR)/%, $(_DEPS))

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)/out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(BINDIR)/*.exe

run:
	@bin/out.exe
