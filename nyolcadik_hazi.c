#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Eredmenyek {
    int min;
    int max;
    double atlag;
};

int is_valid_c_identifier(const char* input) {
    if (input == NULL || input[0] == '\0') return 0;
    if (!isalpha(input[0]) && input[0] != '_') return 0;
    for (int i = 1; input[i] != '\0'; i++) {
        if (!isalnum(input[i]) && input[i] != '_') return 0;
    }
    return 1;
}

int hasonlit(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void statisztikaMutatoval(int tomb[], int meret, int *min, int *max, double *atlag) {
    if (meret <= 0) return;
    *min = tomb[0];
    *max = tomb[0];
    int osszeg = 0;
    for (int i = 0; i < meret; i++) {
        if (tomb[i] < *min) *min = tomb[i];
        if (tomb[i] > *max) *max = tomb[i];
        osszeg += tomb[i];
    }
    *atlag = (double)osszeg / meret;
}

struct Eredmenyek statisztikaStrukturaval(int tomb[], int meret) {
    struct Eredmenyek res = {0, 0, 0.0};
    if (meret <= 0) return res;
    res.min = tomb[0];
    res.max = tomb[0];
    int osszeg = 0;
    for (int i = 0; i < meret; i++) {
        if (tomb[i] < res.min) res.min = tomb[i];
        if (tomb[i] > res.max) res.max = tomb[i];
        osszeg += tomb[i];
    }
    res.atlag = (double)osszeg / meret;
    return res;
}

int main(int argc, char *argv[]) {
    // 1. Parancssori argumentumok es Fajl sorainak szama
    if (argc < 2) {
        fprintf(stderr, "Hiba! Adja meg egy szoveges allomany nevet!\n");
    } else {
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL) {
            fprintf(stderr, "Hiba! A %s nevu file-t nem sikerult megnyitni!\n", argv[1]);
        } else {
            int sorok_szama = 0;
            char ch;
            while ((ch = fgetc(fp)) != EOF) {
                if (ch == '\n') sorok_szama++;
            }
            printf("Fajl sorainak szama: %d\n", sorok_szama);

            if (strcmp(argv[1], "valos_szamok.txt") == 0) {
                rewind(fp);
                double osszegValos = 0.0;
                double aktValos;
                while (fscanf(fp, "%lf", &aktValos) != EOF) osszegValos += aktValos;
                printf("Valos szamok osszege: %.20f\n", osszegValos);
            }
            fclose(fp);
        }

        printf("\nLegrovidebb szavak az argumentumok kozott:\n");
        int min_h = strlen(argv[1]);
        for (int i = 1; i < argc; i++) if (strlen(argv[i]) < min_h) min_h = strlen(argv[i]);
        for (int i = 1; i < argc; i++) if (strlen(argv[i]) == min_h) printf("%s\n", argv[i]);
    }

    // 2. Szuro feladat (in.txt -> out.txt)
    FILE *f_in = fopen("in.txt", "r");
    if (f_in != NULL) {
        printf("\n# in.txt sikeresen megnyitva\n");
        FILE *f_out = fopen("out.txt", "w");
        if (f_out != NULL) {
            printf("# 0,5-nel nagyobb szamok szurese...\n");
            double szam;
            int db_szurt = 0;
            while (fscanf(f_in, "%lf", &szam) != EOF) {
                if (szam > 0.5) {
                    fprintf(f_out, "%f\n", szam);
                    db_szurt++;
                }
            }
            printf("# szures vege\n");
            fclose(f_out);
            printf("# out.txt bezarva\n");
            printf("# out.txt-be kiirt szamok mennyisege: %d db\n", db_szurt);
        }
        fclose(f_in);
    }

    // 3. Random szamos feladat
    printf("\n--- Random szamok (Rendezett, Egyedi) ---\n");
    int db = 10, also = 10, felso = 99;
    int *szamok = (int*)malloc(db * sizeof(int));
    for (int i = 0; i < db; i++) {
        int uj, ok;
        do {
            ok = 1;
            uj = rand() % (felso - also + 1) + also;
            for (int j = 0; j < i; j++) if (szamok[j] == uj) { ok = 0; break; }
        } while (!ok);
        szamok[i] = uj;
    }
    qsort(szamok, db, sizeof(int), hasonlit);
    printf("Szamok: ");
    for (int i = 0; i < db; i++) printf("%d ", szamok[i]);

    struct Eredmenyek stat = statisztikaStrukturaval(szamok, db);
    printf("\nMin: %d, Max: %d, Atlag: %.1f\n", stat.min, stat.max, stat.atlag);
    free(szamok);

    // 4. Azonosito ellenorzo
    printf("\n--- Azonosito teszt ('*' vegjelig) ---\n");
    char buf[256];
    while (1) {
        printf("Input: ");
        if (scanf("%255s", buf) != 1 || strcmp(buf, "*") == 0) break;
        if (is_valid_c_identifier(buf)) printf("YES\n"); else printf("NO\n");
    }

    return 0;
}