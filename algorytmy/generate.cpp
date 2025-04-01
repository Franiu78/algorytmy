#include "generate.h"
#include <iostream>
#include <algorithm>


// generuje liste 
void generuj(vector<int>& arr, int ilosc)
{   
    vector<int> arr2;
    for (int i = 0; i < ilosc; i++)
    {
        arr2.push_back(rand());

    }
    arr = arr2;
}
//sortuje pierwsze miejsca (procentowo)
void sort_proc(vector<int>& arr, double procenty)
{
    int rozmiar = static_cast<int>(arr.size() * procenty);
    sort(arr.begin(), arr.begin() + rozmiar);
}
// sortuje na  odwrót
void sort_odwrot(vector<int>& arr)
{
    sort(arr.begin(), arr.end(), greater<int>());
}