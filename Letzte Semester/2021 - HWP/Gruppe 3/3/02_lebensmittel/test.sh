#!/usr/bin/env bash

name="lebensmittel"

inputs=(
    lebensmittel1.txt
    lebensmittel1.txt
    lebensmittel1.txt
    lebensmittel1.txt
    lebensmittel2.txt
)

outputs=(
    sechs_tage_haltbar.txt
    ei.txt
    about_3_50_or_less.txt
    dateiausgabe_1_00_oder_billiger.txt
    billig_und_drei_tage_haltbar.txt
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
    "./$name" -d 6 < "eingaben/${inputs[0]}" > "ausgaben/${outputs[0]}"
    "./$name" -b Ei < "eingaben/${inputs[1]}" > "ausgaben/${outputs[1]}"
    "./$name" -p 3.50 < "eingaben/${inputs[2]}" > "ausgaben/${outputs[2]}"
    "./$name" -p 1.00 "ausgaben/${outputs[3]}" < "eingaben/${inputs[3]}"
    "./$name" -p 0.25 -d 3 "ausgaben/${outputs[4]}" < "eingaben/${inputs[4]}"
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
