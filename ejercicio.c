#include <stdio.h>

/*
Este programa permite administrar la produccion
de una fabrica de componentes electronicos.

El sistema permite:
- Registrar productos
- Editar productos
- Eliminar productos
- Calcular produccion
- Mostrar productos registrados

Se utilizaron:
- Arreglos paralelos
- Punteros
- Busqueda lineal manual
- Validaciones manuales

Restricciones cumplidas:
- Sin struct
- Sin archivos
- Sin funciones creadas por el usuario
*/

int main()
{
    /*
    Arreglos principales.

    Cada posicion representa un producto.
    */

    char nombres[5][20];

    int demanda[5];

    /*
    El tiempo se manejara en HORAS.
    */

    float tiempo[5];

    /*
    Los recursos se manejaran en UNIDADES.
    */

    float recursos[5];

    /*
    Punteros para trabajar directamente
    con los arreglos.
    */

    int *ptrDemanda;

    float *ptrTiempo;

    float *ptrRecursos;

    /*
    Variables generales del programa.
    */

    int i, j;

    int opcion;

    int indiceVacio;

    int encontrado;

    char buscar[20];

    float tiempo_total;

    float recursos_totales;

    /*
    Limites maximos disponibles
    en la fabrica.
    */

    float limite_tiempo;

    float limite_recursos;

    /*
    Inicializacion de arreglos.
    */

    for(i = 0; i < 5; i++)
    {
        nombres[i][0] = '\0';

        ptrDemanda = &demanda[i];
        *ptrDemanda = 0;

        ptrTiempo = &tiempo[i];
        *ptrTiempo = 0;

        ptrRecursos = &recursos[i];
        *ptrRecursos = 0;
    }

    /*
    MENU PRINCIPAL DEL SISTEMA
    */

    do
    {
        
        printf(" SISTEMA DE PRODUCCION INDUSTRIAL\n");

        printf("1. Registrar productos\n");
        printf("2. Editar productos\n");
        printf("3. Eliminar productos\n");
        printf("4. Calcular capacidad de produccion\n");
        printf("5. Mostrar productos\n");
        printf("6. Salir\n");

        printf("\nSeleccione una opcion: ");

        scanf("%d", &opcion);

        /*
        
        OPCION 1
        REGISTRAR PRODUCTOS
        

        Se ingresan:
        - nombre del producto
        - demanda requerida
        - tiempo de fabricacion en horas
        - recursos necesarios en unidades

        Tambien se valida:
        - que no existan negativos
        - que no existan productos repetidos
        */

        if(opcion == 1)
        {
            indiceVacio = -1;

            for(i = 0; i < 5; i++)
            {
                if(nombres[i][0] == '\0')
                {
                    indiceVacio = i;

                    break;
                }
            }

            if(indiceVacio == -1)
            {
                printf("\nERROR: No existe espacio disponible.\n");
            }
            else
            {
                printf("\nIngrese nombre del producto a fabricar: ");

                scanf(" %[^\n]", nombres[indiceVacio]);

                encontrado = 0;

                for(i = 0; i < 5; i++)
                {
                    if(i != indiceVacio)
                    {
                        j = 0;

                        while(nombres[i][j] ==
                              nombres[indiceVacio][j] &&

                              nombres[i][j] != '\0' &&

                              nombres[indiceVacio][j] != '\0')
                        {
                            j++;
                        }

                        if(nombres[i][j] == '\0' &&
                           nombres[indiceVacio][j] == '\0')
                        {
                            encontrado = 1;
                        }
                    }
                }

                if(encontrado == 1)
                {
                    printf("\nERROR: El producto ya existe.\n");

                    nombres[indiceVacio][0] = '\0';
                }
                else
                {
                    ptrDemanda = &demanda[indiceVacio];

                    printf("Ingrese demanda requerida de fabricacion (unidades): ");

                    scanf("%d", ptrDemanda);

                    while(*ptrDemanda < 0)
                    {
                        printf("ERROR: No se permiten negativos: ");

                        scanf("%d", ptrDemanda);
                    }

                    ptrTiempo = &tiempo[indiceVacio];

                    printf("Ingrese el tiempo de fabricacion por unidad (horas): ");

                    scanf("%f", ptrTiempo);

                    while(*ptrTiempo < 0)
                    {
                        printf("ERROR: No se permiten negativos: ");

                        scanf("%f", ptrTiempo);
                    }

                    ptrRecursos = &recursos[indiceVacio];

                    printf("Ingrese el numero de componentes necesarios por unidad: ");

                    scanf("%f", ptrRecursos);

                    while(*ptrRecursos < 0)
                    {
                        printf("ERROR: No se permiten negativos: ");

                        scanf("%f", ptrRecursos);
                    }

                    printf("\nProducto registrado correctamente.\n");
                }
            }
        }

        /*
        
        OPCION 2
        EDITAR PRODUCTOS
        

        Se busca un producto mediante
        busqueda lineal manual y luego
        se actualizan sus datos.
        */

        else if(opcion == 2)
        {
            printf("\nIngrese nombre del producto a editar: ");

            scanf(" %[^\n]", buscar);

            encontrado = -1;

            for(i = 0; i < 5; i++)
            {
                j = 0;

                while(nombres[i][j] == buscar[j] &&
                      nombres[i][j] != '\0' &&
                      buscar[j] != '\0')
                {
                    j++;
                }

                if(nombres[i][j] == '\0' &&
                   buscar[j] == '\0')
                {
                    encontrado = i;

                    break;
                }
            }

            if(encontrado != -1)
            {
                printf("\nNuevo nombre del producto: ");

                scanf(" %[^\n]", nombres[encontrado]);

                ptrDemanda = &demanda[encontrado];

                printf("Ingrese la nueva demanda de productos requerida (unidades): ");

                scanf("%d", ptrDemanda);

                while(*ptrDemanda < 0)
                {
                    printf("ERROR: No se permiten negativos: ");

                    scanf("%d", ptrDemanda);
                }

                ptrTiempo = &tiempo[encontrado];

                printf("Ingrese el nuevo tiempo de fabricacion por unidad (horas): ");

                scanf("%f", ptrTiempo);

                while(*ptrTiempo < 0)
                {
                    printf("ERROR: No se permiten negativos: ");

                    scanf("%f", ptrTiempo);
                }

                ptrRecursos = &recursos[encontrado];

                printf("Ingrese la nueva cantidad de componentes necesarios por unidad: ");

                scanf("%f", ptrRecursos);

                while(*ptrRecursos < 0)
                {
                    printf("ERROR: No se permiten negativos: ");

                    scanf("%f", ptrRecursos);
                }

                printf("\nProducto editado correctamente.\n");
            }
            else
            {
                printf("\nERROR: Producto no encontrado.\n");
            }
        }

        /*
      
        OPCION 3
        ELIMINAR PRODUCTOS
       

        Se busca el producto y se realiza
        una eliminacion logica limpiando
        sus datos del arreglo.
        */

        else if(opcion == 3)
        {
            printf("\nIngrese nombre del producto a eliminar: ");

            scanf(" %[^\n]", buscar);

            encontrado = -1;

            for(i = 0; i < 5; i++)
            {
                j = 0;

                while(nombres[i][j] == buscar[j] &&
                      nombres[i][j] != '\0' &&
                      buscar[j] != '\0')
                {
                    j++;
                }

                if(nombres[i][j] == '\0' &&
                   buscar[j] == '\0')
                {
                    encontrado = i;

                    break;
                }
            }

            if(encontrado != -1)
            {
                nombres[encontrado][0] = '\0';

                ptrDemanda = &demanda[encontrado];
                *ptrDemanda = 0;

                ptrTiempo = &tiempo[encontrado];
                *ptrTiempo = 0;

                ptrRecursos = &recursos[encontrado];
                *ptrRecursos = 0;

                printf("\nProducto eliminado correctamente.\n");
            }
            else
            {
                printf("\nERROR: Producto no encontrado.\n");
            }
        }

        /*
      
        OPCION 4
        CALCULAR PRODUCCION
       

        El sistema calcula:
        - tiempo total requerido
        - recursos totales requeridos

        Luego compara si la fabrica
        puede cumplir con la demanda.
        */

        else if(opcion == 4)
        {
            tiempo_total = 0;

            recursos_totales = 0;

            for(i = 0; i < 5; i++)
            {
                if(nombres[i][0] != '\0')
                {
                    ptrDemanda = &demanda[i];

                    ptrTiempo = &tiempo[i];

                    ptrRecursos = &recursos[i];

                    tiempo_total =
                    tiempo_total +
                    ((*ptrDemanda) * (*ptrTiempo));

                    recursos_totales =
                    recursos_totales +
                    ((*ptrDemanda) * (*ptrRecursos));
                }
            }

            printf("\nTiempo total requerido: %.2f horas\n",
            tiempo_total);

            printf("Recursos totales requeridos: %.2f unidades\n",
            recursos_totales);

            printf("\nIngrese las horas operativas disponibles para la linea de produccion (horas): ");

            scanf("%f", &limite_tiempo);

            while(limite_tiempo < 0)
            {
                printf("ERROR: No se permiten negativos: ");

                scanf("%f", &limite_tiempo);
            }

            printf("Ingrese la cantidad de componentes disponibles en fabrica: ");

            scanf("%f", &limite_recursos);

            while(limite_recursos < 0)
            {
                printf("ERROR: No se permiten negativos: ");

                scanf("%f", &limite_recursos);
            }

            if(tiempo_total <= limite_tiempo &&
               recursos_totales <= limite_recursos)
            {
                printf("\nLa fabrica SI puede cumplir la demanda.\n");
            }
            else
            {
                printf("\nLa fabrica NO puede cumplir la demanda.\n");
            }
        }

        /*
        
        OPCION 5
        MOSTRAR PRODUCTOS
        

        Se muestran todos los productos
        registrados actualmente.
        */

        else if(opcion == 5)
        {
            printf("\n PRODUCTOS \n");

            for(i = 0; i < 5; i++)
            {
                if(nombres[i][0] != '\0')
                {
                    printf("\nProducto %d\n", i + 1);

                    printf("Nombre: %s\n", nombres[i]);

                    printf("Demanda: %d unidades\n", demanda[i]);

                    printf("Tiempo: %.2f horas\n", tiempo[i]);

                    printf("Recursos: %.2f unidades\n", recursos[i]);
                }
            }
        }

        /*
        OPCION 6
        FINALIZAR PROGRAMA
        */

        else if(opcion == 6)
        {
            printf("\nFin del programa.\n");
        }

        /*
        Validacion de opcion invalida.
        */

        else
        {
            printf("\nERROR: Opcion invalida.\n");
        }

    }
    while(opcion != 6);

    return 0;
}
