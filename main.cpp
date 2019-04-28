#include <iostream>
//#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

void matriz(int n, int m);
void cargar_matriz(int **&pmatriz,int n,int m);
int areascerradas(int **&pmatriz,int n, int m, int &i, int &j, int &valor);
bool validar(int **&pmatriz, int n, int m, int &i, int &j, int x);
void mostrar(int **pmatriz, int n, int m, int x);
void liberar(int **pmatriz, int n);
//int areacerradas(int **&pmatriz, int &i, int &j, int &a);
//bool validar(int **&pmatriz,int n, int m);

int main()
{
    int filas, columnas;

    cout << "Ingrese la cantidad de filas: ";
    cin >> filas;
    cout << "Ingrese la cantida de columnas: ";
    cin >> columnas;

    matriz(filas,columnas);

    return 0;
}

void matriz(int n, int m){
    int i, j, y;
    int **pmatriz = new int *[n];

    for(int i=0;i<n;i++){
        pmatriz[i] = new int [m];
    }

    cargar_matriz(pmatriz, n, m);


    //mostrar(pmatriz, n, m); Esta función está ahora dentro de la función "cargar_matriz"

    liberar(pmatriz, n);
}

void cargar_matriz(int **&pmatriz,int n,int m){
    int NUM, x, y, i, j;

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
    }

 //   areascerradas(pmatriz,n,m,i,j,y); Ahora está dentro de la función "validar"


void mostrar(int **pmatriz, int n, int m, int x){
    int valor, i, j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout << pmatriz[i][j] << " ";
        }
        cout << endl;
    }

    if (validar(pmatriz,n,m,i,j,x) == true)
        cout << "Matriz Valida" << endl;
    else cout << "Matriz Invalida" << endl;
}

void liberar(int **pmatriz, int n){
    for(int i=0; i<n; i++){
        delete[] pmatriz[i];
    }
    delete[] pmatriz;
}

int areascerradas(int **&pmatriz,int n, int m, int &i, int &j, int &valor){
    int band = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           int band2=0;
            if(pmatriz[i][j]==valor){
                if (j==0 && i==0){
                    band2=1;
                    if((valor == pmatriz[i+1][j] )|| (valor == pmatriz[i][j+1] )){
                        band = 1;
                    }
                    else {
                       band = 0;
                    }
                }
                if (j==(m-1) && i==(n-1)){
                    band2=1;
                    if((valor == pmatriz[i-1][j])|| (valor == pmatriz[i][j-1] )){
                        band = 1;
                    }
                    else {
                        band = 0;
                    }
                }
                if (j==(m-1) && i==0){
                    band2=1;
                    if((valor == pmatriz[i+1][j] )|| (valor == pmatriz[i][j-1])){
                        band = 1;
                    }
                    else {
                        band =0;
                    }
                }
                if (j==0 && i==(n-1)){
                    band2=1;
                    if((valor == pmatriz[i-1][j] ) || (valor == pmatriz[i][j+1])){
                        band = 1;
                    }
                    else {
                        band =0;
                    }
                }
               if(band2==0){
                       if (j==0){
                           if((valor == pmatriz[i+1][j] )|| (valor == pmatriz[i][j+1] ) || (valor == pmatriz[i-1][j] )){
                               band = 1;
                           }
                           else {
                               band =0;
                           }
                       }
                       if (i==0){
                           if((valor == pmatriz[i+1][j] )|| (valor == pmatriz[i][j+1] ) || (valor == pmatriz[i][j-1])){
                               band = 1;
                           }
                           else {
                               band =0;
                           }
                       }
                       if (j==(m-1)){
                           if((valor == pmatriz[i+1][j] )|| (valor == pmatriz[i][j-1]) || (valor == pmatriz[i-1][j])){
                               band = 1;
                           }
                           else {
                               band =0;
                           }
                       }
                       if (i==(n-1)){
                           if((valor == pmatriz[i-1][j] )|| (valor == pmatriz[i][j-1]) || (valor == pmatriz[i][j+1])){
                               band = 1;
                           }
                           else {
                               band =0;
                           }
                       }
                   }
               }

                /*if ((valor == (pmatriz[i][j+1]  || pmatriz[i+1][j]))){
                    band = 1;
                } else {
                    if ((valor == (pmatriz[i][j+1] || pmatriz[i+1][j]))){
                        band = 1;
                }} else{
                    if ((valor == (pmatriz[i][j+1] || pmatriz[i][j-1] || pmatriz[i+1][j] || pmatriz[i-1][j]))){
                        band = 1;
                    } else{
                band = 0;
            }}*/
            if(band == 0){
                i=n;
                j=m;
            }
          }
         }



    return (band);
}


bool validar(int **&pmatriz, int n, int m, int &i, int &j, int x){
    int valor;
    //int band = 0;
    //pmatriz[i][j] = valor;

    /*for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if ((valor == (pmatriz[i][j+1]  || pmatriz[i+1][j])) && (i == 0)){
                band = 1;
            } else
                if ((valor == (pmatriz[i][j+1] || pmatriz[i+1][j])) && (j == 0)){
                        band = 1;
            } else
                    if ((valor == (pmatriz[i][j+1] || pmatriz[i][j-1] || pmatriz[i+1][j] || pmatriz[i-1][j])) && (i != 0) && (j != 0)){
                        band = 1;
            }
        }
     }*/



    if (areascerradas(pmatriz,n,m,i,j,x) == 1)
        return (true);
    else return (false);

}





/*if ((pmatriz[i][j] == pmatriz[i][j+1]) || (pmatriz[i][j] == pmatriz[i][j-1]) || (pmatriz[i][j] == pmatriz[i+1][j]) || pmatriz[i][j] == pmatriz[i-1][j])
{
    band=1;
    cout << band << " valido" <<endl;}
else  {
    band=0;
    cout << band << "No valido " << pmatriz[i][j] <<endl;
}
}

int areacerradas(int **&pmatriz, int &i, int &j, int &a){
    int band = 0;

    if (pmatriz[i][j+1] == a)//pmatriz[i][j+1])
            band=1;
    else if (pmatriz[i][j-1] == a)//pmatriz[i][j-1])
                band=1;
           else if (pmatriz[i+1][j] == a)//pmatriz[i+1][j])
                     band=1;
                else if (pmatriz[i-1][j] == a)// pmatriz[i-1][j])
                            band=1;
                     else band=0;

    return (band);
}

bool validar(int **&pmatriz,int n, int m){
    int i=0, j=0, a;

            areacerradas(pmatriz,i,j,a);



    if (areacerradas(pmatriz,i,j,a) == 1)
        return (true);
    else return (false);

}*/


/*Número aleatorios entre 250 y 420: 9y 12
  num=250+rand()%(421-250);*/
