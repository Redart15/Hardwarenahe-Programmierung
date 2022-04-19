#include "dominos.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return 1;
    }
    FILE *in = fopen(argv[1], "r");
    if (!in)
    {
        return 2;
    }
    domino *alle_dominos = malloc(sizeof(domino));
    int domino_anzahl = dominos_einlesen(in, &alle_dominos);
    fclose(in);
    if (domino_anzahl < 1)
    {
        FILE *out = fopen(argv[2], "w");

        fclose(out);
        free(alle_dominos);
        return 0;
    }

    char **domino_feld = malloc(sizeof(char *));
    domino_feld[0] = malloc(10 * sizeof(char));
    memset(domino_feld[0], ' ', 10);

    int feld_hoehe = 1;
    if (alle_dominos[0].direction == 1 || alle_dominos[0].direction == 3)
    {
        domino_feld = realloc(domino_feld, 2 * sizeof(char *));
        domino_feld[1] = malloc(10 * sizeof(char));
        memset(domino_feld[1], ' ', 10);
        feld_hoehe += 1;
    }

    if (alle_dominos[0].direction == 2 || alle_dominos[0].direction == 3)
    {
        domino_feld[0][0] = alle_dominos[0].outer + '0';
        int i_offset = (alle_dominos[0].direction == 2) ? 0 : 1;
        int j_offset = (alle_dominos[0].direction == 2) ? 1 : 0;
        domino_feld[i_offset][j_offset] = alle_dominos[0].inner + '0';
    }
    else
    {
        domino_feld[0][0] = alle_dominos[0].inner + '0';
        int i_offset = (alle_dominos[0].direction == 1) ? 1 : 0;
        int j_offset = (alle_dominos[0].direction == 1) ? 0 : 1;
        domino_feld[i_offset][j_offset] = alle_dominos[0].outer + '0';
    }

    for (int i = 1; i < domino_anzahl; i++)
    {
        domino_einfuegen(&domino_feld, &feld_hoehe, alle_dominos[i]);
    }
    int breite = berechne_breite(domino_feld, feld_hoehe);
    int returnwert = 0;

    printe_feld(&returnwert, argv[2], domino_feld, feld_hoehe, breite);

    free(alle_dominos);
    for (int i = 0; i < feld_hoehe; i++)
    {
        free(domino_feld[i]);
    }
    free(domino_feld);
    return returnwert;
}

int dominos_einlesen(FILE *in, domino **domino_arr)
{
    int domino_length = 0;
    
    int scan_buffer = 0;
    char buffer[8];
    while (fgets(buffer, 8, in))
    {
        int inner = 0, outer = 0, direction = 0;
        scan_buffer = sscanf(buffer, "%d %d %d", &inner, &outer, &direction);
        if (inner > 6 || inner < 0 || outer > 6 || outer < 0 || direction > 3 || direction < 0 || scan_buffer != 3)
        {
            free(*domino_arr);
            fclose(in);
            exit(3);
        }
        if (domino_length > 0)
        {
            *domino_arr = realloc(*domino_arr, sizeof(domino) * (domino_length + 1));
        }
        domino buffer = {inner, outer, direction};
        dominocpy(&(*domino_arr)[domino_length], buffer);
        domino_length++;
    }
    return domino_length;
}

void domino_einfuegen(char ***feld, int *hoehe, domino d)
{
    int platziert = 0;
    for (int i = 0; i < *hoehe; i++)
    {
        if (platziert)
            break;
        for (int j = 0; j < 10; j++)
        {
            if (platzierbar(*feld, *hoehe, i, j, d))
            {
                platziere(feld, i, j, d);
                platziert = 1;
                break;
            }
        }
    }
    if (!platziert)
    { //wenn nicht platziert, guck ob mans obendrauf platzieren kann
        for (int p = 1; p <= 2 && !platziert; p++)
        {

            *feld = realloc(*feld, sizeof(char *) * (*hoehe + p));
            (*feld)[*hoehe + p - 1] = malloc(10 * sizeof(char));
            memset((*feld)[*hoehe + p - 1], ' ', 10);

            for (int i = *hoehe - 1; i < *hoehe + p; i++)
            {
                if (platziert)
                    break;
                for (int j = 0; j < 10; j++)
                {
                    char org = (*feld)[i][j];
                    (*feld)[i][j] = '*';
                    (*feld)[i][j] = org;
                    if (platzierbar(*feld, *hoehe + p, i, j, d))
                    {
                        platziere(feld, i, j, d);
                        *hoehe += p;
                        platziert = 1;
                        break;
                    }
                }
            }
        }
    }

    if (!platziert)
    { //falls immernoch nicht platziert, zusätzliche zeilen entfernen
        free((*feld)[*hoehe + 1]);
        free((*feld)[*hoehe]);
        *feld = realloc(*feld, sizeof(char *) * (*hoehe));
    }
}

void platziere(char ***feld, int i, int j, domino d)
{
    (*feld)[i][j] = d.inner + '0';
    int outer_i, outer_j;
    switch (d.direction)
    {
    case 0:
        outer_i = i;
        outer_j = j + 1;
        break;
    case 1:
        outer_i = i + 1;
        outer_j = j;
        break;
    case 2:
        outer_i = i;
        outer_j = j - 1;
        break;
    case 3:
        outer_i = i - 1;
        outer_j = j;
        break;
    }
    (*feld)[outer_i][outer_j] = d.outer + '0';
}

