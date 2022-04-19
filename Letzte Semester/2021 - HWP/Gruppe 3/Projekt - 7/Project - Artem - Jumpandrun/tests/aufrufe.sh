#!/usr/bin/env bash

rm -rf ausgabe diff
mkdir -p ausgabe diff

# format:
# (input or "-" (stdin)) (output or "-" (stdout)) level
./jumpandrun < eingabe/1.txt > ausgabe/1.txt
./jumpandrun eingabe/2.txt ausgabe/2.txt level/2.txt
./jumpandrun - ausgabe/3.txt level/3.txt < eingabe/3.txt
./jumpandrun eingabe/4.txt - level/4.txt > ausgabe/4.txt
./jumpandrun eingabe/123.txt - level/1.txt level/2.txt level/3.txt > ausgabe/123.txt
./jumpandrun - ausgabe/24.txt level/2.txt level/4.txt < eingabe/24.txt

for name in 1 2 3 4 123 24
do
    input="eingabe/$name.txt"
    output="ausgabe/$name.txt"
    expected="erwartete_ausgabe/$name.txt"
    diff_file="diff/$name.txt"

    if diff -yZ "$output" "$expected" > "$diff_file"
    then
        printf '\tOK: %s stimmt mit %s überein.\n' "$expected" "$output"
    else
        printf '\tFEHLER: %s stimmt nicht mit %s überein. Details in %s.\n' "$expected" "$output" "$diff_file"
        exit 1
    fi
done

