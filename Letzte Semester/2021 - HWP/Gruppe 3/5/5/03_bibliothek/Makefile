CFLAGS=-g -fsanitize=address -fsanitize=undefined -Wall -std=c99

run: ausgabe
	./ausgabe_pruefen.sh

compile: bibliothek.c bibliothek.h ../02_datum/datum.c ../02_datum/datum.h
	gcc $(CFLAGS) bibliothek.c ../02_datum/datum.c -o bibliothek

ausgabe: compile
	mkdir -p ausgaben
	./bibliothek eingaben/eingabe1.txt ausgaben/faellig1.txt ausgaben/noch_nicht_faellig1.txt 2021 05 06
	./bibliothek eingaben/eingabe2.txt ausgaben/faellig2.txt ausgaben/noch_nicht_faellig2.txt 2021 04 04

clean:
	rm -rf bibliothek ausgaben
