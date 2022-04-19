#!/usr/bin/env bash

rm -f texteditor

# Compile
CFLAGS='-g -fsanitize=address -fsanitize=undefined -Wall -std=c99'
if ! gcc $CFLAGS texteditor.c -o texteditor
then
    printf '\tFEHLER: Programm konnte nicht kompiliert werden.\n'
    exit 1
fi

# Check if copying from the internet
if grep -F "unistd.h" "texteditor.c" ; then
    printf '\tFEHLER: Inkludieren Sie getopt.h anstelle von unistd.h. Die Datei unistd.h ist Teil des POSIX-Standards, aber wir verwenden den C99-Standard.\n'
    exit 1
fi

function test_texteditor() {
    expected_return_value="$1"
    expected_output="$2"
    output="ausgabe.txt"

    # Run program and generate output
    (set -x ; ./texteditor "${@:3}" >& "$output")

    return_value="$?"

    # Check if return value is as expected
    if [ "$return_value" -eq "$expected_return_value" ]
    then
        printf '\tOK: Rückgabewert ist %s.\n' "$return_value"
    else
        printf '\tAusgabe:\n'
        cat "$output"
        printf '\n'
        printf '\tFEHLER: Rückgabewert %s entspricht nicht dem erwarteten Rückgabewert %s.\n' "$return_value" "$expected_return_value"
        exit 1
    fi

    if test -f "$expected_output"
    then
        # If expected_output is a file, check if the file contents match with output
        if diff -qyZ "$expected_output" "$output"
        then
            printf '\tOK: Ausgabe ist wie erwartet.\n'
        else
            printf '\tAusgabe : "%s"\n' "$(cat $output)"
            printf '\tErwartet: "%s"\n' "$(cat $expected_output)"
            printf '\tFEHLER: Ausgabe entspricht nicht erwarteter Ausgabe.\n'
            exit 1
        fi
    else
        # Check if output contains expected output
        if grep -Fq "$expected_output" "$output"
        then
            printf '\tOK: Ausgabe ist "%s".\n' "$expected_output"
        else
            printf '\tAusgabe:\n'
            cat "$output"
            printf '\n'
            printf '\tFEHLER: Ausgabe ist nicht "%s".\n' "$expected_output"
            exit 1
        fi
    fi

    printf 'Bestanden \n'
}

printf 'Prüfe einfache Ausgabe ohne zusätzliche Optionen.\n\n'

test_texteditor '0' 'erwartete_ausgabe/helloworld.txt' 'Hello, World!'

printf 'Prüfe Kleinschreibung.\n\n'

test_texteditor '0' 'erwartete_ausgabe/hallo.txt' 'HALLO!' -k

printf 'Prüfe Text einfügen, Parameter zuerst.\n\n'

test_texteditor '0' 'erwartete_ausgabe/12345.txt' -t ', ' '12345'

printf 'Prüfe Text einfügen, Parameter zuletzt.\n\n'

test_texteditor '0' 'erwartete_ausgabe/abc.txt' 'abc' -t '_'

printf 'Prüfe Text einfügen zusammen mit Kleinschreibung.\n\n'

test_texteditor '0' 'erwartete_ausgabe/gutgut.txt' -t '___' 'gutgut' -k

printf 'Prüfe langen Text einfügen zusammen mit Kleinschreibung.\n\n'

test_texteditor '0' 'erwartete_ausgabe/lang.txt' -t '-12345678901234567890123456789012345678901234567890-' 'abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz' -k

printf 'Prüfe nicht definierten Parameter.\n\n'

test_texteditor '1' 'Fehler' -x

printf 'Prüfe fehlenden Text.\n\n'

test_texteditor '1' 'Fehler'

printf 'Prüfe zu viele Texte.\n\n'

test_texteditor '1' 'Fehler' 'Text1' 'Text2'

printf 'Prüfe Hilfe.\n\n'

test_texteditor '0' 'Hilfe' -h

rm -f "$output" 'texteditor'
