// merge_array
#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std;
using namespace std::chrono;

int* generate_number(int g) {
    int *arr = new int[g];
    for (int j = 0; j < g; j++) {
        arr[j] = rand();
    }
    return arr;
}

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int* left = new int[n1];
    int* right = new int[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

void merge_sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    for (int i = 100000; i <= 500000; i += 20000) {
        int *arr = generate_number(i);

        auto start = high_resolution_clock::now();

        for (int m = 1; m <= 10; m++) {
            merge_sort(arr, 0, i - 1); 
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
       // cout << i << "\t" << duration.count() << endl;
        //cout<<i<<endl;
        cout<<duration.count()<<endl;

        delete[] arr; 
    }

    return 0;
}