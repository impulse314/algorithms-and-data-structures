#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include <time.h>

using namespace std;

/*-----------------------
   Пузырьковая сортировка
------------------------*/
void bubbleSort(int list[], int listLength)
{
    while (listLength--)
    {
        bool swapped = false;

        for (int i = 0; i < listLength; i++)
        {
            if (list[i] > list[i + 1])
            {
                list[i] ^= list[i + 1] ^= list[i] ^= list[i + 1]; //меняем значения местами
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

/*--------------------
  Сортировка выбором
---------------------*/
int findSmallestPosition(int list[], int startPosition, int listLength)
{
    int smallestPosition = startPosition;

    for (int i = startPosition; i < listLength; i++)
    {
        if (list[i] < list[smallestPosition])
            smallestPosition = i;
    }
    return smallestPosition;
} //метод поиска наименьшего элемента

void selectionSort(int list[], int listLength)
{
    for (int i = 0; i < listLength; i++)
    {
        int smallestPosition = findSmallestPosition(list, i, listLength);
        list[i] ^= list[smallestPosition] ^= list[i] ^= list[smallestPosition];
    }
    return;
}

/*-------------------- 
  Сортировка вставками
---------------------*/

void insertionSort(int list[], int listLength)
{
    for (int i = 1; i < listLength; i++)
    {
        int j = i - 1;
        while (j >= 0 && list[j] > list[j + 1])
        {
            list[j] ^= list[j + 1] ^= list[j] ^= list[j + 1];
            j--;
        }
    }
}

/*----------------------
  Сортировка подсчетом
----------------------*/

void countSort(int list[], int listLength) {
    // The size of count must be at least the (max+1) but
    // we cannot assign declare it as int count(max+1) in C++ as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int output[10];
    int count[10];
    int max = list[0];

    // Find the largest element of the array
    for (int i = 1; i < listLength; i++) {
        if (list[i] > max)
            max = list[i];
    }

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < listLength; i++) {
        count[list[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = listLength - 1; i >= 0; i--) {
        output[count[list[i]] - 1] = list[i];
        count[list[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < listLength; i++) {
        list[i] = output[i];
    }
}

/*-------------------
  Сортировка слиянием
--------------------*/

void merge(int list[], int start, int end, int mid)
{
    int mergedList[100000];
    int i, j, k;
    i = start;
    k = start;
    j = mid + 1;

    while (i <= mid && j <= end) {
        if (list[i] < list[j]) {
            mergedList[k] = list[i];
            k++;
            i++;
        }
        else {
            mergedList[k] = list[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        mergedList[k] = list[i];
        k++;
        i++;
    }

    while (j <= end) {
        mergedList[k] = list[j];
        k++;
        j++;
    }

    for (i = start; i < k; i++) {
        list[i] = mergedList[i];
    }
}
void mergeSort(int list[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        mergeSort(list, start, mid);
        mergeSort(list, mid + 1, end);
        merge(list, start, end, mid);
    }
}

/*------------------
  Быстрая сортировка
-------------------*/

int partition(int list[], int start, int pivot)
{
    int i = start;
    while (i < pivot)
    {
        if (list[i] > list[pivot] && i == pivot - 1)
        {
            list[i] ^= list[pivot] ^= list[i] ^= list[pivot];
            pivot--;
        }

        else if (list[i] > list[pivot])
        {
            list[pivot - 1] ^= list[pivot] ^= list[pivot - 1] ^= list[pivot];
            list[i] ^= list[pivot] ^= list[i] ^= list[pivot];
            pivot--;
        }

        else i++;
    }
    return pivot;
}
void quickSort(int list[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(list, start, end);

        quickSort(list, start, pivot - 1);
        quickSort(list, pivot + 1, end);
    }
}

/*---------------------
  Точка входа программы
----------------------*/

int main()
{
    int data[100000];
    int size = sizeof(data) / sizeof(*data);
    setlocale(LC_ALL, "Russian");
    FILE* in = nullptr, * out = nullptr;
    freopen_s(&in, "input.txt", "r", stdin);
    freopen_s(&out, "output.txt", "w", stdout);
    ios::sync_with_stdio(false);

    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }

    clock_t start = clock();
    
    //bubbleSort(data, size);
    
    //selectionSort(data, size);
    
    //insertionSort(data, size);
    
    //quickSort(data, 0, size - 1);
    
    //mergeSort(data, 0, size-1);
    
    //int test[10] = { 2, 3, 6, 8, 9, 1, 4, 7, 5, 10 };
    //countSort(test, 10);

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Время исполнения алгоритма составило: " << seconds << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    return 0;
}
