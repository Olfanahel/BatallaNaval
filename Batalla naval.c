#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void colocarBarcos(char [][5]);
int validacion(int,int);
void mostrarTablero(char [][5],int,int);
int disparo(char [][5],int);


int main()
{
    int hundidoJ1=0,hundidoJ2=0,disparoEfectuado;
   char tablero[5][5],tableroJugadorUno[5][5],tableroJugadorDos[5][5];

   printf("\nJUGADOR 1");
   colocarBarcos(tableroJugadorUno);
   printf("\nJUGADOR 2");
   colocarBarcos(tableroJugadorDos);
   while(hundidoJ1!=5&&hundidoJ2!=5)
   {
        system("cls");
        printf("Tablero Jugador 2: \n");
        mostrarTablero(tableroJugadorDos,5,5);
        disparoEfectuado=disparo(tableroJugadorDos,1);
        if(disparoEfectuado==1)
            hundidoJ2++;

        if(hundidoJ2!=5)
        {
            system("cls");
            printf("Tablero Jugador 1: \n");
            mostrarTablero(tableroJugadorUno,5,5);
            disparoEfectuado=disparo(tableroJugadorUno,2);
            if(disparoEfectuado==1)
                hundidoJ1++;
        }
   }


   return 0;
}

void colocarBarcos(char mat[][5])
{
    int i=1,fila,columna;

    while(i<6)
    {
        printf("\nIndique la fila del %d barco: ",i);
        fila=validacion(1,5);
        printf("\nIndique la columna del %d barco: ",i);
        columna=validacion(1,5);
        if(mat[fila-1][columna-1]=='B')
            printf("\nUbicacion ocupada, vuelva a ingresar");
        else
        {
            mat[fila-1][columna-1]='B';
            i++;
        }
    }
}

int validacion(int a,int b)
{
    int dato;
    do
    {
        scanf("%d",&dato);
        if(dato<a||dato>b)
            printf("Error,fuera de rango vuelva a ingresar");
    }while(dato<a||dato>b);
    return dato;
}

void mostrarTablero(char mat[][5],int cf,int cc)
{
    int i,j;

    printf(" ");
    for(i=0;i<cf;i++)
    {
        printf("%3d",i+1);
    }
    printf("\n");
    for(i=0;i<cf;i++)
    {
        printf("%2d",i+1);
        for(j=0;j<cc;j++)
        {
            if(mat[i][j]=='X')
                printf("[X]");
            else
            {
                if(mat[i][j]=='A')
                    printf("[A]");
                else
                    printf("[ ]");
            }
        }
        printf("\n");
    }
}


int disparo(char mat[][5],int jugador)
{
    int filaDisparo,columnaDisparo;

    printf("Jugador %d indique fila para disparo: ",jugador);
    filaDisparo=validacion(1,5);
    printf("Jugador %d indique columna para disparo: ",jugador);
    columnaDisparo=validacion(1,5);
    if(mat[filaDisparo-1][columnaDisparo-1]=='B')
    {
        mat[filaDisparo-1][columnaDisparo-1]='X';
        return 1;
    }
    else
    {
        mat[filaDisparo-1][columnaDisparo-1]='A';
        return 0;
    }

}
