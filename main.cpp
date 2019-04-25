#include <iostream>
//#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

void matriz(int n, int m);
void cargar_matriz(int **&pmatriz,int n,int m);
int areascerradas(int **&pmatriz,int n, int m, int &i, int &j, int &valor);
bool validar(int **&pmatriz, int n, int m, int &i, int &j);
void mostrar(int **pmatriz, int n, int m);
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


    mostrar(pmatriz, n, m);

    liberar(pmatriz, n);
}

void cargar_matriz(int **&pmatriz,int n,int m){
    int NUM, x, y, i, j;

    srand(time(0));

    cout <<"Ingrese un numero con el que quiera cargar la matriz: ";
    cin >> x;
    cout <<"Ingrese otro numero con el que quiera cargar la matriz: ";cin.get();
    cin >> y;


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            NUM = x + rand()%(y+1-x);
            if (NUM == x){
                pmatriz[i][j] = NUM;}
            else {
                pmatriz[i][j] = y;}
        }
    }
    areascerradas(pmatriz,n,m,i,j,y);

}

void mostrar(int **pmatriz, int n, int m){
    int valor, i, j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout << pmatriz[i][j] << " ";
        }
        cout << endl;
    }

    if (validar(pmatriz,n,m,i,j) == true)
        cout << "Matriz Valida" << endl;
    else cout << "Matriz Invalida";
}

void liberar(int **pmatriz, int n){
    for(int i=0; i<n; i++){
        delete[] pmatriz[i];
    }
    delete[] pmatriz;
}

int areascerradas(int **&pmatriz,int n, int m, int &i, int &j, int &valor){
    int band = 0;
    for(int i=0; i<n; i++){
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
     }
    return (band);
}


bool validar(int **&pmatriz, int n, int m, int &i, int &j){
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



    if (areascerradas(pmatriz,n,m,i,j,valor) == 1)
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
