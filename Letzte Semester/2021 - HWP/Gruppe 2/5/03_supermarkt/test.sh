#!/usr/bin/env bash

if grep -qF "enum" supermarkt.h
then
    printf 'OK: Die Datei supermarkt.h enthält das Wort 'enum'.\n'
else
    printf 'FEHLER: Die Datei supermarkt.h enthält nicht das Wort 'enum'.\n'
    exit 1
fi

# Check output
for i in 1 2
do
    output="ausgabe$i.txt"
    expected_output="erwartete_ausgabe/ausgabe$i.txt"

    if diff "$output" "$expected_output"
    then
        printf 'OK: %s entspricht %s.\n' "$output" "$expected_output"
    else
        printf 'FEHLER: Erwartet:\n'
        cat "$expected_output"
        printf 'Tatsächliche Ausgabe:\n'
        cat "$output"
        exit 1
    fi
done
