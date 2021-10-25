#include <bits/stdc++.h>
using namespace std;
//quicksort

int Q_merge(int a[], int l, int h)
{
    int pivot = a[h];
    int i = l;
    for (int j = l; j < h; j++)
    {
        if (a[j] <= pivot)
        {

            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[h]);
    return i;
}
void quicksort(int a[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pi = Q_merge(a, low, high);
    quicksort(a, low, pi - 1);
    quicksort(a, pi + 1, high);
}

//mergesort
void M_merge(int *a, int low, int high, int mid)
{
    int temp[high - low + 1], i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= high)
    {
        temp[k++] = a[j++];
    }
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}
void mergesort(int a[], int low, int high)
{

    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    M_merge(a, low, high, mid);
}
void bubblesort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void insertionsort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = a[i];
        int j = i - 1;
        while (a[j] > curr && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = curr;
    }
}
int main()
{
    int n, i;

    n = 6;
    int arr[] = {9, 6, 7, 10, 30, 5};

    quicksort(arr, 0, n - 1);

    cout << "\nSorted Data ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    int ar[] = {9, 6, 7, 10, 30, 5};
    mergesort(ar, 0, n - 1);

    cout << "\nSorted Data ";
    for (i = 0; i < n; i++)
        cout << ar[i] << " ";

    int a[] = {9, 6, 7, 10, 30, 5};
    bubblesort(a, n);

    cout << "\nSorted Data ";
    for (i = 0; i < n; i++)
        cout << ar[i] << " ";
    int aa[] = {9, 6, 7, 10, 30, 5};
    insertionsort(aa, n);

    cout << "\nSorted Data ";
    for (i = 0; i < n; i++)
        cout << aa[i] << " ";

    return 0;
}