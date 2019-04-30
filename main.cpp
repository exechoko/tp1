#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;

void matriz(int n, int m);
void cargar_matriz(int **&pmatriz,int n,int m);
int areascerradas(int **&pmatriz,int n, int m, int &i, int &j, int &valor);
bool validar(int **&pmatriz, int n, int m, int &i, int &j, int x);
void mostrar(int **pmatriz, int n, int m, int x);
void mostrar2(int **pmatriz, int n, int m, int x);
void liberar(int **&pmatriz, int n);


int main()
{
    int **pmatriz = NULL;
    int filas, columnas;

    cout << "Ingrese la cantidad de filas: ";
    cin >> filas;
    cout << "Ingrese la cantida de columnas: ";
    cin >> columnas;

    matriz(filas,columnas);

    liberar(pmatriz, filas);

    return 0;
}

void matriz(int n, int m){

    int **pmatriz = new int *[n];

    for(int i=0;i<n;i++){
        pmatriz[i] = new int [m];
    }

    cargar_matriz(pmatriz, n, m);

}

void cargar_matriz(int **&pmatriz,int n,int m){
    int NUM, x, y;

    srand(time(0));

    cout <<"Ingrese un numero con el que quiera cargar la matriz: ";
    cin >> x;
    cout <<"Ingrese otro numero con el que quiera cargar la matriz: ";
    cin >> y;

//En esta parte arregle un bug que, si ponias un valor de "x" mas grande que el de "y" no te mostraba la matriz
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(x < y){
                NUM = x + rand()%(y+1-x);
                if (NUM == x){
                     pmatriz[i][j] = NUM;}
                 else {
                     pmatriz[i][j] = y;}
            } else {
                NUM = y + rand()%(x+1-y);
                if (NUM == y){
                     pmatriz[i][j] = NUM;}
                 else {
                     pmatriz[i][j] = x;}
              }
        }
    }
    mostrar(pmatriz, n, m, x); //agregué el valor de x para que la funcion "validar" sea mas precisa
    cout << endl;
    //mostrar2(pmatriz, n, m, x);

}

 //   areascerradas(pmatriz,n,m,i,j,y); Ahora está dentro de la función "validar"


void mostrar(int **pmatriz, int n, int m, int x){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout << pmatriz[i][j] << " ";
        }
        cout << endl;
    }

    if (validar(pmatriz,n,m,i,j,x) == true)
        cout << "Matriz Valida" << endl;
    else {
        cout << "Matriz Invalida" << endl;
        mostrar2(pmatriz, n, m, x);
    }
}

void mostrar2(int **pmatriz, int n, int m, int x){
    int i, j;
    cout << "MATRIZ VALIDADA" << endl;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout << pmatriz[i][j] << " ";
        }
        cout << endl;
    }
}

void liberar(int **&pmatriz, int n){
    for(int i=0; i<n; i++){
        delete[] pmatriz[i];
    }
    delete[] pmatriz;
}

int areascerradas(int **&pmatriz,int n, int m, int &i, int &j, int &valor){
    int band = 1;
    int band3 = 1;
    for( i=0; i<n; i++){
       for( j=0; j<m; j++){

           int band = 1;
           int band2= 0;
            if(pmatriz[i][j]==valor){
                if (j==0 && i==0){
                    band2=1;
                    if((valor != pmatriz[i+1][j]) && (valor != pmatriz[i][j+1] )){
                       band = 0;
                    }
                }
                if (j==(m-1) && i==(n-1)){
                    band2=1;
                    if((valor != pmatriz[i-1][j]) && (valor != pmatriz[i][j-1] )){
                        band = 0;
                    }
                }
                if (j==(m-1) && i==0){
                    band2=1;
                    if((valor != pmatriz[i+1][j]) && (valor != pmatriz[i][j-1])){
                        band =0;
                    }
                }
                if (j==0 && i==(n-1)){
                    band2=1;
                    if((valor != pmatriz[i-1][j]) && (valor != pmatriz[i][j+1])){
                        band =0;
                    }
                }
               if(band2==0){
                       if (j==0){
                           band2=1;
                           if((valor != pmatriz[i+1][j]) && (valor != pmatriz[i][j+1] ) && (valor != pmatriz[i-1][j] )){
                               band =0;
                           }
                       }
                       if (i==0){
                           band2=1;
                           if((valor != pmatriz[i+1][j]) && (valor != pmatriz[i][j+1] ) && (valor != pmatriz[i][j-1])){
                               band =0;
                           }
                       }
                       if (j==(m-1)){
                           band2=1;
                           if((valor != pmatriz[i+1][j]) && (valor != pmatriz[i][j-1]) && (valor != pmatriz[i-1][j])){
                               band =0;
                           }
                       }
                       if (i==(n-1)){
                           band2=1;
                           if((valor != pmatriz[i-1][j]) && (valor != pmatriz[i][j-1]) && (valor != pmatriz[i][j+1])){
                               band =0;
                           }
                       }
                       if(band2==0){
                           if((valor != pmatriz[i-1][j]) && (valor != pmatriz[i][j-1]) && (valor != pmatriz[i][j+1]) && (valor != pmatriz[i+1][j])){
                               band =0;
                           }
                       }
                   }
               }


            if(band == 0){
                cout << "INVALIDA en ["<< i << "][" << j << "]" << endl;
                if ( (i==0) && (j==0) ){
                    pmatriz [i][j+1] = valor; // cambia el valor invalido
                    band3=0;}
                else if ( (i==(n-1)) && (j==(m-1)) ){
                        pmatriz [i][j-1] = valor; // cambia el valor invalido
                        band3=0;}
                    else if ( (i==0) && (j!=0) ){
                            pmatriz [i][j-1] = valor; // cambia el valor invalido
                            band3=0;}
                        else if ( (i!=0) && (j==0) ){
                                pmatriz [i-1][j] = valor; // cambia el valor invalido
                                band3=0;}
                            else if ( (i!=0) && (j!=0) ){
                                      pmatriz [i][j-1] = valor; // cambia el valor invalido
                                      band3=0;}
                                 else if ( (i==0) && (j==(m-1)) ){
                                           pmatriz [i][j-1] = valor; // cambia el valor invalido
                                           band3=0;}
                                       else if ( (i==(n-1)) && (j==0) ){
                                               pmatriz [i-1][j] = valor; // cambia el valor invalido
                                                band3=0;}
                                              else if ( (i!=0) && (j==(m-1)) ){
                                                      pmatriz [i-1][j] = valor; // cambia el valor invalido
                                                      band3=0;}
                                                    else if ( (i==(n-1)) && (j!=0) ){
                                                            pmatriz [i][j-1] = valor; // cambia el valor invalido(funciona)
                                                            band3=0;}
            }
       }
    }

    return (band3);
}


bool validar(int **&pmatriz, int n, int m, int &i, int &j, int x){

    if (areascerradas(pmatriz,n,m,i,j,x) == 1)
        return (true);
    else return (false);

}
