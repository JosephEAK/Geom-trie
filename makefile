CC ?= gcc
CFLAGS += -Wall --pedantic -g -Werror
LIB_PATH = .

all: clean lib
	$(CC) $(LDFLAGS) -L$(LIB_PATH) -o geometric $(CFLAGS) main.c -lcunit -lgeometric

lib:
	$(CC) -fPIC -c geometric.c
	$(CC) -shared -o libgeometric.so geometric.o -lcunit

test: clean lib
	$(CC) $(LDFLAGS) -L$(LIB_PATH) -o test_geometric $(CFLAGS) test_geometric.c -lgeometric -lcunit -lm

clean:
	rm -f *.o geometric libgeometric.so libgeometric.a