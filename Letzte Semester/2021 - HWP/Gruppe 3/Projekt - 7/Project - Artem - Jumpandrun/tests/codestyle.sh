printf 'Die Code-Vorgaben werden nur teilweise automatisch getestet.\n'
printf 'Lesen Sie sich die Code-Vorgaben im Lernmodul nochmal aufmerksam durch,\n'
printf 'um sicherzugehen, dass Sie sie auch einhalten.\n'
printf 'Zum Beispiel ist die Verwendung von globalen Variablen verboten.\n\n'

if ! gcc -g -Wall -std=c99 -x c tests/codestyle_check -o tests/codestyle
then
    printf 'FEHLER: Konnte Programm zur Überprüfung der Code-Vorgaben nicht kompilieren.\n'
    exit 1
fi

if ! tests/codestyle
then
    rm -f tests/codestyle
    printf 'FEHLER: Codevorgaben nicht eingehalten.\n'
    exit 1
fi

rm -f tests/codestyle
