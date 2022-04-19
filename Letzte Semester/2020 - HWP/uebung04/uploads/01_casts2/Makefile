
tests:
	checkmk casts_tests.ts > casts_tests.c

gcc: tests
	gcc casts.c casts_tests.c -o tests -Wall -std=c99 -g `pkg-config --cflags --libs check`

run: gcc
	./tests

clean:
	rm -f casts_tests.c tests



