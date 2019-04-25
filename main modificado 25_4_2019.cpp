#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

void matriz(int n, int m);
void cargar_matriz(int **&pmatriz,int n,int m);
void mostrar(int **pmatriz, int n, int m);
void liberar(int **pmatriz, int n);
bool validar(int **&pmatriz, int &i, int &j, int &band, int &y);


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
    bool Z;
    int i = 0, j = 0, band, y;
    int **pmatriz = new int *[n];

    for(int i=0; i<n; i++){
        pmatriz[i] = new int [m];
    }

    cargar_matriz(pmatriz, n, m);

    Z = validar(pmatriz,band,i,j,y);

    mostrar(pmatriz, n, m);

    cout << endl;

    if (Z == true)
        cout << "Matriz valida" << endl;
    else cout << "Matriz Invalida" << endl;

    liberar(pmatriz, n);
}

void cargar_matriz(int **&pmatriz,int n,int m){
    int NUM, x, y, i, j, band;

    srand(time(0));

    cout <<"Ingrese un numero con el que quiera cargar la matriz: ";
    cin >> x;
    cout <<"Ingrese otro numero con el que quiera cargar la matriz: ";cin.get();
    cin >> y;


    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            NUM = x + rand()%(y+1-x);
            if (NUM == x){
                pmatriz[i][j] = NUM;}
            else {
                pmatriz[i][j] = y;}
        }
    }



    //validar(pmatriz,i,j,band,y);

}

bool validar(int **&pmatriz, int &i, int &j, int &band, int &y){

    //int i=0,j=0;

    if ((pmatriz[i][j] == y) && ((pmatriz[i][j+1] == y) || (pmatriz[i+1][j] == y)) && (i == 0) && (j == 0))
        band = 1;
    else if ((pmatriz[i][j] == y) && ((pmatriz[i][j+1] == y) || (pmatriz[i+1][j] == y) || (pmatriz[i-1][j] == y) || (pmatriz[i][j+1] == y)) && (i != 0) && (j != 0))
        band = 1;

    if (band == 1)
        return (true);
    else return (false);
}

void mostrar(int **pmatriz, int n, int m){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout << pmatriz[i][j] << " ";
        }
        cout << endl;
    }

}

void liberar(int **pmatriz, int n){
    for(int i=0; i<n; i++){
        delete[] pmatriz[i];
    }
    delete[] pmatriz;
}
