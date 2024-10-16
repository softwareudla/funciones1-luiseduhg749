#include <stdio.h>
#include "funciones.h"
#include <string.h>

void leerNombreProducto(char productos[10][50], float precio[10], int num, int i){
    printf("Ingrese el producto numero %d: ", num);
    scanf("%s", productos[i]);
    printf("Ingrese el precio del producto %d: ", num);
    scanf("%f", &precio[i]);
}

void imprimirNombreProducto(char productos[10][50], float precio[10], int num, int i){
    printf("El nombre del producto %d es: %s\n", num, productos[i]);
    printf("El precio del producto es: %.2f\n", precio[i]);
}

void buscarProducto(char productos[10][50], float precio[10], char productoBuscar[50]){
    int encontrado = 0;
    for (int i = 0; i < 10; i++){
        if (strcmp(productos[i], productoBuscar) == 0){
            printf("El precio del producto %s es: %.2f\n", productoBuscar, precio[i]);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado){
        printf("No existe el producto buscado\n");
    }
}

float calcularTotalInventario(float precio[10], int totalProductos){
    float total = 0.0;
    for (int i = 0; i < totalProductos; i++){
        total += precio[i]; 
    }
    return total;
}

void encontrarProductoMasCaroYBarato(char productos[10][50], float precio[10], int totalProductos){
    int indexMasCaro = 0, indexMasBarato = 0;

    for (int i = 1; i < totalProductos; i++){
        if (precio[i] > precio[indexMasCaro]){
            indexMasCaro = i;
        }
        if (precio[i] < precio[indexMasBarato]){
            indexMasBarato = i;
        }
    }

    printf("El producto más caro es: %s con un precio de %.2f\n", productos[indexMasCaro], precio[indexMasCaro]);
    printf("El producto más barato es: %s con un precio de %.2f\n", productos[indexMasBarato], precio[indexMasBarato]);
}

float calcularPrecioPromedio(float precio[10], int totalProductos){
    float total = calcularTotalInventario(precio, totalProductos);
    return total / totalProductos;
}
