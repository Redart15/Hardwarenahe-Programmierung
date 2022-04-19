#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ringpuffer.h"

void print(buffer* buf){
    if(buf == NULL){
        printf("Der Puffer existiert nicht.\n");
        return;
    }
    printf("Der Puffer hat Größe %i\n", buf->size);
    int pos = buf->pos -1;
    printf("Alle Strings im Puffer:\n");
    for(int i = 0; i < buf->size; i++){
        int j = pos-i;
        if (j < 0) j+=buf->size;
        if(buf->strings[j] != NULL) printf("\t%s\n", buf->strings[j]);
    }
}

/* Implementieren Sie hier Ihre Funktionen. */
/* Erstellt einen leeren Puffer der Größe "size". */
buffer* init(int size){
    buffer *b = malloc(sizeof(buffer));
    b->pos = 0;
    b->size = size;
    b->strings = malloc(sizeof(char*)*size);
    for(int i = 0; i < size; i++){
        b->strings[i] = NULL;
    }
    return b;
}

/* Fügt ein Element in den gegebenen Puffer ein. */
void add(char *new_string, buffer *buf){
    if(buf->strings[buf->pos]){
        free(buf->strings[buf->pos]);
    }
    buf->strings[buf->pos] = malloc(sizeof(char)*(strlen(new_string)+1));
    strcpy(buf->strings[buf->pos], new_string);
    buf->pos = (buf->pos + 1) % buf->size;
}

/* Entfernt das zuletzt eingefügte Element aus dem Puffer. */
void remove_last(buffer *buf){
    buf->pos = ((buf->pos - 1) < 0) ? buf->size-1 : buf->pos - 1;
    if(buf->strings[buf->pos]){
        free(buf->strings[buf->pos]);
        buf->strings[buf->pos] = NULL;
    }
}

/* Gibt den gesamten Puffer wieder frei (ohne Unittests, überprüfen Sie dies mit valgrind). */
void free_buf(buffer *buf){
    for (int i = 0; i < buf->size; i++)
    {
        if(buf->strings){
            if(buf->strings[i]){
                free(buf->strings[i]);
            }
        }
    }
    free(buf->strings);
    free(buf);
}