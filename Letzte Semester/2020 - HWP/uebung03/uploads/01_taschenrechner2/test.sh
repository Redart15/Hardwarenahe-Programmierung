#!/usr/bin/env bash

# Kompilieren.
gcc taschenrechner.c -o taschenrechner -Wall -std=c99 -g

echo -e "Prüfe Taschenrechner"

echo -e "\nTest ohne Parameter"
output=$(./taschenrechner)
if [ $output == "1" ]; then
    echo -e "\tOK: Ausgabe ist 1."
else
    echo -e "\tFEHLER: Ausgabe sollte 1 sein, ist aber stattdessen $output."
    exit 1
fi

echo -e "\nMultipliziere mit 10"
output=$(./taschenrechner -m 10)
if [ $output == "10" ]; then
    echo -e "\tOK: Ausgabe ist 10."
else
    echo -e "\tFEHLER: Ausgabe sollte 10 sein, ist aber stattdessen $output."
    exit 1
fi

echo -e "\nMultipliziere mit 20, dividiere durch 5"
output=$(./taschenrechner -m 20 -d 5)
if [ $output == "4" ]; then
    echo -e "\tOK: Ausgabe ist 4."
else
    echo -e "\tFEHLER: Ausgabe sollte 4 sein, ist aber stattdessen $output."
    exit 1
fi

echo -e "\nUnbenutzte Parameter 1, 10 und 99 sollen aufaddiert werden."
output=$(./taschenrechner 1 10 99)
if [ $output == "111" ]; then
    echo -e "\tOK: Ausgabe ist 111."
else
    echo -e "\tFEHLER: Ausgabe sollte 111 sein, ist aber stattdessen $output."
    exit 1
fi

echo -e "\nMit 10 multiplizieren, durch 5 dividieren, mit 20 multiplizieren und zum Schluss noch 60 und 100 addieren."
output=$(./taschenrechner -m 10 60 -d 5 -m 20 100)
if [ $output == "200" ]; then
    echo -e "\tOK: Ausgabe ist 200."
else
    echo -e "\tFEHLER: Ausgabe sollte 200 sein, ist aber stattdessen $output."
    exit 1
fi

echo -e "\nZeige Hilfe an"
output=$( ./taschenrechner -h )
if echo -e "$output" | egrep -iqo hilfe ; then
    echo -e "\tOK: Hilfe wird angezeigt."
else
    echo -e "\tFEHLER: Ausgabe ($output) enthält nicht das Wort \"Hilfe\"."
    exit 1
fi
