#include <iostream>
#include <vector>
#include <cstdlib> // do generowania losowych liczb 
#include "sorting.h"
#include "generate.h"
#include "test.h"

using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr; 

        
    cout << endl << "1000" << endl;
    generuj(arr, 1000);
    test_heap(arr);
    test_merge(arr);
    test_merge_iter(arr);
    test_quick(arr);
    cout << endl << "10000" << endl;
    generuj(arr, 10000);
    test_heap(arr);
    test_merge(arr);
    test_merge_iter(arr);
    test_quick(arr);
    cout << endl << "50000" << endl;
    generuj(arr, 50000);
    test_heap(arr);
    test_merge(arr);
    test_merge_iter(arr);
    test_quick(arr);
    cout << endl << "100000" << endl;
    generuj(arr, 100000);
    test_heap(arr);
    test_merge(arr);
    test_merge_iter(arr);
    test_quick(arr);
    cout << endl << "500000" << endl;
    generuj(arr, 500000);
    test_heap(arr);
    test_merge(arr);
    test_merge_iter(arr);
    test_quick(arr);
    cout << "1000000" << endl;
    generuj(arr, 1000000);
    test_heap(arr);
    test_merge(arr);
    test_merge_iter(arr);
    test_quick(arr);

    

    
    

    

   
   
    
    

    
    
    
    
    return 0;
}
