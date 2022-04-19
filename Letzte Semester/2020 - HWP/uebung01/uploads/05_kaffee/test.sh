#!/usr/bin/env bash

name="kaffee"
program="./kaffee"
pluralname="Kaffee"
printname="KAFFEE"
expected_numbers=(2 100 100)

# Compile program
gcc -std=c99 -Wall "$name.c" -o $name

for i in 0 1 2
do
    echo "Prüfe eingabe$i.txt"

    input="eingabe$i.txt"
    output="ausgabe$i.txt"

    rm -f $output

    # Pipe input to program and create output
    cat $input | $program > $output

    # For each word that would be expected in output
    for expected in $(cat "erwartete_woerter$i.txt")
    do
        # Check if word occurs in output
        if grep -qw $expected $output; then
            echo -e "\tOK: \"$expected\" kommt in Ausgabe vor."
        else
            echo -e "\tFEHLER: \"$expected\" kommt nicht in Ausgabe vor."
            exit 1
        fi
    done

    # Count objects
    n=$(grep $printname $output | wc -l)

    # Get expected number of objects
    n_expected=${expected_numbers[i]}

    # Compare expected and actual number of objects
    if [ "$n" == "$n_expected" ]; then
        echo -e "\tOK: $n_expected $pluralname ausgegeben."
    else
        echo -e "FEHLER: $n_expected $pluralname erwartet, aber $n bekommen."
        exit 2
    fi

    rm $output
done
