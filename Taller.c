//Josue Alarcon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5



int registrar(int cant, char nombre[MAX][50], float tiempo[MAX], int recursos[MAX], int demand[MAX] );
void mostrar(int cant, char nombre[MAX][50], float tiempo[MAX], int recursos[MAX], int demand[MAX] );
int buscar(char nbuscar[50], char nombre[MAX][50], int cant);
void editar(int cant, char nombre[MAX][50], float tiempo[MAX], int recursos[MAX], int demand[MAX]);
int eliminar(int cant, char nombre[MAX][50], float tiempo[MAX], int recursos[MAX], int demand[MAX]);
void calcular(int cant, char nombre[MAX][50], float tiempo[MAX], int recursos[MAX], int demand[MAX]);





int main()  
{
    int cant = 0;
    char nombre[MAX][50];
    float tiempo[MAX];
    int recursos[MAX];
    int demand[MAX];
    int opc = 0;



    do
    {
        system("cls");
        printf("=====Menu=====\n");
        printf("1. Registrar productos\n");
        printf("2. Mostrar productos registrados\n");
        printf("3. Editar productos\n");
        printf("4. Eliminar productos\n");
        printf("5. Calcular\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion del 1-6\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
        system("cls");
        cant = registrar(cant, nombre, tiempo, recursos, demand);
        system("pause");
        break;
        case 2:
        system("cls");
        mostrar(cant, nombre, tiempo, recursos, demand);
        system("pause");
        break;
        case 3:
        system("cls");
        editar(cant, nombre, tiempo, recursos, demand);
        system("pause");
        break;
        case 4:
        system("cls");
        cant = eliminar(cant, nombre, tiempo, recursos, demand);
        system("pause");
        break;
        case 5:
        system("cls");
        calcular(cant, nombre, tiempo, recursos, demand);
        system("pause");
        break;
        case 6:
        system("cls");
        printf("Saliendo del sistema....\n");
        system("pause");
        break;
    
        default:
        system("cls");
        printf("Ingrese una opcion validan...\n");
        system("pause");
        break;
    }


    } while (opc != 6);



    return 0;
}







int registrar(int cant, char nombre[MAX][50], float tiempo[MAX], int recursos[MAX], int demand[MAX] )
{
    
    printf("Que cantidad de productos desea registrar?\n");
    scanf("%d", &cant);

    if (cant > 5)
    {
        printf("Seleccione un numero menor a 5\n");
        cant = 0;
    }else if(cant <= 0)
    {
        printf("Ingrese un numero valido\n");
        cant = 0;

    }else
    {
        for (int i = 0; i < cant; i++)
        {
            printf("Ingrese el nombre del producto %d\n", i + 1);
            scanf(" %[^\n]", nombre[i]);
            printf("Ingrese el tiempo de fabricacion\n");
            scanf("%f", &tiempo[i]);
            printf("Ingrese los recursos unitarios\n");
            scanf("%d", &recursos[i]);
            printf("Ingrese la demanda requerida\n");
            scanf("%d", &demand[i]);
            printf("=================================================\n");
        }
        
    }
    

    return(cant);



}




void mostrar(int cant, char nombre[MAX][50], float tiempo[MAX], int recursos[MAX], int demand[MAX] )
{
    if (cant == 0)
    {
        printf("Advertencia no hay productos registrados\n");

    }else
    {
        for (int i = 0; i < cant; i++)
        {
            printf("El nombre del producto es %s\n", nombre[i]);
            printf("El tiempo de fabricacion es %.2f\n", tiempo[i]);
            printf("Los recursos necesarios son: %d\n", recursos[i]);
            printf("La demanda del producto es: %d\n", demand[i]);
            printf("=================================================\n");
        }
        



    }
    
}



int buscar(char nbuscar[50], char nombre[MAX][50], int cant)
{

    
    if (cant == 0)
    {
        printf("Advertencia: No hay productos registrados.\n");
        return -1; 
    } else{

    printf("Ingrese el nombre del producto que desea buscar: \n");
    scanf(" %[^\n]", nbuscar);

    for (int i = 0; i < cant; i++)
    {
        
        if (strcmp(nbuscar, nombre[i]) == 0)
        {
            return i; 
        }
    }
    }
    return -1; 
    
}



void editar(int cant, char nombre[MAX][50], float tiempo[MAX], int recursos[MAX], int demand[MAX])
{
    if (cant == 0)
    {
        printf("Advertencia: No hay productos registrados.\n");
       
    }
    else{

   
    char nbuscar[50];
    int pos = buscar(nbuscar, nombre, cant);

    if (pos == -1)
    {
        printf("El producto no fue encontrado\n");
    }else
    {
       
        printf("Ingrese el nuevo nombre del producto: \n");
        scanf(" %[^\n]", nombre[pos]);
        printf("Ingrese el nuevo tiempo de fabricacion: \n");
        scanf("%f", &tiempo[pos]);
        printf("Ingrese los nuevos recursos unitarios: \n");
        scanf("%d", &recursos[pos]);
        printf("Ingrese la nueva demanda requerida: \n");
        scanf("%d", &demand[pos]);
        printf("Producto editado con exito\n");
    }
    }

}



int eliminar(int cant, char nombre[MAX][50], float tiempo[MAX], int recursos[MAX], int demand[MAX])
{
    if (cant == 0)
    {
        printf("Advertencia: No hay productos registrados.\n");
       
    }
    else
    {

        char nbuscar[50];
        int pos = buscar(nbuscar, nombre, cant);
        if (pos == -1)
        {
            printf("El producto no fue encontrado\n");
        }
        else
        {
            for (int i = pos; i < cant - 1; i++)
            {
            strcpy(nombre[i], nombre[i + 1]);
            tiempo[i] = tiempo[i + 1];
            recursos[i] = recursos[i + 1];
            demand[i] = demand[i + 1];
            }
            cant = cant - 1;
            printf("El producto fue eliminado exitosamente\n");
        



        }
    }


    return cant;
}


void calcular(int cant, char nombre[MAX][50], float tiempo[MAX], int recursos[MAX], int demand[MAX])
{
    if (cant == 0)
    {
        printf("Advertencia: No hay productos registrados.\n");
       
    }else{
    float tiempot = 0;
    int recursost = 0;

    for (int i = 0; i < cant; i++)
    {
        tiempot += tiempo[i] * demand[i];
        recursost += recursos[i] * demand[i];
    }
    
    printf("El tiempo total de fabricacion necesario: %.2f horas\n", tiempot);
    printf("La cantidad total de recursos necesarios: %d unidades\n", recursost);

    float tiempod;
    int recursosd;
    printf("Ingrese el tiempo disponible en planta en horas: \n");
    scanf("%f", &tiempod);
    printf("Ingrese los recursos disponibles en bodega: \n");
    scanf("%d", &recursosd);



    
    if (tiempot <= tiempod && recursost <= recursosd)
    {
        printf("La fabrica si puede cumplir con la demanda solicitada\n");
    }
    else
    {
        printf("La fabrica no puede cumplir con la demanda\n");
        if (tiempot > tiempod)
        {
            printf("No hay suficiente tiempo: Se exceden %.2f horas del limite.\n", tiempot - tiempod);
        }
        if (recursost > recursosd)
        {
            printf("No hay suficientes recursos: Se exceden %d recursos del limite.\n", recursost - recursosd);
        }
    }
    }


}


