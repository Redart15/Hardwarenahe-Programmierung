#This is comment trying to make make work

all: main
test:
	./test.sh >t_result.txt
run:
	./main >test.txt
main: main.o zoo.o giraffe.o elefant.o
	gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99  *o -o main
main.o: main.c zoo.h
	gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99  -c main.c
zoo.o: zoo.c zoo.h giraffe.h elefant.h
	gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99 -c zoo.c
giraffe.o: giraffe.c giraffe.h
	gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99 -c giraffe.c
elefant.o: elefant.c elefant.h
	gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99 -c elefant.c
clean:
	rm -f *.o.txt *.o *main.txt main
