
tests:
	checkmk caesar_plus2_klein_tests.ts > caesar_plus2_klein_tests.c

gcc: tests
	gcc caesar_plus2_klein.c caesar_plus2_klein_tests.c -o tests -Wall -std=c99 -g `pkg-config --cflags --libs check`

run: gcc
	./tests

clean:
	rm -f caesar_plus2_klein_tests.c tests
