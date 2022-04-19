#!/usr/bin/env bash

# Für mehr Informationen zu valgrind:
# https://valgrind.org/docs/manual/mc-manual.html

rm -rf ausgabe diff valgrind
mkdir -p ausgabe diff valgrind

outputfile='valgrind/temporary_output.txt'

if sha256sum -c 'tests/pruefsummen.txt' ; then
    printf '\tOK: Testdateien wurden nicht modifiziert.\n\n'
else
    printf '\./tFEHLER: Eine oder mehrere Testdateien wurden modifiziert.\n\n'
    exit 1
fi

for name in 1 2 3 4 5 6 7 8
do
    input="eingabe/$name.txt"
    output="ausgabe/$name.txt"
    level="level/$name.txt"
    expected="erwartete_ausgabe/$name.txt"
    logfile="valgrind/$name.txt"
    diff_file="diff/$name.txt"

    (set -x ; valgrind \
        --leak-check=full \
        --show-leak-kinds=all \
        --track-origins=yes \
        --log-file="$logfile" \
        ./jumpandrun "$input" "$output" "$level" )

    return_value="$?"

    if [ $return_value -eq 0 ]; then
        printf '\tOK: Rückgabewert ist 0.\n'
    else
        printf '\tFEHLER: Rückgabewert ist nicht 0, sondern %s.\n' "$return_value"
        exit 5
    fi

    if ! tests/valgrind_log_pruefen.sh "$logfile" ; then
        exit 1
    fi

    if diff -yZ "$output" "$expected" > "$diff_file"
    then
        printf '\tOK: %s stimmt mit %s überein.\n' "$expected" "$output"
    else
        printf '\tFEHLER: %s stimmt nicht mit %s überein. Details in %s.\n' "$expected" "$output" "$diff_file"
        exit 1
    fi

    printf '\n'
done
