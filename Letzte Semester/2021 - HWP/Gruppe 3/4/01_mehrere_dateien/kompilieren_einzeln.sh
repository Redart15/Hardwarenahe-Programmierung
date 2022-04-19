gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99 -c mathematik.c
gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99 -c berechnung1.c
gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99 -c berechnung2.c
gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99 -c berechnung3.c
gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99 -c berechnung.c
gcc -g -fsanitize=address -fsanitize=undefined -Wall -std=c99 *.o -o berechnung
