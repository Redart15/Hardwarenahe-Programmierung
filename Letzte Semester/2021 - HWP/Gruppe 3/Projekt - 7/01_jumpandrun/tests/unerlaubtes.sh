#!/usr/bin/env bash

function check_disallowed() {
    disallowed="$1"
    if grep -rF --include='*.c' --include='*.h' "$disallowed" .
    then
        printf '\n'
        printf 'FEHLER: Die Verwendung von %s ist nicht erlaubt, da nicht Teil des C99-Standards.\n' "$disallowed"
        printf 'Falls Sie durch das Kapitel "16.26 Low-Level-Datei-I/O-Funktionen ---> (nicht ANSI C) <---"\n'
        printf 'aus dem Buch "C von A bis Z" auf diese Idee gekommen sind, dann haben Sie möglicherweise\n'
        printf 'eine interessante Funktion, die vorher in Kapitel 16 genannt wurde, verpasst.\n\n'
        exit 9
    fi
}

function check_disallowed_c99() {
    disallowed="$1"
    if grep -rF --include='*.c' --include='*.h' "$disallowed" .
    then
        printf '\n'
        printf 'FEHLER: Die Verwendung von %s ist nicht erlaubt, da nicht Teil des C99-Standards.\n\n' "$disallowed"
        exit 9
    fi
}

function check_disallowed_too_hard_to_use() {
    disallowed="$1"
    if grep -rF --include='*.c' --include='*.h' "$disallowed" .
    then
        printf '\n'
        printf 'FEHLER: Die Verwendung von "%s" ist nicht erlaubt, da "%s" in der Regel falsch verwendet wird.\n\n' "$disallowed" "$disallowed"
        exit 9
    fi
}

check_disallowed 'fcntl.h'
check_disallowed '<io.h>'
check_disallowed '"io.h"'
check_disallowed 'sys/types.h'
check_disallowed 'sys/stat.h'
check_disallowed 'unistd.h'
check_disallowed 'dirent.h'
check_disallowed 'S_ISREG'
check_disallowed 'S_ISDIR'
check_disallowed 'F_OK'
check_disallowed 'R_OK'
check_disallowed 'W_OK'
check_disallowed 'X_OK'
check_disallowed 'O_CREAT'
check_disallowed 'O_WRONLY'
check_disallowed 'POSIX'
check_disallowed 'GNU_'
check_disallowed 'opendir'

check_disallowed_c99 'strlcat'
check_disallowed_c99 'strlcpy'
check_disallowed_c99 'strdup'

check_disallowed_too_hard_to_use 'ungetc'
check_disallowed_too_hard_to_use 'errno'
check_disallowed_too_hard_to_use 'pragma'
check_disallowed_too_hard_to_use 'static'
check_disallowed_too_hard_to_use 'goto'

if grep -rP --include='*.c' --include='*.h' '\d\d\d+' .
then
    printf '\n'
    printf 'MÖGLICHERWEISE FEHLER: Im Code wird eine Zahl größer als 99 verwendet.\n'
    printf 'Eine große Zahl ist häufig ein Indiz dafür, dass etwas nicht dynamisch alloziert wird.\n'
    printf 'Oder möglicherweise verwenden Sie Zahlen anstelle von Character-Konstanten,\n'
    printf "z.B. 65 an Stelle von 'A', was zwar technisch nicht falsch, aber zumindest unschön ist.\n\n"
    exit 9
fi
