#!/usr/bin/env bash

logfile="valgrind_log.txt"

# Kompilieren
if gcc -g liste.c -std=c99 -g -Wall -o liste
then
    for i in 1 2
    do
        # Programm ausführen und mit valgrind überprüfen
        valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$logfile ./liste eingabe$i.txt ausgabe$i.txt

        # Ausgabe überprüfen
        if diff ausgabe$i.txt erwartete_ausgabe$i.txt ;then
            echo -e "\tOK: Ausgabe ist wie erwartet."
        else
            echo -e "\tFEHLER: Ausgaben unterscheiden sich:"
            diff -y ausgabe$i.txt erwartete_ausgabe$i.txt
            exit 1
        fi

        # Speicherlecks suchen
        if grep -E "definitely lost: [1-9][0-9,]* bytes" $logfile ; then
            echo -e -e "\tFEHLER: Speicherleck gefunden. Details in Datei $logfile."
            exit 2
        else
            echo -e "\tOK: Speichertest 1"
        fi

        if grep -E "indirectly lost: [1-9][0-9,]* bytes" $logfile ; then
            echo -e "\tFEHLER: Speicherleck gefunden. Details in Datei $logfile."
            exit 2
        else
            echo -e "\tOK: Speichertest 2"
        fi

        if grep -E "possibly lost: [1-9][0-9,]* bytes" $logfile ; then
            echo -e "\tFEHLER: Speicherleck gefunden. Details in Datei $logfile."
            exit 2
        else
            echo -e "\tOK: Speichertest 3"
        fi

        if grep -E "still reachable: [1-9][0-9,]* bytes" $logfile ; then
            echo -e "\tFEHLER: Speicherleck gefunden. Details in Datei $logfile."
            exit 2
        else
            echo -e "\tOK: Speichertest 4"
        fi

        if grep -E "in use at exit: [1-9][0-9,]* bytes" $logfile ; then
            echo -e "\tFEHLER: Speicherleck gefunden. Details in Datei $logfile."
            exit 2
        else
            echo -e "\tOK: Speichertest 5"
        fi

        # Speicherzugriffsfehler suchen
        if grep -E "Invalid free()" $logfile ; then
            echo -e "\tFEHLER: Invalid free gefunden. Details in Datei $logfile."
            exit 2
        else
            echo -e "\tOK: Invalid free test"
        fi

        if grep -E "Invalid read of size" $logfile ; then
            echo -e "\tFEHLER: Invalid read gefunden. Details in Datei $logfile."
            exit 2
        else
            echo -e "\tOK: Invalid read test"
        fi

        if grep -E "Invalid write of size" $logfile ; then
            echo -e "\tFEHLER: Invalid write gefunden. Details in Datei $logfile."
            exit 2
        else
            echo -e "\tOK: Invalid write test"
        fi

        # Verwendung von uninitialisierten Variablen prüfen
        if grep -E "depends on uninitialised value" $logfile ; then
            echo -e "\tFEHLER: Uninitialisierte Variablen verwendet. Details in Datei $logfile."
            exit 2
        else
            echo -e "\tOK: Nur initialisierte Variablen verwendet"
        fi

        echo -e ""

        # Aufräumen
        rm -f ausgabe$i.txt $logfile
    done

    rm -f liste
else
    echo -e "Programm konnte nicht kompiliert werden."
    exit 1
fi
