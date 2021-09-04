IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

BINS=../bin

_DEPS = event_mang.h mod_event.h struct_head.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = event_manager.o init.o module.o
OBJ = $(patsubst %,$(BINS)/%,$(_OBJ))


$(BINS)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINS)/event_manager: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

