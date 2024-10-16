#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    char productos[10][50];
    float precio[10];
    int totalProductos = 3;

    for (int i = 0; i < totalProductos; i++) {
        leerNombreProducto(productos, precio, i + 1, i);
    }

    for (int i = 0; i < totalProductos; i++) {
        imprimirNombreProducto(productos, precio, i + 1, i);
    }

    char productobuscar[50];
    printf("Ingrese el nombre del producto que desea buscar: ");
    scanf("%s", productobuscar);
    buscarProducto(productos, precio, productobuscar);

    float total = calcularTotalInventario(precio, totalProductos);
    printf("El precio total del inventario es: %.2f\n", total);

    encontrarProductoMasCaroYBarato(productos, precio, totalProductos);

    float promedio = calcularPrecioPromedio(precio, totalProductos);
    printf("El precio promedio de los productos es: %.2f\n", promedio);

    return 0;
}
