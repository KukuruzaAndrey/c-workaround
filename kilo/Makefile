all: kilo r c

kilo: kilo.c
	$(CC) kilo.c -o kilo -Wall -Wextra -pedantic -std=c17

r: kilo
	./kilo

c:
	rm -f kilo
