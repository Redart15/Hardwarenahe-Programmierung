tests:
	checkmk ringpuffer_tests.ts > ringpuffer_tests.c

compile: tests ringpuffer.c ringpuffer.h
	gcc -Wall -std=c99 -g ringpuffer.c ringpuffer_tests.c -o tests `pkg-config --cflags --libs check`

run: compile
	./tests

clean:
	rm -f ringpuffer_tests.c tests


