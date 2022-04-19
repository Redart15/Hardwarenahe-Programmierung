#!/usr/bin/env bash

program='./jumpandrun_fsanitize'

rm -rf ausgabe diff
mkdir -p ausgabe diff

for name in 1 2 3 4 5 6 7 8 decke beispiel2 beispiel3 eof lang
do
    level="level/$name.txt"
    input="eingabe/$name.txt"
    output="ausgabe/$name.txt"
    expected="erwartete_ausgabe/$name.txt"
    diff_file="diff/$name.txt"

    (set -x ; "$program" "$input" "$output" "$level")

    return_value="$?"

    if [ $return_value -eq 0 ]
    then
        printf '\tOK: Rückgabewert ist 0.\n'
    else
        printf '\tFEHLER: Rückgabewert ist nicht 0, sondern %s.\n' "$return_value"
        exit 6
    fi

    if diff -yZ "$output" "$expected" > "$diff_file"
    then
        printf '\tOK: %s stimmt mit %s überein.\n' "$expected" "$output"
    else
        printf '\tFEHLER: %s stimmt nicht mit %s überein. Details in %s.\n' "$expected" "$output" "$diff_file"
        exit 7
    fi

    printf '\n'
done
