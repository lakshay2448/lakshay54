#include<iostream>
#include<chrono>
#include<cstdlib>
#include<algorithm>
using namespace std;
using namespace std::chrono;

void permute(string str, int k, int n)
{
    if (k == n)
    {
        return;
    }

    for (int i = k; i <= n; i++)
    {
        swap(str[k], str[i]);
        permute(str, k + 1, n);
        swap(str[k], str[i]);  
    }
}

int main()
{
    for (int i = 3; i <= 12; i += 2)
    {
        string str;
        for (int j = 0; j < i; j++)
        {
            str += static_cast<char>('a' + j);
        }

        auto start = high_resolution_clock::now(); // Time count

        for (int m = 1; m <= 10; m++)
        {
            permute(str, 0, i - 1);
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
        cout << "Inputs: " << i << "\tTime taken: " << duration.count() << " nanoseconds.." << endl;
      //  cout<<i<<endl;
       // cout<<duration.count()<<endl;
    }

    return 0;
}