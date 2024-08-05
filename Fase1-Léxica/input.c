#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() {
    /* Diretivas de pré-processador */
    #define PI 3.14
    #ifdef PI
        printf("PI is defined\v");
    #endif

    /* Palavras reservadas e tipos de dados */
    int a = 10;
    auto int b = 20;
    const float pi = 3.14159;
    double d = 123.456;
    char c = 'A';
    enum { RED, GREEN, BLUE } color;
    extern int externalVar;
    register int regVar;
    static int staticVar = 50;
    volatile int volVar = 60;
    long l = 1234567890L;
    short s = 1000;
    unsigned int u = 12345;

    /* Controle de fluxo*/
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            printf("i is even: %d\n", i);
        } else {
            printf("i is odd: %d\n", i);
        }
    }

    switch (a) {
        case 10:
            printf("a is 10\n");
            break;
        default:
            printf("a is not 10\n");
    }

    /* Operadores e expressões*/
    a += b;
    a++;
    a--;
    int result = (a > b) ? a : b;
    result = a * b / c + d - l % s;
    result = a & b | c ^ d;
    result = (a << 2) >> 1;
    result = a && b || c;
    result = ~a;
    result = !a;
    result = (a == b) ? 1 : 0;
    result = (a != b) ? 1 : 0;
    result = (a <= b) ? 1 : 0;
    result = (a >= b) ? 1 : 0;

    /* Arrays e ponteiros*/
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i * i;
    }
    int *p = &a;

    /* Funções e retornos*/
    printf("Hello, World!\n");
    return 0;
}

/* Função auxiliar*/
void helperFunction(int param) {
    printf("Parameter is: %d\n", param);
}
