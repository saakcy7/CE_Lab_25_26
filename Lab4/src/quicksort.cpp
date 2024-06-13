#include <iostream>
#include <ctime>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high ;
    while (i < j)
    {
        while (arr[j] > pivot)
            j--;
        while (arr[i] < pivot)
            i++;
        swap(&arr[i], &arr[j]);
    }

    // swap(&arr[low], &arr[j]); // No need to swap with pivot, as pivot is already at low
    return j;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main() {

    srand(time(NULL));

    int r, n = 10;
    
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        r = rand();
        arr[i] = r;
    }

    clock_t start = (int)clock();

    cout<<"Before sorting: \n";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);
    
    cout << "\nSorted array: \n";
    printArray(arr, n);

    printf("%0.5fms", (clock() - start) * 10.0 / CLOCKS_PER_SEC);
    
    return 0;
}