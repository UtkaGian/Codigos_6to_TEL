#include <stdio.h>

    float valor;


int main()
{
    printf("Ingrese el valor que quiere ver en hexadecimal\n");
    scanf("%f", &valor);
    
    char *point = (char*)&valor;
    
    printf("0x%x%x%x%x", *(point + 3), *(point + 2), *(point + 1), *(point));
    return 0;
}


