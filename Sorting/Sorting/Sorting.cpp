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


void countingSort(int list[], int listLength)
{
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < listLength; i++) {
        if (list[i] > max)
            max = list[i];
        if (list[i] < min)
            min = list[i];
    }
    int* c = new int[max + 1 - min];
    for (int i = 0; i < max + 1 - min; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < listLength; i++) {
        c[list[i] - min] = c[list[i] - min] + 1;
    }
    int i = 0;
    for (int j = min; j < max + 1; j++) {
        while (c[j - min] != 0) {
            list[i] = j;
            c[j - min]--;
            i++;
        }
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
    //freopen_s(&in, "input.txt", "r", stdin);
    freopen_s(&out, "output.txt", "w", stdout);
    ios::sync_with_stdio(false);

    for (int j = 0; j < 1; j++)
    {
        int run = rand() % 5;
        for (int i = 0; i < 100000; i++)
        {
            data[i] = rand() % 100;
        }
    }
        

    clock_t start = clock();

    //bubbleSort(data, size);

    //selectionSort(data, size);

    //insertionSort(data, size);

    //quickSort(data, 0, size - 1);

    //mergeSort(data, 0, size-1);

    countingSort(data, size);

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    //cout << size << endl;
    cout << "Время исполнения алгоритма составило: " << seconds << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    return 0;
}
