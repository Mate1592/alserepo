#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    
    if (x < 10) {
        return true;
    }
    
    if (x % 10 == 0) {
        return false;
    }
    
    int numeroRevertido = 0;
    while (x > numeroRevertido) {
        numeroRevertido = numeroRevertido * 10 + x % 10;
        x = x / 10;
    }
    
    return x == numeroRevertido || x == numeroRevertido / 10;
}

int main() {
    int x;
    
    printf("Ingrese un numero: ");
    scanf("%d", &x);
    
    if (isPalindrome(x)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}