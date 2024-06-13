#include<iostream>
#include<random>
#include<vector>
#include<ctime>
#include<chrono>
#include<cstdlib>
#include "sorting.h"
using namespace std;
int main()
{
    
    srand(time(NULL));
    int r, n = 10;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        r = rand() % 10;
        a[i] = r;
    }
    clock_t start = (int)clock();
    cout << "BEFORE" << endl;
    insertionSort(&a[0], n);
    cout << "AFTER" << endl;
    printf("%0.5fms", (clock() - start) * 10.0 / CLOCKS_PER_SEC);
    return 0;
    

}