#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//bacchetta, Tomás
/*1. Crear una función llamada aplicarDescuento que reciba
    como parámetro el precio de un producto y devuelva el
    valor del producto con un descuento del 5%.
    Realizar la llamada desde el main. **/

    /*Crear una función que se llame contarCaracteres que
    reciba una cadena de caracteres como primer parámetro y un
    carácter como segundo y devuelva la cantidad de veces que
    ese carácter aparece en la cadena */

    /*3. Dada la estructura Notebook(id, procesador, marca, precio)
    generar una función que permita ordenar un array de dicha estructura por marca.
    Ante igualdad de marca deberá ordenarse por precio.
    Hardcodear datos y mostrarlos desde el main. */

    #define TAMARRAY 5
struct{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} typedef eNotebook;


int aplicarDescuento (int precioProducto);
int contarCaracteres (char cadena[], char caracter);
int ordenarArray(eNotebook notebooks[], int tamArray);

int main()
{
    int precioProducto = 100;
    int precioConDescuento;
    char cadena[20] = "favio alberti";
    char caracter = 'a';
    int cantidadDeApariciones;
    eNotebook notebooks[TAMARRAY] = {
    {1,"Pungun", "Intel", 2000},
     {1,"Yen", "Zonga", 3500},
    {1,"Tengen", "AMD", 1500},
    {1,"Fuego", "Pipi", 500},
    {1,"Zorro", "Lowry", 750}};

    precioConDescuento = aplicarDescuento(precioProducto);

    printf("1. El producto de valor $%d con descuento quedara en $%d\n", precioProducto, precioConDescuento);

    cantidadDeApariciones = contarCaracteres (cadena, caracter);
    printf("2. El caracter '%c' aparece %d veces en '%s'", caracter, cantidadDeApariciones, cadena);

    ordenarArray(notebooks, TAMARRAY);

    return 0;
}

int aplicarDescuento (int precioProducto){
    int resultado;
    resultado = precioProducto - (precioProducto * 5/100);
    return resultado;
}

int contarCaracteres (char cadena[], char caracter){
    int contador = 0;
    for (int x = 0; x < strlen(cadena); x++){
        if (cadena[x] == caracter){
            contador++;
        }
    }
    return contador;
}

int ordenarArray(eNotebook notebooks[], int tamArray){
    int allRight = 1;
    eNotebook aux;
    for (int x = 0; x < tamArray - 1; x++){
        for (int y = x + 1; y < tamArray; y++){
            if (strcmp(notebooks[x].marca, notebooks[y].marca) > 0
               ||  (strcmp(notebooks[x].marca, notebooks[y].marca) == 0 && notebooks[x].precio > notebooks[y].precio))
            {
                 aux = notebooks[x];
                 notebooks[x] = notebooks[y];
                 notebooks[y] = aux;
            }
        }
    }
    return allRight;
}

