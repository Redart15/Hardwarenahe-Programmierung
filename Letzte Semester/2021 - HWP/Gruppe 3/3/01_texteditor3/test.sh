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

    printf '\n'
}

printf 'Prüfe einfache Ausgabe ohne zusätzliche Optionen.\n\n'

test_texteditor '0' 'Hello, World!' 'Hello, World!'

printf 'Prüfe nicht definierten Parameter.\n\n'

test_texteditor '1' 'Fehler' -x

printf 'Prüfe fehlenden Text.\n\n'

test_texteditor '1' 'Fehler'

printf 'Prüfe zu viele Texte.\n\n'

test_texteditor '1' 'Fehler' 'Text1' 'Text2'

printf 'Prüfe Hilfe.\n\n'

test_texteditor '0' 'Hilfe' -h

printf 'Prüfe Startzahl.\n\n'

test_texteditor '0' 'erwartete_ausgabe/100.txt' 'Hundertste Zeile
Hundertunderste Zeile' -s 100

printf 'Prüfe Text einfügen, Parameter zuerst.\n\n'

test_texteditor '0' 'erwartete_ausgabe/zwei_zeilen.txt' -t '. ' 'Erste Zeile
Zweite Zeile'

printf 'Prüfe Text einfügen, Parameter zuletzt.\n\n'

test_texteditor '0' 'erwartete_ausgabe/123.txt' 'Eins
Zwei
Drei' -t ' - '

printf 'Prüfe Text einfügen zusammen mit Startzahl.\n\n'

test_texteditor '0' 'erwartete_ausgabe/10_11.txt' -t ': ' 'Zehnte Zeile
Elfte Zeile' -s 10

printf 'Prüfe Text einfügen zusammen mit Startzahl mit langen Texten.\n\n'

test_texteditor '0' 'erwartete_ausgabe/lang.txt' -t ' 01234567890123456789012345678901234567890123456789 ' 'Millionste Zeile
Zeile danach
Noch eine Zeile
Eine weitere Zeile
Und noch eine weitere Zeile
Dir vorvorvorvorvorvorletzte Zeile
Dir vorvorvorvorvorletzte Zeile
Dir vorvorvorvorletzte Zeile
Dir vorvorvorletzte Zeile
Dir vorvorletzte Zeile
Die vorletzte Zeile
Letzte Zeile' -s 1000000

rm -f "$output" 'texteditor'
