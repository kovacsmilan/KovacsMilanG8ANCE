#include <stdio.h>

int main() {
    //1.
    int osszeg = 0;
    for (int i = 1; i <= 100; i++) {
        osszeg += i;
    }
    printf("A szamok ossege 1-tol 100-ig: %d\n", osszeg);

    //2.
    int osszeg2 = 0;
    for (int j = 1; j < 1000; j++) {
        if (j % 3 == 0 || j % 5 == 0) {
            osszeg2 += j;
        }
    }
    printf("A 1000-nel kisebb, 3-mal vagy 5-tel oszthato szamok ossege: %d\n", osszeg2);

    //3.
    int n;
    printf("n: ");
    scanf("%d", &n);
    for (int k = 1; k <= n; k++) {
        if (k % 4 == 0) {
            printf("%d\n", k);
        }
    }

    //4.
    int n2;
    printf("n: ");
    scanf("%d", &n2);
    for (int l = n2; l >= 1; l--) {
        if (l % 2 != 0) {
            printf("%d\n", l);
        }
    }

    //5.
    int n3;
    printf("n: ");
    scanf("%d", &n3);
    for (int m = 1; m <= n3; m++) {
        printf("%d", m);
        if (m < n) {
            printf(" --> ");
        }
    }
    printf("\n");

    //6.
    for (int o = 32; o <= 126; o++) {
        printf("%d: %c\n", o, o);
    }

    return 0;


}