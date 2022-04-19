#!/usr/bin/env bash

name='roulette'

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

    function test_output(){
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

    test_output 'Runde 1: 35'
    test_output 'Runde 9: 33'
    test_output 'Runde 10: 36'
    test_output 'Runde 11: 28'
    test_output 'Runde 12: 31'
    test_output 'Runde 30: 34'
    test_output 'Runde 45: 23'
    test_output 'Runde 46: 36'
    test_output 'Runde 47: 25'
    test_output 'Runde 50: 28'

    rm -f "$name" ausgabe.txt
else
    printf 'Konnte nicht kompiliert werden.\n'
    exit 1
fi
