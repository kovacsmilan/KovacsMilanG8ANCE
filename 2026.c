#include <stdio.h>

int main() {
    int t = 'K' - 'A'; 
    int sz = 'z' - 'v';
    int ev = ('T' - '@') * ('d') + ('Z' - '@');
    
    printf("%d\n", ev);
    
    return 'A' - 'A';

    /*K = 75, A = 65
    z = 122, v = 118
     T = 84, @ = 64, d = 100, Z = 90*/
    // 84 - 64 = 20 * 100 + 90 - 64 = 2000 + 26 = 2026 
}