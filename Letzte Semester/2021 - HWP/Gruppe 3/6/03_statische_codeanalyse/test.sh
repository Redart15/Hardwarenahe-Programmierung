printf 'Programme zur statischen Code-Analysie werden ausgeführt.\n'
printf 'Denken Sie daran, die Programme vorher zu installieren (siehe install.sh).\n'
printf 'Die Ausgabe wird in den Ordner "Beispielausgabe" geschrieben.\n'
printf '\n'

mkdir -p Beispielausgabe

(set -x
    cppcheck --enable=all --suppress=missingIncludeSystem main.c &> Beispielausgabe/cppcheck_output.txt
    clang-tidy --checks='-*,clang-analyzer-*' main.c -- &> Beispielausgabe/clang_tidy_output.txt
    gcc -O3 -Wall -Wextra main.c &> Beispielausgabe/gcc_output.txt
)

rm -f a.out

printf '\nDiese Tests werden nicht überprüft, da dies keine Pflichtaufgabe ist. Schauen Sie trotzdem in den Ordner "Beispielausgabe" und bewundern Sie die hilfreichen Anmerkungen, die von den Programmen generiert wurden.\n'

