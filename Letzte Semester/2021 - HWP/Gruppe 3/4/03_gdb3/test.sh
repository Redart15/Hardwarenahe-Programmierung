#!/usr/bin/env bash

name='spielautomat'

rm -f "$name"

if sha256sum -c 'pruefsummen.txt'
then
    printf 'OK: Die C-Datei wurde nicht modifiziert.\n'
else
    printf 'FEHLER: Die C-Datei darf bei dieser Aufgabe nicht modifiziert werden!\n'
    exit 1
fi

if gcc -g -std=c99 -Wall "$name".c -o "$name"
then
    gdb -q "./$name" < gdb_eingabe.txt > ausgabe.txt

    function test_output_contains(){
        expected="$1"
        if grep -qF "$expected" ausgabe.txt
        then
            printf 'OK: Die Ausgabe enthält "%s".\n' "$expected"
        else
            cat ausgabe.txt
            printf 'FEHLER: Die Ausgabe enthält nicht "%s".\n' "$expected"
            exit 1
        fi
    }

    function test_output_does_not_contain(){
        not_expected="$1"
        if grep -qF "$not_expected" ausgabe.txt
        then
            cat ausgabe.txt
            printf 'FEHLER: Die Ausgabe enthält "%s".\n' "$not_expected"
            exit 1
        else
            printf 'OK: Die Ausgabe enthält nicht "%s".\n' "$not_expected"
        fi
    }

    test_output_contains 'Runde 1: 8 9 8'
    test_output_contains 'Runde 24: 4 1 2'
    test_output_does_not_contain 'Gewonnen!'
    for i in 0 1 2 3 4 5 6 7 8 9
    do
        test_output_does_not_contain ": $i $i $i"
    done

    rm -f "$name" ausgabe.txt
else
    printf 'Konnte nicht kompiliert werden.\n'
    exit 1
fi
