#!/usr/bin/env bash

if gcc main.c studenten.c ../02_datum/datum.c -std=c99 -Wall -g -o main ;then

    ./main < studenten_eingabe.txt > studenten_ausgabe.txt

    if diff studenten_ausgabe.txt studenten_erwartete_ausgabe.txt ;then
        echo -e "OK: Ausgabe ist wie erwartet."
    else
        echo -e "FEHLER: Ausgaben unterscheiden sich:"
        diff studenten_ausgabe.txt studenten_erwartete_ausgabe.txt
        exit 1
    fi

    rm -f studenten_ausgabe.txt main

else
    echo -e "FEHLER: Datei konnte nicht kompiliert werden."
    exit 1
fi
