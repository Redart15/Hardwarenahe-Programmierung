name=snake_case
CFLAGS=-g -fsanitize=address -fsanitize=undefined -Wall -std=c99 `pkg-config --cflags check`
LFLAGS=`pkg-config --libs check`

$(name)_tests.c: $(name)_tests.ts
	checkmk $(name)_tests.ts > $(name)_tests.c

compile: $(name).c $(name).h $(name)_tests.c
	gcc $(CFLAGS) $(name).c $(name)_tests.c -o tests $(LFLAGS)

run: compile
	./tests

$(name): $(name).c main.c
	gcc $(CFLAGS) $(name).c main.c -o $(name)

clean:
	rm -f $(name)_tests.c tests $(name)
