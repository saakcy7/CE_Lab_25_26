#include<iostream>
#include<cstdlib>
#include <ctime>
#include <chrono>
#include"sorting.h"
using namespace std;

int length=1000
const int max_length=500000;
void insertionSort(int list[],int ArraySize)
{
    int i,j,key;
    for(i=1;i<ArraySize;i++)
    {
        key = list[i];
        j = i - 1;

        while (j >= 0 && list[j] > key)
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}
int partition(int *list, int low, int high)
{
    int pivot = list[high];
    int i = low;
    for (int j = low; j <= high; j++)
    {
        if (list[j] < pivot)
        {
            swapPlace(list, i, j);
            i++;
        }
    }
    swapPlace(list, high, i);
    return i;
}




