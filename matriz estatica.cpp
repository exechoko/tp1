#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int M[100][100], filas, columnas,i,j;
    srand(time(0));

    cin>>filas;
    cin>>columnas;
    for(i=0; i<filas; i++){
        for(j=0; j<columnas;j++)
        {

            M[i][j]=rand()%2;// carga aleatoriamente de 0 y 1
            //M[i][j]=0; // carga con 0 toda la matriz
        }
    }
     M[0][0] = 1; //al primer valor le asigno el 1 para que compare en el primer if

     //M[1][1] = 1;
    // M[2][2] = 1;




    for(i=0; i<filas; i++){// muestra la matriz
        for(j=0; j<columnas;j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }



    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){


            if (( M[i][j] != M[i][j+1] ) && ( M[i][j] != M[i+1][j] ) && ( i == 0) && ( j == 0)) //compara con el primer elemento i:0 j:0
                cout << " Elemento: [" << i << "][" << j << "] " << "invalido  i: " << i << " j: " << j << endl; // muestra el lugar donde quedo un area cerrada
            else

            if (( M[i][j] != M[i][j+1] ) && ( M[i][j] != M[i+1][j] ) && ( M[i][j] != M[i][j-1] ) && ( i == 0) ) // compara en la primer fila i=0
                cout << " Elemento: [" << i << "][" << j << "] " << "invalido  i: " << i << " j: " << j << endl;
            else

            if (( M[i][j] != M[i][j+1] ) && ( M[i][j] != M[i+1][j] ) && ( M[i][j] != M[i-1][j] ) && ( j == 0) ) // compara en la primer columna
                cout << " Elemento: [" << i << "][" << j << "] " << "invalido  i: " << i << " j: " << j << endl;
            else

            if (( M[i][j] != M[i][j+1] ) && ( M[i][j] != M[i+1][j] ) && ( M[i][j] != M[i-1][j] ) && ( M[i][j] != M[i][j-1] ) && ( i != 0) &&( j != 0) ) // compara en el resto de la matriz
                cout << "invalido  i: " << i << " j: " << j << endl;
            else cout << " Elemento: [" << i << "][" << j << "] " <<"valido" << endl; // muestra donde no quedo area cerrada




        /*if (( 1 != M[i][j+1] ) && ( 1 != M[i+1][j] ) && ( i == 0) && ( j == 0)){// para el primer elemento
            cout << "invalido  i: " << i << " j: " << j << endl;
        } else if (( 1 != M[i][j+1] ) && ( 1 != M[i+1][j] ) && ( 1 != M[i][j-1] ) && ( i == 0) ){ // para la primer fila completa
            cout << "invalido  i: " << i << " j: " << j << endl;}
        else if (( 1 != M[i][j+1] ) && ( 1 != M[i+1][j] ) && ( 1 != M[i][j-1] ) && ( 1 != M[i-1][j] ) && ( i == 1) ){ // para la segunda fila completa
            cout << "invalido  i: " << i << " j: " << j << endl;}
        else  cout << "valido" << endl;*/


    }
}


    return 0;
}
