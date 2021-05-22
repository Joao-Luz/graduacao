CC = gcc

CFLAGS = -Wall -g

LDFLAGS = -lm

FONTES = $(wildcard *.c)

OBJETOS = $(FONTES:.c=.o)

EXECUTAVEL = descompacta

all: $(EXECUTAVEL) clean

$(EXECUTAVEL): $(OBJETOS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf *.o

rmproper: clean
	rm -r $(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)
