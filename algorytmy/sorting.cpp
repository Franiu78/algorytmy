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
            for (int num : arr) cout << num << " ";
            cout << endl;
        }
    }
}

void babelkowe_lepsze(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);

            }
            for (int num : arr) cout << num << " ";
            cout << endl;
        }
    }
}

