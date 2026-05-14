#include <stdio.h>
#include "funciones.h"



int buscarProducto(char nombres[][30], char buscar[])
{
    int i, j;

    for(i = 0; i < MAX; i++)
    {
        j = 0;

        while(
            nombres[i][j] == buscar[j] &&
            nombres[i][j] != '\0' &&
            buscar[j] != '\0'
        )
        {
            j++;
        }

        if(
            nombres[i][j] == '\0' &&
            buscar[j] == '\0'
        )
        {
            return i;
        }
    }

    return -1;
}



void registrarProducto(
    char nombres[][30],
    int demanda[],
    float tiempo[],
    float recursos[]
)
{
    int i;

    int indiceVacio = -1;

    int existe;

    int *ptrDemanda;

    float *ptrTiempo;

    float *ptrRecursos;

    for(i = 0; i < MAX; i++)
    {
        if(nombres[i][0] == '\0')
        {
            indiceVacio = i;

            break;
        }
    }

    if(indiceVacio == -1)
    {
        printf("\nERROR: Capacidad maxima alcanzada.\n");

        return;
    }

    printf("\nIngrese nombre del componente a fabricar: ");

    scanf(" %[^\n]", nombres[indiceVacio]);

    existe = buscarProducto(
        nombres,
        nombres[indiceVacio]
    );

    if(existe != -1 && existe != indiceVacio)
    {
        printf("\nERROR: El componente ya existe.\n");

        nombres[indiceVacio][0] = '\0';

        return;
    }

    ptrDemanda = &demanda[indiceVacio];

    printf("Ingrese cantidad de unidades requeridad: ");

    scanf("%d", ptrDemanda);

    while(*ptrDemanda < 0)
    {
        printf("ERROR: No se permiten negativos: ");

        scanf("%d", ptrDemanda);
    }

    ptrTiempo = &tiempo[indiceVacio];

    printf("Ingrese horas requeridas en linea de ensamblaje por unidad: ");

    scanf("%f", ptrTiempo);

    while(*ptrTiempo < 0)
    {
        printf("ERROR: No se permiten negativos: ");

        scanf("%f", ptrTiempo);
    }

    ptrRecursos = &recursos[indiceVacio];

    printf("Ingrese cantidad de componentes requeridos por unidad: ");

    scanf("%f", ptrRecursos);

    while(*ptrRecursos < 0)
    {
        printf("ERROR: No se permiten negativos: ");

        scanf("%f", ptrRecursos);
    }

    printf("\nComponente registrado correctamente.\n");
}

/* ==================================================
EDITAR COMPONENTE
================================================== */

void editarProducto(
    char nombres[][30],
    int demanda[],
    float tiempo[],
    float recursos[]
)
{
    char buscar[30];

    int posicion;

    int *ptrDemanda;

    float *ptrTiempo;

    float *ptrRecursos;

    printf("\nIngrese nombre de la unidad a editar: ");

    scanf(" %[^\n]", buscar);

    posicion = buscarProducto(nombres, buscar);

    if(posicion == -1)
    {
        printf("\nERROR: Unidad no encontrado.\n");

        return;
    }

    printf("\nNuevo nombre de la unidad: ");

    scanf(" %[^\n]", nombres[posicion]);

    ptrDemanda = &demanda[posicion];

    printf("Nueva cantidad de pedidos: ");

    scanf("%d", ptrDemanda);

    while(*ptrDemanda < 0)
    {
        printf("ERROR: No se permiten negativos: ");

        scanf("%d", ptrDemanda);
    }

    ptrTiempo = &tiempo[posicion];

    printf("Nuevas horas de ensamblaje: ");

    scanf("%f", ptrTiempo);

    while(*ptrTiempo < 0)
    {
        printf("ERROR: No se permiten negativos: ");

        scanf("%f", ptrTiempo);
    }

    ptrRecursos = &recursos[posicion];

    printf("Nueva cantidad de componentes requeridos por unidad: ");

    scanf("%f", ptrRecursos);

    while(*ptrRecursos < 0)
    {
        printf("ERROR: No se permiten negativos: ");

        scanf("%f", ptrRecursos);
    }

    printf("\nComponente actualizado correctamente.\n");
}

