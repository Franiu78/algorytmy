#include "sorting.h"
#include <iostream>

using namespace std;

void babelkowe_klasyk(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                
            }            
        }
    }
}

void babelkowe_lepsze(vector<int>& arr) 
{
    int n = arr.size();
    int ostatnia; // Indeks ostatniej zamiany
    int nowy= n; // Zakres do którego sprawdzamy

    do 
    {
        ostatnia = 0; 
        for (int i = 0; i < nowy - 1; i++) 
        {
            if (arr[i] > arr[i + 1]) 
            {
                swap(arr[i], arr[i + 1]);
                ostatnia = i + 1; // Zapisujemy miejsce ostatniej zamiany
            }
        }
        nowy = ostatnia; // Kolejna iteracja obejmie tylko do ostatniej zamiany
    } while (ostatnia > 0);
}

void kopiec(vector<int>& arr, int n, int korzen)
{
    int max = korzen;  // Korzeñ (najwiêkszy element)
    int lewy = 2 * korzen + 1;  // Lewy syn
    int prawy = 2 * korzen + 2; // Prawy syn

    // Jeœli lewy syn jest wiêkszy od korzenia
    if (lewy < n && arr[lewy] > arr[max])   max = lewy;

    // Jeœli prawy syn jest wiêkszy od obecnego najwiêkszego
    if (prawy < n && arr[prawy] > arr[max]) max = prawy;

    // Jeœli najwiêkszy element nie jest korzeniem, zamieñ i rekurencyjnie popraw kopiec
    if (max != korzen) 
    {
        swap(arr[korzen], arr[max]);
        kopiec(arr, n, max);
    }
}

void sort_kopcowanie(vector<int>& arr) //heap sort
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        kopiec(arr, n, i); // max kopiec (z wszystkimi wartoœciami, wstêpne sortowanie) sprawdza wszystkich rodziców od najm³odszego prawego 
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);  // Zamieñ korzeñ z ostatnim elementem    
        kopiec(arr, i, 0);     // znowu przeprowadŸ kopcowanie bez ostatniego elementu 
    }

}

void scal(vector<int>& arr, int poczatek, int srodek, int koniec)
{
    int n1 = srodek - poczatek + 1; // Rozmiar pierwszej po³owy
    int n2 = koniec - srodek;    // Rozmiar drugiej po³owy
    // tworzymy tablice pomocnicze
    vector<int> L(n1), R(n2); 
    for (int i = 0; i < n1; i++)    L[i] = arr[poczatek + i];
    for (int j = 0; j < n2; j++)    R[j] = arr[srodek + 1 + j];

    
    int i = 0, j = 0, k = poczatek;

    // Scalanie dwóch posortowanych podtablic
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sort_scalanie(vector<int>& arr, int poczatek, int koniec) // merge sort rekurencyjny
{
    if (poczatek < koniec) 
    {
        int srodek = poczatek + (koniec - poczatek) / 2;

        sort_scalanie(arr, poczatek, srodek);      // Sortowanie lewej po³owy
        sort_scalanie(arr, srodek + 1, koniec); // Sortowanie prawej po³owy
        scal(arr, poczatek, srodek, koniec);   // Scalanie dwóch po³ówek
        
    }
}

void sort_scalanie_iteracyjny(vector<int>& arr) 
{
    int n = arr.size();

    // Stopniowo zwiêkszamy rozmiar podtablicy (1, 2, 4, 8...)
    for (int rozmiar = 1; rozmiar < n; rozmiar *= 2) {
        for (int poczatek = 0; poczatek < n - 1; poczatek += 2 * rozmiar)
        { 
            int srodek = poczatek + rozmiar - 1;
            int koniec = min(poczatek + 2 * rozmiar - 1, n - 1);

            if (srodek < koniec)    scal(arr, poczatek, srodek, koniec);
        }
    }
}



void quicksort(vector<int>& arr, int poczatek, int koniec) //  Quick Sort
{
    if (poczatek < koniec) {
        int pivot = arr[koniec]; // Wybieramy pivot jako ostatni element
        int i = poczatek - 1; // Indeks mniejszego elementu

        for (int j = poczatek; j < koniec; j++) {
            if (arr[j] < pivot) { // Jeœli element jest mniejszy ni¿ pivot
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[koniec]); // Umieszczamy pivot na w³aœciwej pozycji

        int pivot_miejsce = i + 1; // ZnajdŸ pivot

        quicksort(arr, poczatek, pivot_miejsce - 1);  // Sortowanie lewej czêœci
        quicksort(arr, pivot_miejsce + 1, koniec); // Sortowanie prawej czêœci
    }
}