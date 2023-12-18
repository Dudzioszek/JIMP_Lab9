#include "gauss.h"
#include <math.h>
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){


    int n = mat->r; // Pobranie liczbę wierszy macierzy
    
    int w;
    int p = 0;
    double max = 0;
    double temp;

    for (int i = 0; i < n; i++) {

    // *wybór elementu diagonalnego

        //szukam najwiekszego elementu w kolumnie (co do wartości bezwzględnej)
        for(int l = n-1; l >= i; l--) {
            if(fabs(mat -> data[l][i]) > fabs(max)) {
                max = mat -> data[l][i];
                w = l;
            }
        }

        //zamieniam miejscami wiersze w głównej macierzy
        for(int i2 = 0; i2 < n; i2++) {
            temp = mat->data[i][i2];
            mat->data[i][i2] = mat->data[w][i2];
            mat->data[w][i2] = temp;
        }

        //zamieniam miejscami wiersze w macierzy zawierającej wyniki
        temp = b->data[i][0];
        b->data[i][0] = b->data[w][0];
        b->data[w][0] = temp;
    
    //*
		
        for (int j = i + 1; j < n; j++) {
            //współczynnik do wyeliminowania elementów poniżej diagonalnego
            double factor = mat->data[j][i] / mat->data[i][i];

            
            for (int k = i; k < n; k++) {
                mat->data[j][k] -= factor * mat->data[i][k]; // wyeliminowanie elementów poniżej diagonalnego
            }
            b->data[j][0] -= factor * b->data[i][0];
        }
    }
    return 0; // Sukces
}
