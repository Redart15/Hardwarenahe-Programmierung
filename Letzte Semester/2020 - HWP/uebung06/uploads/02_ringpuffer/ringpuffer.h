
typedef struct {
    /* Die Struktur soll mindestens die Elemente pos, size und strings haben. */
    /* Wählen Sie geeignete Datentypen! */
    int pos;
    int size;
    char** strings;


} buffer;

/* Erstellt einen leeren Puffer der Größe "size". */
buffer* init(int size);

/* Fügt ein Element in den gegebenen Puffer ein. */
void add(char *new_string, buffer *buf);

/* Entfernt das zuletzt eingefügte Element aus dem Puffer. */
void remove_last(buffer *buf);

/* Gibt den gesamten Puffer wieder frei (ohne Unittests, überprüfen Sie dies mit valgrind). */
void free_buf(buffer *buf);

/* Gibt den gesamten Puffer auf der Konsole aus (ohne Unittests, bereits implementiert)*/
void print(buffer* buf);

/* Platz für eigene Funktionen
 *   ... */
