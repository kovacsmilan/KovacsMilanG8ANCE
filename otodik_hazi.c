#include <stdio.h>

void line(char c, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", c);
    }
    printf("\n"); 
}

int rfind_char(char s[], char c) {
    int hossz = 0;
    while (s[hossz] != '\0') {
        hossz++;
    }

    for (int i = hossz - 1; i >= 0; i--) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

int char_count(char s[], char c) {
    int darab = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            darab++;
        }
    }

    return darab;
}


int match_ends(int n, char* words[]) {
    int db = 0;

    for (int i = 0; i < n; i++) {
        int h = 0;
        while (words[i][h] != '\0') {
            h++;
        }
        if (h >= 2 && words[i][0] == words[i][h - 1]) {
            db++;
        }
    }

    return db;
}

int main() {
    printf("hello\n");
    line('-', 40);
    printf("world\n");


    printf("Abba, 'b' -> %d\n", rfind_char("Abba", 'b'));      
    printf("Abba, 'a' -> %d\n", rfind_char("Abba", 'a'));      
    printf("Abba, 'x' -> %d\n", rfind_char("Abba", 'x'));      
    printf("Aladar, 'a' -> %d\n", rfind_char("Aladar", 'a'));  


    printf("Abba, 'b' -> %d\n", char_count("Abba", 'b'));
    printf("Abba, 'a' -> %d\n", char_count("Abba", 'a'));
    printf("Abba, 'x' -> %d\n", char_count("Abba", 'x'));


    char* szavak1[] = {"aba", "xyz", "aa", "x", "bbb"};
    int meret1 = 5;

    char* szavak2[] = {"", "x", "xy", "xyx", "xx"};
    int meret2 = 5;

    char* szavak3[] = {"aaa", "be", "abc", "hello"};
    int meret3 = 4;

    printf("%d\n", match_ends(meret1, szavak1)); 
    printf("%d\n", match_ends(meret2, szavak2)); 
    printf("%d\n", match_ends(meret3, szavak3));


    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("fizzbuzz\n");
        }
        else if (i % 3 == 0) {
            printf("fizz\n");
        }
        else if (i % 5 == 0) {
            printf("buzz\n");
        }
        else {
            printf("%d\n", i);
        }
    }
    return 0;
}