/* ==================================================
ELIMINAR COMPONENTE
================================================== */

void eliminarProducto(
    char nombres[][30],
    int demanda[],
    float tiempo[],
    float recursos[]
)
{
    char buscar[30];

    int posicion;

    printf("\nIngrese nombre del componente a eliminar: ");

    scanf(" %[^\n]", buscar);

    posicion = buscarProducto(nombres, buscar);

    if(posicion == -1)
    {
        printf("\nERROR: Componente no encontrado.\n");

        return;
    }

    nombres[posicion][0] = '\0';

    demanda[posicion] = 0;

    tiempo[posicion] = 0;

    recursos[posicion] = 0;

    printf("\nComponente eliminado correctamente.\n");
}

/* ==================================================
MOSTRAR COMPONENTES
================================================== */

void mostrarProductos(
    char nombres[][30],
    int demanda[],
    float tiempo[],
    float recursos[]
)
{
    int i;

    printf("\n====================================\n");
    printf(" COMPONENTES REGISTRADOS\n");
    printf("====================================\n");

    for(i = 0; i < MAX; i++)
    {
        if(nombres[i][0] != '\0')
        {
            printf("\nComponente %d\n", i + 1);

            printf("Nombre: %s\n", nombres[i]);

            printf("Unidades solicitados: %d\n", demanda[i]);

            printf("Horas de ensamblaje: %.2f\n", tiempo[i]);

            printf("Componentes requeridos: %.2f\n",
            recursos[i]);
        }
    }
}

/* ==================================================
ANALISIS DE PRODUCCION
================================================== */

void calcularProduccion(
    char nombres[][30],
    int demanda[],
    float tiempo[],
    float recursos[]
)
{
    int i;

    int *ptrDemanda;

    float *ptrTiempo;

    float *ptrRecursos;

    float tiempoTotal = 0;

    float recursosTotales = 0;

    float capacidadOperativa;

    float stockMateriales;

    for(i = 0; i < MAX; i++)
    {
        if(nombres[i][0] != '\0')
        {
            ptrDemanda = &demanda[i];

            ptrTiempo = &tiempo[i];

            ptrRecursos = &recursos[i];

            tiempoTotal =
            tiempoTotal +
            ((*ptrDemanda) * (*ptrTiempo));

            recursosTotales =
            recursosTotales +
            ((*ptrDemanda) * (*ptrRecursos));
        }
    }

    printf("\n====================================\n");
    printf(" ANALISIS INDUSTRIAL DE PRODUCCION\n");
    printf("====================================\n");

    printf("\nCarga operativa requerida: %.2f horas\n",
    tiempoTotal);

    printf("Materia prima requerida: %.2f unidades\n",
    recursosTotales);

    printf("\nIngrese el tiempo disponible para la fabricacion (horas): ");

    scanf("%f", &capacidadOperativa);

    while(capacidadOperativa < 0)
    {
        printf("ERROR: No se permiten negativos: ");

        scanf("%f", &capacidadOperativa);
    }

    printf("Ingrese stock de componentes disponibles: ");

    scanf("%f", &stockMateriales);

    while(stockMateriales < 0)
    {
        printf("ERROR: No se permiten negativos: ");

        scanf("%f", &stockMateriales);
    }

    printf("\n====================================\n");
    printf(" RESULTADO DEL ANALISIS\n");
    printf("====================================\n");

    if(
        tiempoTotal <= capacidadOperativa &&
        recursosTotales <= stockMateriales
    )
    {
        printf("\nLa fabrica puede cumplir los pedidos.\n");

        printf("La capacidad operativa y el stock\n");
        printf("de materiales son suficientes.\n");
    }
    else
    {
        printf("\nLa fabrica NO puede cumplir los pedidos.\n");

        if(tiempoTotal > capacidadOperativa)
        {
            printf("- Capacidad operativa insuficiente.\n");
        }

        if(recursosTotales > stockMateriales)
        {
            printf("- Materia prima insuficiente.\n");
        }
    }
}