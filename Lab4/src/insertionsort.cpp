#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertionSort(int a[], int n)
{
     int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main()
{   
    srand(time(NULL));

    int r, n = 10;
    
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        r = rand() % 10;
        a[i] = r;
    }
    clock_t start = (int)clock();

    cout << "BEFORE" << endl;
    display(a, n);

    insertionSort(a, n);
    
    cout << "AFTER" << endl;
    display(a, n);
    
    printf("%0.5fms", (clock() - start) * 10.0 / CLOCKS_PER_SEC);
}