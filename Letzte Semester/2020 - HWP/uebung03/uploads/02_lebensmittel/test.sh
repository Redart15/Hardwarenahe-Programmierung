#!/usr/bin/env bash

name="lebensmittel"

eingaben=(
    lebensmittel1.txt
    lebensmittel1.txt
    lebensmittel1.txt
    lebensmittel1.txt
    lebensmittel2.txt
)

ausgaben=(
    hundert_tage_haltbar.txt
    ei.txt
    abgelaufen.txt
    abgelaufen_datei.txt
    abgelaufen_min_4_tage_haltbar.txt
)

# Kompilieren
gcc "$name.c" -o "$name" -Wall -std=c99 -g

# Ausgaben erzeugen.
mkdir -p ausgaben
"./$name" -m 100 < eingaben/${eingaben[0]} > ausgaben/${ausgaben[0]}
"./$name" -b Ei < eingaben/${eingaben[1]} > ausgaben/${ausgaben[1]}
"./$name" -a < eingaben/${eingaben[2]} > ausgaben/${ausgaben[2]}
"./$name" -a ausgaben/${ausgaben[3]} < eingaben/${eingaben[3]}
"./$name" -a -m 4 ausgaben/${ausgaben[4]} < eingaben/${eingaben[4]}

# Ausgaben vergleichen.
for ausgabe in ${ausgaben[*]} ; do
    if diff ausgaben/$ausgabe erwartete_ausgaben/$ausgabe ; then
        echo -e "OK: \"ausgabe/$ausgabe\" stimmt mit erwarteter Ausgabe überein."
    else
        echo -e "FEHLER: \"ausgabe/$ausgabe\" stimmt nicht mit der erwarteten Ausgabe \"erwartete_ausgabe/$ausgabe\" überein:"
        diff -y ausgaben/$ausgabe erwartete_ausgaben/$ausgabe
        exit 1
    fi
done

rm -f lebensmittel
rm -rf ausgaben
