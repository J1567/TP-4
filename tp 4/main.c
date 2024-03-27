#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**PROTOTIPADO*/
int arrayEnteros (int enteros[], int dimencion);
void mostrarParametro (int enteros[], int validos);
int sumar (int entero[], int validos);
Pila cargaPila ();
int pasarDatos (Pila punto4,int entero[],int dimencion);
float  cargaArrayCien (float arrayCien[],int dimencion);
float sumaArrayCien(float arrayDeCien[],int validos);
void busquedaCaracteres (int enteros[]);
int main()
{
    int numerosEnteros[10];
    int arreglo4[5];
    Pila pilon;
    inicpila(&pilon);
    /* 1) Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado.
     La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos)*/


    int validos = arrayEnteros(numerosEnteros,10);
    printf ("los validos son: %i\n",validos);
    system("pause");
    system("cls");



    /**2) Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y
     los muestre por pantalla.*/

    mostrarParametro(numerosEnteros, validos);

    system("pause");
    system("cls");

    /**3) Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él
    y calcule la suma de sus elementos.*/
    int suma = sumar(numerosEnteros,validos);
    printf("suma = : %i\n", suma);
    system("pause");
    system("cls");

    /**4) Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos
    (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila. */
    pilon = cargaPila();
    int i = pasarDatos (pilon,arreglo4,5);
    printf("los elementos son: %i\n",i);
    system("pause");
    system("cls");
    /**5) Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100.
    (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)*/
    printf("ACT 5\n");
    float arrayDeCien[100];
    int validosCien = cargaArrayCien(arrayDeCien,100);
    float sumaCien = sumaArrayCien(arrayDeCien,validosCien);
    printf("la suma de los numeros reales en un array de dimencion 100 es: %f", sumaCien);
    system("pause");
    system("cls");
    /**6) Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.*/
    printf("ACT 6\n");
    busquedaCaracteres(numerosEnteros);




    return 0;
}




int arrayEnteros (int enteros[], int dimencion)
{
    int i = 0;
    char seguir = 's';

    while (seguir == 's' && i< dimencion)
    {

        printf("ingrese el elemento del array \n");
        fflush (stdin);
        scanf("%i", &enteros[i]);


        printf ("desea seguir s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);
        i++;
    }

    return i;
}

void mostrarParametro (int enteros[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        printf ("%i / ", enteros[i]);
    }

}

int sumar (int entero[], int validos)
{
    int i = 0;
    int sumar = 0;
    while(i< validos)
    {
        sumar += entero[i];
        i++;
    }
    return sumar;



}
Pila cargaPila ()
{
    Pila punto4;
    inicpila(&punto4);
    int valor;
    char seguir = 's';
    while (seguir == 's')
    {
        printf("ingrese un valor: \n");
        fflush(stdin);
        scanf("%i", &valor);
        apilar(&punto4,valor);

        printf ("desea seguir s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    return punto4;
}
int pasarDatos (Pila punto4,int entero[],int dimencion)
{
    Pila aux;
    inicpila(&aux);
    int i = 0;
    while (!pilavacia (&punto4)&& i< dimencion)
    {
        entero[i]  =tope(&punto4);
        apilar (&aux, desapilar(&punto4));
        i++;
    }

    return i;

}

float  cargaArrayCien (float arrayCien[],int dimencion)
{
    int i = 0;

    char seguir = 's';

    while (seguir == 's' && i< dimencion)
    {

        printf("ingrese el elemento del array \n");
        fflush (stdin);
        scanf("%f",&arrayCien[i]);


        printf ("desea seguir s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);
        i++;
    }
    return i;
}

float sumaArrayCien(float arrayDeCien[],int validos)
{
    int i = 0;
    float sumar = 0;
    while(i< validos)
    {
        sumar += arrayDeCien[i];
        i++;
    }
    return sumar;
}


void busquedaCaracteres (int enteros[])
{
    int num;
    int i = 0;
    printf ("ingrese el elemento a buscar en el array: \n");
    scanf("%i",&num);
    if (num=enteros [i])
    {
        printf("el caracter se encuentra en el array, en la posicion: %i\n", enteros[i]);
    }
    else
    {
        i++;
    }


}

