#include <stdio.h>

// Declaración de funciones.
float calcularAcd();
float calcularApe();
float calcularAa();
float calcularEs();
float calcularPromedioUnidad(int unidad);
float calcularNotaFinal (float a, float b, float c, const int NUMEROUNIDADES);
void notaFinalCualitativa(float notaFinal);

// Función principal.
int main (){
    int unidad;
    float notaFinal, notaUnidades = 0, promedioUnidad;
    const int NUMEROUNIDADES = 3;
    
    //Bucle repetitivo para acumular las notas de cada unidad.
    for (unidad = 1; unidad <= NUMEROUNIDADES; unidad++){
        promedioUnidad = calcularPromedioUnidad(unidad);
        notaUnidades = notaUnidades + promedioUnidad;
    }

    //Cálculo de la nota Final.    
    notaFinal = notaUnidades / NUMEROUNIDADES;

    printf ("============================================================\n");
    printf ("Su nota final es: %.2f\n", notaFinal);
    notaFinalCualitativa(notaFinal);
    printf ("============================================================\n");

    return 0;
}

//Funcion para calcular el promedio de cada Unidad.

float calcularPromedioUnidad(int unidad){

    float promedioUnidad, acd, ape, aa, es;


    printf ("----------------------------------------------------------------------\n");
    printf ("UNIDAD %i\n", unidad);
    printf ("----------------------------------------------------------------------\n");

    // Llamada a las funciones para calcular promedio
    acd = calcularAcd();
    ape = calcularApe();
    aa = calcularAa();
    es = calcularEs();

    // Cálculo del promedio de cada Unidad
    promedioUnidad = acd + ape + aa + es;

    printf ("----------------------------------------------------------------------\n");
    printf ("NOTAS UNIDAD %i\n", unidad);
    printf ("----------------------------------------------------------------------\n");

    printf ("Su nota de ACD es: %.2f\n", acd);
    printf ("Su nota de APE es: %.2f\n", ape);
    printf ("Su nota de AA es: %.2f\n", aa);
    printf ("Su nota de ES es: %.2f\n", es);
    printf ("El promedio final de la unidad  %i es: %.2f\n", unidad, promedioUnidad);

    return promedioUnidad;
}

// Función para calcular la nota de ACD.
float calcularAcd(){

    int i, numActividades;
    float acd, notaAcd, promedio, acumulador = 0;

    printf ("ACD\n");

    printf ("Ingrese el número de actividades\n");
    scanf ("%i", &numActividades);

    printf ("==========================================================\n");
    
    for (i = 1; i <= numActividades; i ++){
        
        // Bucle repetitivo para controlar que la nota no sea menor 0 o mayor a 10
        do {
            printf ("Ingrese la nota de la actividad %i:\n",i);
            scanf ("%f", &notaAcd);
        } while (notaAcd < 0 || notaAcd > 10);

        acumulador = (acumulador + notaAcd);
    }
    
    // Cálculo de la nota de ACD con una ponderación del 20%
    promedio = acumulador/numActividades;
    acd = promedio * 0.2;

    return acd;
}

// Función para calcular la nota de APE.
float calcularApe(){

    int i, numActividades;
    float ape, notaApe, promedio, acumulador = 0;

    printf ("----------------------------------------------------------------------\n");
    printf ("APE\n");

    printf ("Ingrese el número de actividades\n");
    scanf ("%i", &numActividades);

    printf ("==========================================================\n");

    for (i = 1; i <= numActividades; i ++){
    
        // Bucle repetitivo para controlar que la nota no sea menor 0 o mayor a 10
        do {
            printf ("Ingrese la nota de la actividad %i:\n",i);
            scanf ("%f", &notaApe);
        } while (notaApe < 0 || notaApe > 10);

        acumulador = (acumulador + notaApe);
    }
    
    // Cálculo de la nota de APE con una ponderación del 25%
    promedio = acumulador/numActividades;
    ape = promedio * 0.25;

    return ape;
}

// Función para calcular la nota AA.
float calcularAa(){

    int i, numActividades;
    float aa, notaAa, promedio, acumulador = 0;

    printf ("----------------------------------------------------------------------\n");
    printf ("AA\n");

    printf ("Ingrese el número de actividades\n");
    scanf ("%i", &numActividades);

    printf ("==========================================================\n");

    for (i = 1; i <= numActividades; i ++){
    
        // Bucle repetitivo para controlar que la nota no sea menor 0 o mayor a 10
        do {
            printf ("Ingrese la nota de la actividad %i:\n",i);
            scanf ("%f", &notaAa);
        } while (notaAa < 0 || notaAa > 10);

        acumulador = (acumulador + notaAa);
    }
    
    // Cálculo de la nota de AA con una ponderación del 20%
    promedio = acumulador/numActividades;
    aa = promedio * 0.2;

    return aa;
}

// Función para calcular la nota de ES.
float calcularEs(){

    float porcentaje, porcentajeDos, valor, valorDos, es, examen, portafolio;

    printf ("----------------------------------------------------------------------\n");
    printf ("ES\n");

    // Bucle repetitivo para controlar que la nota no sea menor 0 o mayor a 10
    do {
        printf ("Ingrese la nota de examen:\n");
        scanf ("%f", &examen);
    } while (examen < 0 || examen > 10);

    // Bucle repetitivo para controlar que la nota no sea menor 0 o mayor a 10
    do {
        printf ("Ingrese la nota del portafolio:\n");
        scanf ("%f", &portafolio);
    } while (portafolio < 0 || portafolio > 10);

    printf ("==========================================================\n");

    // Bucle repetitivo para controlar que el porcentaje no sea menor 0 o mayor a 100
    do {
        printf ("Ingrese el porcentaje del examen:\n");
        scanf ("%f", &valor);
    } while (valor < 0 || valor > 100);

    // Bucle repetitivo para controlar que el porcentaje no sea menor 0 o mayor a 100
    do {
        printf ("Ingrese el porcentaje del portafolio:\n");
        scanf ("%f", &valorDos);
    } while (valorDos < 0 || valorDos > 100); 

    // Cálculo de los porcentajes 
    porcentaje = valor/100;
    porcentajeDos = valorDos/100;

    // Cálculo de la nota de ES con una ponderación del 35%
    es = ((examen * porcentaje) + (portafolio * porcentajeDos)) * 0.35;

    return es;
}

// Función para calcular la nota final.
float calcularNotaFinal(float a, float b, float c, const int NUMEROUNIDADES){
    
    float notaFinal;

    // Cálculo de la nota final con las notas de cada unidad aplicando un promedio simple
    notaFinal = (a + b + c)/NUMEROUNIDADES;

    return notaFinal;
}

// Procedimiento para mostrar la nota cualitativa del estudiante.
void notaFinalCualitativa(float notaFinal){

    /* Aplicación de estructura condicional en base a la nota final para mostrar 
    si el estudiante ha aprobado, reprobado o ha quedado en supletorios */
    
    if (notaFinal >= 7){
        printf ("Usted ha aprobado\n");
    } else if (notaFinal < 7 || notaFinal >= 2.5){
        printf ("Usted ha quedado en supletorios\n");
    } else {
        printf ("Usted ha reprobado");
    }
}
