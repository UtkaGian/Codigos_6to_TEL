#include <stdio.h>
#include <stdio_ext.h>
#define LIM 40
#define LIM_RAMA 4
#define LIM_FGETS 40
#define LIM_RAMA_FGETS 4
struct alumnos{
    unsigned char nombre[LIM];
    unsigned char apellido[LIM];
    int edad;
    int año;
    unsigned char rama[LIM_RAMA];
    
};
int main(void){
    int hm; // hm = how many o hijuesumadre
    int wh; // wh = who tf
    printf("Hola, ingrese cuantos alumnos piensa registrar\n");
    scanf("%d", &hm);
    printf("Comencemos...\n");
    __fpurge(stdin);
    struct alumnos alumnos[hm];
    for(unsigned char i=0;i<hm;i++){
        printf("Nombre:\n");
        fgets(alumnos[i].nombre, LIM_FGETS, stdin);
        __fpurge(stdin);
        printf("Apellido;\n");
        fgets(alumnos[i].apellido, LIM_FGETS, stdin);
        __fpurge(stdin);
        printf("Edad:\n");
        scanf("%d", &alumnos[i].edad);
        __fpurge(stdin);
        printf("Año al que asiste en valor numérico:\n");
        scanf("%d", &alumnos[i].año);
        __fpurge(stdin);
        printf("Rama a la que pertenece (TEL/TEM/UND):\n");
        fgets(alumnos[i].rama, LIM_RAMA_FGETS, stdin);
        __fpurge(stdin);
        
    }
    printf("Ahora, qué ficha desea ver?\n");
    scanf("%d", &wh);
    wh=wh--;
    printf(" Nombre:%s \n Apellido:%s \n Edad:%d \n Año:%d \n Rama:%s \n", alumnos[wh].nombre, alumnos[wh].apellido, alumnos[wh].edad, alumnos[wh].año, alumnos[wh].rama);
    return 0;
}
