#include "sorting.h"
#include <iostream>

using namespace std;

void babelkowe_klasyk(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                
            }            
        }
    }
}

void babelkowe_lepsze(std::vector<int>& arr) {
    int n = arr.size();
    int ostatnia; // Indeks ostatniej zamiany
    int nowy= n; // Zakres do którego sprawdzamy

    do {
        ostatnia = 0; // Resetowanie indeksu
        for (int i = 0; i < nowy - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                ostatnia = i + 1; // Zapamiêtujemy miejsce ostatniej zamiany
            }
        }
        nowy = ostatnia; // Kolejna iteracja obejmie tylko do ostatniej zamiany
    } while (ostatnia > 0);
}

