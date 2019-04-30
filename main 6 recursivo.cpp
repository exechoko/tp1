#include <iostream>

using namespace std;



void matriz(int n, int m);
void cargar_matriz(int **&pmatriz,int n,int m);
void mostrar(int **&pmatriz, int n, int m);
void areascerradas (int **&pmatriz, int n, int m);
void liberar(int **&pmatriz, int n);

int main()
{
    int **pmatriz = NULL;
    int filas, columnas;

    cout << "Filas: "; cin >> filas;
    cout << "Columnas: "; cin >> columnas;

    matriz(filas, columnas);
    //cargar_matriz(pmatriz, filas, columnas);
    //mostrar(pmatriz, filas, columnas);
    liberar(pmatriz, filas);

    return 0;
}

void matriz(int n, int m){
    int i,j;
    int **pmatriz = new int *[n];

    for(i=0;i<n;i++){
        pmatriz[i] = new int [m];
    }

    cargar_matriz(pmatriz, n, m);
    mostrar(pmatriz, n, m);
    areascerradas (pmatriz,n,m);
}

void cargar_matriz(int **&pmatriz,int n,int m){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            pmatriz[i][j] = rand()%2;
        }
    }
    pmatriz[0][0] = 1;
}

void mostrar(int **&pmatriz, int n, int m){
    int i, j;
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

void areascerradas (int **&pmatriz, int n, int m){
    int i=0,j=0;

    if ( (pmatriz[i][j] == 1) && ((pmatriz [i][j+1] == 1 ) || (pmatriz[i+1][j] == 1 )) )
    {   i++;j++;
        return (areascerradas (pmatriz, n-1, m-1) );
    } else cout << "area cerrada en [" << i << "][" << j << "]" << endl;
}

void cuadriculacerrada (int **pmatriz, int i, int j, int n, int m){
    if (pmatriz[i][j] != (pmatriz[i+1][j] && pmatriz[i][j+1]))
        cout << "Cerrada";

}
