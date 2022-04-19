CFLAGS=-g -fsanitize=address -fsanitize=undefined -Wall -std=c99

run: ausgabe
	./test.sh

compile: supermarkt.c supermarkt.h ../02_datum/datum.c ../02_datum/datum.h
	gcc $(CFLAGS) supermarkt.c ../02_datum/datum.c -o supermarkt

ausgabe: compile
	./supermarkt eingabe/datum1.txt eingabe/kategorie1.txt eingabe/bezeichnung1.txt ausgabe1.txt 2021 05 06
	./supermarkt eingabe/datum2.txt eingabe/kategorie2.txt eingabe/bezeichnung2.txt ausgabe2.txt 2021 08 11

clean:
	rm -f supermarkt ausgabe1.txt ausgabe2.txt
