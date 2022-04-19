tests:
	checkmk strings_verbinden_tests.ts > strings_verbinden_tests.c

compile: tests
	gcc -Wall -std=c99 -g strings_verbinden.c strings_verbinden_tests.c -o tests `pkg-config --cflags --libs check`

run: compile
	./tests

clean:
	rm -f strings_verbinden_tests.c tests

