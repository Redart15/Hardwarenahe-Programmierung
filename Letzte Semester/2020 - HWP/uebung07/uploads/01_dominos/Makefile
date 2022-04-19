compile: dominos.c dominos.h
	gcc dominos.c -o dominos -Wall -Wmissing-prototypes -Werror -std=c99 -g

clean:
	rm -f dominos
	rm -rf ausgabe
	rm -rf  diff
	rm -rf valgrind

testausgabe: compile eingabe/0.txt eingabe/5.txt eingabe/10.txt eingabe/20.txt eingabe/50.txt eingabe/100.txt eingabe/200.txt eingabe/500.txt eingabe/1000.txt erwartete_ausgabe/0.txt erwartete_ausgabe/5.txt erwartete_ausgabe/10.txt erwartete_ausgabe/20.txt erwartete_ausgabe/50.txt erwartete_ausgabe/100.txt erwartete_ausgabe/200.txt erwartete_ausgabe/500.txt erwartete_ausgabe/1000.txt
	mkdir -p ausgabe
	./dominos eingabe/0.txt ausgabe/0.txt
	./dominos eingabe/5.txt ausgabe/5.txt
	./dominos eingabe/10.txt ausgabe/10.txt
	./dominos eingabe/20.txt ausgabe/20.txt
	./dominos eingabe/50.txt ausgabe/50.txt
	./dominos eingabe/100.txt ausgabe/100.txt
	./dominos eingabe/200.txt ausgabe/200.txt
	./dominos eingabe/500.txt ausgabe/500.txt
	./dominos eingabe/1000.txt ausgabe/1000.txt

diff: clean compile testausgabe
	./diff.sh

valgrind_korrekte_eingabe: clean compile valgrind_korrekte_eingabe.sh
	./valgrind_korrekte_eingabe.sh

valgrind_fehlerhafte_eingabe: clean compile valgrind_fehlerhafte_eingabe.sh
	./valgrind_fehlerhafte_eingabe.sh

valgrind: valgrind_korrekte_eingabe valgrind_fehlerhafte_eingabe

run: diff valgrind
