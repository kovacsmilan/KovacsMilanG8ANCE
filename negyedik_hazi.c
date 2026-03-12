#include <stdio.h>

int haromszog(double a, double b, double c);
int parosos(int n);
int rendezes(int tomb[], int meret);
int min(int tomb[], int meret);
int max(int tomb[], int meret);
int osszeg(int magassag[], int meret);
void kiir(int tomb[], int meret);
void pozitiv(int tomb[], int meret);
void array(int tomb[], int meret);

int parosos(int n) {
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int haromszog(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 0; 
    }

    if (a + b > c && a + c > b && b + c > a) {
        return 1;
    } else {
        return 0; 
    }
}

int sum_magassag(int magassag[], int size) {
    if (size < 2) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < size - 1; i++) {
        int diff = abs(magassag[i] - magassag[i + 1]);
        sum += diff;
    }

    return sum;
}


void kiir(int tomb[], int size) {
    if (size <= 0) {
        printf("\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", tomb[i]);
    }
    printf("%d\n", tomb[size - 1]);
}

int main() {
    double x = 3, y = 4, z = 5;

    if (haromszog(x, y, z)) {
        printf("A %.1f, %.1f, %.1f oldalu haromszog \n", x, y, z);
    } else {
        printf("nem szerkeztheto a haromszog\n");
    }

    return 0;

    int szam = 42;
    if (parosos(szam)) {
        printf("%d paros.\n", szam);
    } else {
        printf("%d paratlan.\n", szam);
    }
    return 0;


    int tomb1[] = {1, 3, 5, 8, 12};
    int meret1 = 5;

    int tomb2[] = {1, 5, 2, 8, 4};
    int meret2 = 5;

    int tomb3[] = {};
    int meret3 = 0;

    if (rendezes(tomb1, meret1)) {
        printf("Az elso tomb rendezett\n");
    } else {
        printf("Az elso tomb nem rendezett\n");
    }

    if (rendezes(tomb2, meret2)) {
        printf("A masodik tomb rendezett\n");
    } else {
        printf("A masodik tomb nem rendezett\n");
    }

    if (rendezes(tomb3, meret3)) {
        printf("Az ures tomb rendezett\n");
    }
    

    int szamok[] = {12, 5, 21, 8, -3, 15, 0};
    int meret = 7;
    int legkisebb = min(szamok, meret);
    int legnagyobb = max(szamok, meret);
    printf("A legkisebb: %d\n", legkisebb);
    printf("A legnagyobb: %d\n", legnagyobb);

    int felhokarcolok[] = {2, 1, 0, 2, 4};
    int meret = 5;
    int vegleges = osszeg(felhokarcolok, meret);
    printf("osszege: %d\n", vegleges);


    int t1[] = {4, 7, 34, 23, 67};
    int m1 = 5;

    int t2[] = {10, 20};
    int m2 = 2;

    int t3[] = {100};
    int m3 = 1;
    kiir(t1, m1);
    kiir(t2, m2);
    kiir(t3, m3);

    int szamok2[] = {-5, 12, 0, -8, -1, 22};
    int meret2 = 6;
    print_array(szamok2, meret2);

    make_positive(szamok2, meret2);

    print_array(szamok2, meret2);

    return 0;
    
}

