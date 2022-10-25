CC ?= gcc
CFLAGS += -Wall --pedantic -Werror

all:
	$(CC) $(LDFLAGS) -o dames $(CFLAGS) dames.c dames_main.c

clean:
	rm -f *.o  dames