#include <iostream>
#include <vector>
#include <cstdlib> // do generowania losowych liczb 
#include <chrono> // do mierzenia czasu
#include "sorting.h"
using namespace std;
int main() {
    vector<int> arr;
    vector<int> badane; 

    // generuje liste 
    int ilosc=50000;
    for (int i = 0; i < ilosc; i++) {
        badane.push_back(rand());
        //cout << badane[i] << endl;
    }

    
    arr = badane;
    auto start = chrono::high_resolution_clock::now();
    babelkowe_klasyk(arr);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Bubble Sort wynik: ";
    //for (int num : arr) cout << num << " ";
    cout << endl << duration.count() << " ms" << endl << endl;
    


    arr = badane;
    start = chrono::high_resolution_clock::now();
    babelkowe_lepsze(arr);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Bubble Sort wynik: ";
    //for (int num : arr) cout << num << " ";
    cout << endl << duration.count() << " ms" << endl << endl;
    return 0;
}
