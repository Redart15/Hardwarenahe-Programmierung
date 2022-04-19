#!/usr/bin/env bash

if grep -qF "enum" bibliothek.h
then
    printf 'OK: Die Datei bibliothek.h enthält das Wort "enum".\n'
else
    printf 'FEHLER: Die Datei bibliothek.h enthält nicht das Wort "enum".\n'
    exit 1
fi

# Check output
for dateiname in \
    faellig1.txt \
    noch_nicht_faellig1.txt \
    faellig2.txt \
    noch_nicht_faellig2.txt
do
    output="ausgaben/$dateiname"
    expected_output="erwartete_ausgaben/$dateiname"

    if diff "$output" "$expected_output"
    then
        printf 'OK: %s entspricht %s.\n' "$output" "$expected_output"
    else
        printf 'FEHLER: Erwartete Ausgabe unterscheidet sich von tatsächlicher Ausgabe.\n\n'
        printf 'Erwartete Ausgabe (%s):\n' "$expected_output"
        cat "$expected_output"
        printf '\nTatsächliche Ausgabe (%s):\n' "$output"
        cat "$output"
        printf '\n'
        exit 1
    fi
done
