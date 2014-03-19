#include <stdio.h>

int* fibonnacci(int limit) {
    int fib[100] = { 0 };
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < limit; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

int main(void) {
    int **a = fibonnacci(10);
    printf("%d", a[1]);
    return 0;
}


