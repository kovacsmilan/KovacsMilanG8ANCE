#include <stdio.h>

void feltoltAbece(char tomb[]) {
    for (int i = 0; i < 26; i++) {
        tomb[i] = 'a' + i;
    }
}

void ellenorizEsOsszead(int darab, char* tomb[]) {
    if (darab != 3) {
        printf("Hiba! Ket parametert (szamot) kell megadni.\n");
    } 
    else {
        int szam1 = atoi(tomb[1]);
        int szam2 = atoi(tomb[2]);
        printf("%d\n", szam1 + szam2);
    }
}

void tombKiir(int tomb[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", tomb[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void generalEsKiir(int n, int also, int felso) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        int r = rand() % (felso - also + 1) + also;
        printf("%d", r);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    ellenorizEsOsszead(argc, argv);

    char abc[26];
    feltoltAbece(abc);

    for (int i = 0; i < 26; i++) {
        printf("%c", abc[i]);
    }
    printf("\n");


    int n;
    printf("Hany db szamot szeretnel bevinni?\n");
    scanf("%d", &n);

    int eredeti[n];
    int masolat[n];

    for (int i = 0; i < n; i++) {
        printf("%d. szam: ", i + 1);
        scanf("%d", &eredeti[i]);
    }

    for (int i = 0; i < n; i++) {
        if (eredeti[i] < 0) {
            masolat[i] = -eredeti[i];
        } else {
            masolat[i] = eredeti[i];
        }
    }
    printf("\nA bevitt szamok abszolutertekei: ");
    tombKiir(masolat, n);

    printf("A megadott szamok: ");
    tombKiir(eredeti, n);


    int volt_mar[100] = {0}; 
    int szam;
    int kulonbozo_db = 0;

    printf("Adj meg 0 vegjelig egesz szamokat az [1, 99] intervallumbol!\n");

    while (1) {
        printf("Szam: ");
        scanf("%d", &szam);
        if (szam == 0) {
            break;
        }

        if (szam < 1 || szam > 99) {
            printf("Ez a szam kivul esik az elfogadhato intervallumon!\n");
            continue;
        }

        if (volt_mar[szam] == 0) {
            volt_mar[szam] = 1; 
            kulonbozo_db++;    
        }
    }

    printf("\n%d db kulonbozo szam lett megadva.\n", kulonbozo_db);
    printf("Ezek (novekvo sorrendben): ");
    int elso = 1;
    for (int i = 1; i <= 99; i++) {
        if (volt_mar[i] == 1) {
            if (!elso) {
                printf(", ");
            }
            printf("%d", i);
            elso = 0;
        }
    }
    printf("\n");


    char szo[100];
    int db = 0;
    int max_hossz = 0;

    printf("Adj meg szavakat '*' vegjelig!\n");

    while (1) {
        printf("Szo: ");
        if (fgets(szo, 100, stdin) == NULL) break;

        if (szo[0] == '*') {
            break;
        }

        int aktualis_hossz = 0;
        while (szo[aktualis_hossz] != '\0' && szo[aktualis_hossz] != '\n') {
            aktualis_hossz++;
        }

        db++;
        if (aktualis_hossz > max_hossz) {
            max_hossz = aktualis_hossz;
        }
    }

    printf("\n%d db szot adtal meg. A leghosszabb szo %d karakterbol all.\n", db, max_hossz);

    int n, a, f;

    printf("Hany db random szamot kers? ");
    scanf("%d", &n);

    printf("Also hatar: ");
    scanf("%d", &a);

    printf("Felso hatar (zart intervallum): ");
    scanf("%d", &f);

    printf("\nA generalt szamok: ");
    generalEsKiir(n, a, f);

    return 0;


}