#include<stdio.h>
#include <string.h>

struct CD{
    int codigo;
    char artista[30];
    char album[30];
    int no_canciones;
    float precio;
    int existencias;
};
//Prototipos
struct CD nuevo_CD();
void mostrar_Stock(struct CD stock_cds);
int buscar_CD(struct CD stock_cds[],int j);
int stock(int j);
struct CD modificar_CD(struct CD stock_cds);
int venta_CD(int existencias,float precio_disco);
int main(){
    struct CD stock_records[50];
    int i = 0,j = 0,posicion = 0;
    do{
        printf("---- BIENVENIDO A NUESTRO MENU ---- \n");
        printf(" Selecciona una opcion para continuar ... ");
        printf("\n 1) Agregar CD's \n");
        printf("   2) Mostrar todos los registros \n");
        printf("   3) Buscar CD's por codigo \n");
        printf("   4) Modificar registro de un CD \n");
        printf("   5) Realizar una venta de CD's \n");
        printf("   6) Salir del sistema \n");
        scanf("%i",&i);
        switch(i){
            case 1:
                if(j >= 0 && j <= 50){
                    stock_records[j]=nuevo_CD();
                    j++;
                }else{
                    printf("El sistema no  puede guardar mas discos, se ha alcanzado el limite de registros");
                }
                break;
            case 2:
                if(stock(j) == 1){
                    for(int z = 0; z < j; z++){
                        mostrar_Stock(stock_records[z]);
                    }
                }
                break;
            case 3:
                if(stock(j) == 1){
                    posicion = buscar_CD(stock_records,j);
                    if(posicion > -1){
                        mostrar_Stock(stock_records[posicion]);
                    }
                }
                break;
            case 4:
                if(stock(j) == 1){
                    posicion=buscar_CD(stock_records,j);
                    if(posicion > -1){
                        stock_records[posicion] = modificar_CD(stock_records[posicion]);
                    }
                }
                break;
            case 5:
                if(stock(j) == 1){
                    posicion=buscar_CD(stock_records,j);
                    if(posicion > -1){
                        mostrar_Stock(stock_records[posicion]);
                        stock_records[posicion].existencias = venta_CD(stock_records[posicion].existencias, stock_records[posicion].precio);
                    }
                }
                break;
        }
    }while(i != 6);
    return 0;
}

int stock(int j){
    if(j == 0){
        printf("\n No hay discos registrados \n");
        return 0;
    }else{
        return 1;
    }
}

//Funcion registro nuevo
struct CD nuevo_CD(){
    struct CD nuevoCD;
    printf("\n Introduce el codigo del disco \n");
    scanf("%i",&nuevoCD.codigo);
    getchar();
    printf("\nIntroduce el nombre del artista \n");
    fgets(nuevoCD.artista,30,stdin);
    printf("\n Introduce el nombre del álbum\n");
    fgets(nuevoCD.album,30,stdin);
    printf("\n Introduce el numero de las canciones\n");
    scanf("%i",&nuevoCD.no_canciones);
    printf("\n Introduce el precio de los discos\n");
    scanf("%f",&nuevoCD.precio);
    printf("\n Introduce el numero de existencias del disco\n");
    scanf("%i",&nuevoCD.existencias);
    return nuevoCD;
}

void mostrar_Stock(struct CD stockCD){
            printf("\n Codigo: %i \n",stockCD.codigo);
            printf("\n Nombre Artista: %s \n",stockCD.artista);
            printf("\n Nombre Album: %s \n",stockCD.album);
            printf("\n Numero de canciones: %i \n",stockCD.no_canciones);
            printf("\n Precio del disco: $%.2f \n",stockCD.precio);
            printf("\n Existencias del disco: %i \n",stockCD.existencias);
}

int buscar_CD(struct CD stockCD[], int j){
    int codigo = 0;
     printf("\n Introducir codigo del disco a localizar... \n");
     scanf("%i",&codigo);
    for(int f = 0;f < j;f++){
        if(codigo == stockCD[f].codigo){
            return f;
        }
    }
    printf("\n El codigo no coincide con ningun disco registrado en el sistema \n ");
    return -1;
}

struct CD modificar_CD(struct CD stockCD){
        int s = 0;
        printf("\n  Selecciona una opción para continuar ... \n ");
        printf("\n 1) Modificar Codigo \n");
        printf("  \n  2) Modificar nombre \n");
        printf("  \n  3) Modificar Album \n");
        printf("  \n  4) Modificar Numero de canciones \n");
        printf("  \n  5) Modificar precio del disco \n");
        printf("  \n  6) Modificar existencias disponibles \n");
        printf("  \n  7) Cancelar  \n");
        scanf("%i",&s);
        getchar();
        switch(s){
            case 1:
                printf("\n Introduce el nuevo codigo del disco \n");
                scanf("%i",&stockCD.codigo);
                break;
            case 2:
            	 printf("\n Introduce el nombre del artista\n");
                 fgets(stockCD.artista,30,stdin);
                break;
            case 3:
                printf("\n Introduce el nombre del álbum\n");
                 fgets(stockCD.album,30,stdin);
                break;
            case 4:
                printf("\n Introduce el numero de las canciones\n");
                scanf("%i",&stockCD.no_canciones);
                break;
            case 5:
                printf("\n Introduce el precio de los discos\n");
                scanf("%f",&stockCD.precio);
                break;
            case 6:
                printf("\n Introduce el numero de existencias del disco\n");
                scanf("%i",&stockCD.existencias);
                break;

        }
        return stockCD;
}

int venta_CD(int oferta,float precio_disco){
    int demanda = 0;
    if(oferta == 0){
        printf("\n No hay existencias para realizar la transacción \n ");
        return 0;
    }

    printf("\n Hay %i existencias \n  Introduce la cantidd de discos a vender \n ",oferta);
    scanf("%i",&demanda);
    if(demanda > oferta){
        printf("\n No se puede realizar la tansacción. Solo Hay %i existencias \n",oferta);
        return oferta;
    }else{
        printf("\n El total de la venta de %i discos es $%.2f \n Ahora solo quedan %i existencia(s)\n",demanda,demanda*precio_disco,oferta-demanda);
        return oferta-demanda;
    }
}
