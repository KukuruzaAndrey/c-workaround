all: kilo run

kilo: kilo.c
	$(CC) kilo.c -o kilo -Wall -Wextra -pedantic -std=c17

run: kilo
	./kilo

clean:
	rm -f kilo
