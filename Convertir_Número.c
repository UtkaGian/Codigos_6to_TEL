#include <stdio.h>

union {
    float valor;
    unsigned char lugar[4];
}conversor;

int main()
{
    printf("Ingrese el valor que quiere ver en hexadecimal\n");
    scanf("%f", &conversor.valor);
    printf("0x%x%x%x%x", conversor.lugar[3], conversor.lugar[2], conversor.lugar[1], conversor.lugar[0]);
    return 0;
}
