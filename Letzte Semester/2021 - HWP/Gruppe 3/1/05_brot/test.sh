#!/usr/bin/env bash

# Compile program
gcc -std=c99 -Wall -Werror automat.c -o automat

# Pipe input into program to generate output
./automat < eingabe.txt > ausgabe.txt

# Check if output matches expected output
if diff -y 'ausgabe.txt' 'erwartete_ausgabe.txt' > diff.txt
then
    printf 'OK: Ausgabe entspricht erwarteter Ausgabe.\n'
else
    printf 'FEHLER: Ausgabe entspricht nicht erwarteter Ausgabe. Details in "diff.txt".\n'
    exit 1
fi