void dominocpy(domino *dest, domino source)
{
    dest->inner = source.inner;
    dest->outer = source.outer;
    dest->direction = source.direction;
}

int pruefe_um_stein(int i, int j, int vergleichs_wert, char **feld, int feld_hoehe)
{
    int passt = 0;
    if (i - 1 >= 0)
    {
        if (feld[i - 1][j] - '0' == vergleichs_wert)
            passt = 1;
    }
    if (i + 1 < feld_hoehe)
    {
        if (feld[i + 1][j] - '0' == vergleichs_wert)
            passt = 1;
    }
    if (j - 1 >= 0)
    {
        if (feld[i][j - 1] - '0' == vergleichs_wert)
            passt = 1;
    }
    if (j + 1 < 10)
    {
        if (feld[i][j + 1] - '0' == vergleichs_wert)
            passt = 1;
    }

    if (i - 1 >= 0)
    {
        if (feld[i - 1][j] - '0' != vergleichs_wert && feld[i - 1][j] != ' ')
            passt = -1;
    }
    if (i + 1 < feld_hoehe)
    {
        if (feld[i + 1][j] - '0' != vergleichs_wert && feld[i + 1][j] != ' ')
            passt = -1;
    }
    if (j - 1 >= 0)
    {
        if (feld[i][j - 1] - '0' != vergleichs_wert && feld[i][j - 1] != ' ')
            passt = -1;
    }
    if (j + 1 < 10)
    {
        if (feld[i][j + 1] - '0' != vergleichs_wert && feld[i][j + 1] != ' ')
            passt = -1;
    }
    return passt;
}

int platzierbar(char **feld, int feld_hoehe, int i, int j, domino d)
{
    if (feld[i][j] != ' ')
        return 0; //aktuelles feld nicht frei

    int platzierbarkeit = 0;
    switch (d.direction)
    {
    case 0: //domino zeigt nach rechts
        if (j + 1 >= 10)
            return 0;

        if (feld[i][j] != ' ' || feld[i][j + 1] != ' ')
            return 0;

        platzierbarkeit = 0;
        platzierbarkeit += pruefe_um_stein(i, j, d.inner, feld, feld_hoehe);
        platzierbarkeit += pruefe_um_stein(i, j + 1, d.outer, feld, feld_hoehe);
        if (platzierbarkeit < 1)
        {
            return 0;
        }
        break;
    case 1: //domino zeigt nach oben
        if (i + 1 >= feld_hoehe)
            return 0;

        if (feld[i][j] != ' ' || feld[i + 1][j] != ' ')
            return 0;

        platzierbarkeit = 0;
        platzierbarkeit += pruefe_um_stein(i, j, d.inner, feld, feld_hoehe);
        platzierbarkeit += pruefe_um_stein(i + 1, j, d.outer, feld, feld_hoehe);
        if (platzierbarkeit < 1)
        {
            return 0;
        }

        break;
    case 2: //domino zeigt nach links
        if (j - 1 < 0)
            return 0;

        if (feld[i][j] != ' ' || feld[i][j - 1] != ' ')
            return 0;

        platzierbarkeit = 0;
        platzierbarkeit += pruefe_um_stein(i, j, d.inner, feld, feld_hoehe);
        platzierbarkeit += pruefe_um_stein(i, j - 1, d.outer, feld, feld_hoehe);
        if (platzierbarkeit < 1)
        {
            return 0;
        }

        break;
    case 3: //domino zeigt nach unten
        if (i - 1 < 0)
            return 0;

        if (feld[i][j] != ' ' || feld[i - 1][j] != ' ')
            return 0;

        platzierbarkeit = 0;
        platzierbarkeit += pruefe_um_stein(i, j, d.inner, feld, feld_hoehe);
        platzierbarkeit += pruefe_um_stein(i - 1, j, d.outer, feld, feld_hoehe);
        if (platzierbarkeit < 1)
        {
            return 0;
        }
        break;
    }
    return 1;
}

int berechne_breite(char **feld, int h)
{
    int breite = 0;
    for (int j = 0; j < 10; j++)
    {
        int domino_in_spalte = 0;
        for (int i = 0; i < h; i++)
        {
            if (feld[i][j] != ' ')
            {
                domino_in_spalte = 1;
            }
        }
        if (!domino_in_spalte)
            break;
        breite++;
    }
    return breite;
}

void printe_feld(int *returnwert, char *outfile, char **feld, int hoehe, int breite)
{
    FILE *out = fopen(outfile, "w");
    if (out == NULL)
    {
        *returnwert = 2;
        return;
    }
    for (int i = hoehe - 1; i >= 0; i--)
    {
        for (int j = 0; j < breite; j++)
        {
            fprintf(out, "%c", feld[i][j]);
        }
        fprintf(out, "\n");
    }
    fclose(out);
}

void printe_feld_std(FILE *out, char **feld, int hoehe)
{
    printf("|----------|\n");
    for (int i = hoehe - 1; i >= 0; i--)
    {
        printf("|");
        for (int j = 0; j < 10; j++)
        {
            fprintf(out, "%c", feld[i][j]);
        }
        fprintf(out, "|\n");
    }
    printf("|----------|\n");
}