#include <stdio.h>
#include "funciones.h"

#define MAX 5

int main()
{
    char nombres[MAX][30];

    int demanda[MAX];

    float tiempo[MAX];

    float recursos[MAX];

    int opcion;

    int i;

    for(i = 0; i < MAX; i++)
    {
        nombres[i][0] = '\0';

        demanda[i] = 0;

        tiempo[i] = 0;

        recursos[i] = 0;
    }

    do
    {
        printf("\n====================================\n");
        printf(" SISTEMA INDUSTRIAL DE PRODUCCION\n");
        printf("====================================\n");

        printf("1. Registrar componente\n");
        printf("2. Editar componente\n");
        printf("3. Eliminar componente\n");
        printf("4. Analizar produccion\n");
        printf("5. Mostrar componentes\n");
        printf("6. Salir\n");

        printf("\nSeleccione una opcion: ");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                registrarProducto(
                    nombres,
                    demanda,
                    tiempo,
                    recursos
                );

                break;

            case 2:

                editarProducto(
                    nombres,
                    demanda,
                    tiempo,
                    recursos
                );

                break;

            case 3:

                eliminarProducto(
                    nombres,
                    demanda,
                    tiempo,
                    recursos
                );

                break;

            case 4:

                calcularProduccion(
                    nombres,
                    demanda,
                    tiempo,
                    recursos
                );

                break;

            case 5:

                mostrarProductos(
                    nombres,
                    demanda,
                    tiempo,
                    recursos
                );

                break;

            case 6:

                printf("\nFin del sistema.\n");

                break;

            default:

                printf("\nERROR: Opcion invalida.\n");
        }

    }
    while(opcion != 6);

    return 0;
}