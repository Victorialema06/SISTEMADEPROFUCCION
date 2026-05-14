#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX 5

int buscarProducto(char nombres[][30], char buscar[]);

void registrarProducto(
    char nombres[][30],
    int demanda[],
    float tiempo[],
    float recursos[]
);

void editarProducto(
    char nombres[][30],
    int demanda[],
    float tiempo[],
    float recursos[]
);

void eliminarProducto(
    char nombres[][30],
    int demanda[],
    float tiempo[],
    float recursos[]
);

void mostrarProductos(
    char nombres[][30],
    int demanda[],
    float tiempo[],
    float recursos[]
);

void calcularProduccion(
    char nombres[][30],
    int demanda[],
    float tiempo[],
    float recursos[]
);

#endif