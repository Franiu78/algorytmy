#include "test.h"
#include "sorting.h"
#include "generate.h"
#include <iostream>
#include <chrono> // do mierzenia czasu
#include <iomanip>

using namespace std;

void pom_heap(vector<int>& arr)
{
    vector<int> bad;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        bad = arr;
        sort_kopcowanie(bad);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout  << duration.count() << " ms";
}
void test_heap(vector<int>& arr)
{
    vector<int> bad;
    bad = arr;
    cout << endl <<"heap sort wyniki" << endl;
    cout << "      caly:   " << setprecision(3);
    pom_heap(bad);
    vector<double> poziomy = { 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, 1 };
    for (double p : poziomy)
    {
        cout << endl << fixed << setprecision(3) << setw(10) << p << ":   ";
        sort_proc(bad, p);
        pom_heap(bad);
    }


    cout << endl << "    odwrot:   " << setprecision(3) ;
    sort_odwrot(bad);
    pom_heap(bad);
}

void pom_merge(vector<int>& arr)
{
    vector<int> bad;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        bad = arr;
        sort_scalanie(bad, 0, bad.size() - 1);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << duration.count() << " ms";
}

void test_merge(vector<int>& arr)
{
    vector<int> bad = arr;
    cout << endl << "merge sort (rekurencyjny) wyniki" << endl;
    cout << "      caly:   ";
    pom_merge(bad);
    vector<double> poziomy = { 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, 1.0 };
    for (double p : poziomy)
    {
        cout << endl << fixed << setprecision(3) << setw(10) << p << ":   ";
        sort_proc(bad, p);
        pom_merge(bad);
    }
    cout << endl << "    odwrot:   ";
    sort_odwrot(bad);
    pom_merge(bad);
}


void pom_merge_iter(vector<int>& arr)
{
    vector<int> bad;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        bad = arr;
        sort_scalanie_iteracyjny(bad);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << duration.count() << " ms";
}

void test_merge_iter(vector<int>& arr)
{
    vector<int> bad = arr;
    cout << endl << "merge sort (iteracyjny) wyniki" << endl;
    cout << "      caly:   ";
    pom_merge_iter(bad);
    vector<double> poziomy = { 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, 1.0 };
    for (double p : poziomy)
    {
        cout << endl << fixed << setprecision(3) << setw(10) << p << ":   ";
        sort_proc(bad, p);
        pom_merge_iter(bad);
    }
    cout << endl << "    odwrot:   ";
    sort_odwrot(bad);
    pom_merge_iter(bad);
}


void pom_quick(vector<int>& arr)
{
    vector<int> bad;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        bad = arr;
        quicksort(bad, 0, bad.size() - 1);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << duration.count() << " ms";
}

void test_quick(vector<int>& arr)
{
    vector<int> bad = arr;
    cout << endl << "quick sort wyniki" << endl;
    cout << "      caly:   ";
    pom_quick(bad);
    vector<double> poziomy = { 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, 1.0 };
    for (double p : poziomy)
    {
        cout << endl << fixed << setprecision(3) << setw(10) << p << ":   ";
        sort_proc(bad, p);
        pom_quick(bad);
    }
    cout << endl << "    odwrot:   ";
    sort_odwrot(bad);
    pom_quick(bad);
}
