#include <iostream>
#include <vector>
#include "sorting.h"

int main() {
    std::vector<int> arr = { 5, 3, 8, 1, 2 };

    babelkowe_klasyk(arr);
    std::cout << "Bubble Sort wynik: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    arr = { 5, 3, 8, 1, 2 };
    babelkowe_lepsze(arr);
    std::cout << "Bubble Sort wynik: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    return 0;
}
