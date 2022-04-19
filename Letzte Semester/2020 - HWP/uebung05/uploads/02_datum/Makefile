tests:
	checkmk datum_tests.ts > datum_tests.c

compile: tests datum.c datum.h
	gcc -Wall -std=c99 -g datum.c datum_tests.c -o tests `pkg-config --cflags --libs check`

run: compile
	./tests

clean:
	rm -f datum_tests.c tests ausgabe.txt

