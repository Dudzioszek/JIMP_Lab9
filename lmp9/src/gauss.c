#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){


    int n = mat->r; // Pobranie liczbę wierszy macierzy

    for (int i = 0; i < n; i++) {
        
        if (mat->data[i][i] == 0) {
            return 1; // macierz osobliwa
        }
		// bez wybory elementu diagonalnego
		
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
