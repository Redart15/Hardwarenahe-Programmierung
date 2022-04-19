Für diese Aufgabe benötigen Sie folgende zwei Dateien:

- gdb_2
- gdb_2.c.gpg
- test.sh

Sie können das Programm gdb_2 in gdb ausführen. Die Datei gdb_2.c.gpg ist
verschlüsselt. Das Passwort können Sie mittels gdb herausfinden. Es steht in
der Variablen pwd.

Entschlüsseln Sie die Datei mit folgendem Befehl:

gpg -d gdb_2.c.gpg

Leiten Sie die Ausgabe in die Datei gdb_2_loesung.c um und arbeiten Sie mit der C-Datei und gdb
weiter um die beiden Fehler zu finden.
