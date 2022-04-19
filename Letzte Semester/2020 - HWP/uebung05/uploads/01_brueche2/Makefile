tests:
	checkmk bruch_tests.ts > bruch_tests.c

compile: tests bruch.c bruch.h
	gcc -Wall -std=c99 -g bruch.c bruch_tests.c -o tests `pkg-config --cflags --libs check`

run: compile
	./tests

clean:
	rm -f bruch_tests.c tests

