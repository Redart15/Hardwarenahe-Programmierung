
tests:
	checkmk tiere_zaehlen_tests.ts > tiere_zaehlen_tests.c

gcc: tests
	gcc tiere_zaehlen.c tiere_zaehlen_tests.c -o tests -Wall -std=c99 -g `pkg-config --cflags --libs check`

run: gcc
	./tests

clean:
	rm -f tiere_zaehlen_tests.c tests


