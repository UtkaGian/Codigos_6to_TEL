#include <stdio.h>

#define BS flotante.bits
#define BE flotante.bite
#define BM flotante.bitm
#define BNE 8 //Número de bits del exponente
#define BNM 23//Número de bits de la mantisa 
union{
    struct{
        unsigned int bitm:23;
        unsigned int bite:8;
        unsigned int bits:1;
    };
    float value;
}flotante;

void Decimal_A_Binario(int valor, int bits);

int main (){
    printf("Bienvenido, ingrese su flotante:\n");
    scanf("%f", &flotante.value);
    printf("Bit de signo: %d\n", BS);
    printf("Exponente: ");
    Decimal_A_Binario(BE, BNE);
    printf("Mantisa: ");
    Decimal_A_Binario(BM,BNM);
    return 0;
    
}
void Decimal_A_Binario(int valor, int bits){
    int c, k;
	for (c=bits;c>=0;c--){
		k = valor>>c;
		if (k&1){
			printf("1");
		}else {
			printf("0");
		}
	}	
	printf("\n");	
}

