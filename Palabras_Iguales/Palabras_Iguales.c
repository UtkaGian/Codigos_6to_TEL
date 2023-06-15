#include <stdio.h>

int Compara_Palabras (char *LS1, char *LS2);
int main()
{
    char String_1[14]={0};
    char String_2[14]={0};
    char *LS_1=&String_1[0];  //Las siglas LS representan "Letra de string"
    char *LS_2=&String_2[0];
    int Retorno;
    printf("Hola, ingrese una palabra de max 13 letras\n");
    scanf("%s", String_1);
    fflush;
    printf("Ahora ingrese su segunda palabra bajo las mismas condiciones\n");
    scanf("%s", String_2);
    fflush;
    Retorno=Compara_Palabras(LS_1, LS_2);
    if(Retorno==0) printf("Son cadenas exactamente iguales\n");
    printf("%d", Retorno);
    return 0;
}
int Compara_Palabras (char *LS1, char *LS2){
    int Flag=0;
    for (int i=0; i<=13; i++){
        if(*(LS1+i) == *(LS2+i)){
            Flag=0;
        }else{
            printf("Son cadenas distinas...\n");
            Flag=1;
            break;
        }
    }
    return (Flag);
}
