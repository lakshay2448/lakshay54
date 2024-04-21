#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std;
using namespace std::chrono;

void coins(int arr[], int k, int n)
{
    if(k == n + 1)
    {
        return;
    }

    arr[k] = 1;
    coins(arr, k + 1, n);

    arr[k] = 0;
    coins(arr, k + 1, n);
}

int main()
{
    for (int i = 10; i <= 25; i += 3)
    {
        int *arr = new int[i]; // Dynamic array for each iteration

        auto start = high_resolution_clock::now(); // Time count

        for (int m = 1; m <= 10; m++)
        {
            coins(arr, 0, i); 
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
        cout << "Inputs: " << i << "\tTime taken: " << duration.count() << " nanoseconds.." << endl;
        // cout<<i<<endl;
        //cout<<duration.count()<<endl;

        delete[] arr;
    }

    return 0;
}