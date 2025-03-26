#include <iostream>
#include <vector>
#include <cstdlib> // do generowania losowych liczb 
#include <chrono> // do mierzenia czasu
#include "sorting.h"

using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr;
    vector<int> badane; 

    
    

       

        

    
    // generuje liste 
    int ilosc=1000000;
    for (int i = 0; i < ilosc; i++) {
        badane.push_back(rand());
        //cout << badane[i] << endl;
    }

    /*
    
    auto start = chrono::high_resolution_clock::now();
   // for (int i = 0; i < 100; i++) {
        arr = badane;
        babelkowe_klasyk(arr);
  //  }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Bubble Sort wynik: ";
    //for (int num : arr) cout << num << " ";
    cout << endl << duration.count() << " ms" << endl << endl;
    


    
    start = chrono::high_resolution_clock::now();
    //for (int i = 0; i < 100; i++) {
        arr = badane;
        babelkowe_lepsze(arr);
    //}
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Bubble Sort lepszy wynik: ";
    //for (int num : arr) cout << num << " ";
    cout << endl << duration.count() << " ms" << endl << endl;
    */

    cout << "Tablica przed sortowaniem:" << endl;
   // printArray(badane);
    
    auto start = chrono::high_resolution_clock::now();
    //for (int i = 0; i < 100; i++) 
    {
        arr = badane;
        sort_kopcowanie(arr);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "kopiec wynik: ";
    //for (int num : arr) cout << num << " ";
    cout << endl << duration.count()  << " ms" << endl << endl;
    
    
    start = chrono::high_resolution_clock::now();
    //for (int i = 0; i < 100; i++) 
    {
        arr = badane;
        sort_scalanie(arr, 0, arr.size() - 1);
    }
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "scalanie wynik: ";
    //for (int num : arr) cout << num << " ";
    cout << endl << duration.count() << " ms" << endl << endl;


    

    
    
    return 0;
}
