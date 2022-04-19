#!/usr/bin/env bash

name="studierende"

inputs=(
    studierende1.txt
    studierende1.txt
    studierende1.txt
    studierende1.txt
    studierende2.txt
)

outputs=(
    matrikelnummer_groesser_2999.txt
    semester_kleiner_5.txt
    informatikstudenten.txt
    informatikstudenten_datei.txt
    matrikelnummer_groesser_5000_mathematikstudenten.txt
)

# Compile program
CFLAGS='-g -fsanitize=address -fsanitize=undefined -Wall -std=c99'

if ! gcc $CFLAGS "$name.c" -o "$name"
then
    printf '\tFEHLER: Programm konnte nicht kompiliert werden.\n'
    exit 1
fi

# Create output
mkdir -p ausgaben
(set -x;
    "./$name" -g 2999 < "eingaben/${inputs[0]}" > "ausgaben/${outputs[0]}"
    "./$name" -k 5 < "eingaben/${inputs[1]}" > "ausgaben/${outputs[1]}"
    "./$name" -s Informatik < "eingaben/${inputs[2]}" > "ausgaben/${outputs[2]}"
    "./$name" -s Informatik "ausgaben/${outputs[3]}" < "eingaben/${inputs[3]}"
    "./$name" -g 5000 -s Mathematik "ausgaben/${outputs[4]}" < "eingaben/${inputs[4]}"
)

# Check output
for filename in ${outputs[*]}
do
    output="ausgaben/$filename"
    expected_output="erwartete_ausgaben/$filename"
    if diff "$output" "$expected_output"
    then
        printf 'OK: Datei "%s" stimmt mit erwarteter Ausgabe überein.\n' "$output"
    else
        printf 'FEHLER: Datei "%s" stimmt nicht mit erwarteter Ausgabe "%s" überein.\n' "$output" "$expected_output"
        diff -y "$output" "$expected_output"
        exit 1
    fi
done

rm -rf "$name" ausgaben
