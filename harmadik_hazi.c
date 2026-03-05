#include <stdio.h>

int main() {
    int magassag;

    printf("magassag: ");
    scanf("%d", &magassag);

    //mario
    for (int i = 1; i <= magassag; i++) {
        for (int j = 0; j < magassag - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        printf("\n");
    }

    //diamond
    int magassag2;

    printf("Magassag: ");
    if (scanf("%d", &magassag2) != 1 || magassag2 <= 0 || magassag2 % 2 == 0) {
        printf("Hiba: Csak pozitiv paratlan szamot fogadunk el!\n");
        return 1;
    }

    int kozep = magassag2 / 2;

    for (int i = 0; i <= kozep; i++) {
            for (int j = 0; j < kozep - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = kozep - 1; i >= 0; i--) {
        for (int j = 0; j < kozep - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}