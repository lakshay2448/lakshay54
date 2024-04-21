#include<iostream>
#include<algorithm>
#include <bits/stdc++.h> 
using namespace std;

int carAssembly(int a[][4], int t[][4], int *e, int *x, vector<vector<int>>& path) {
    int i;

    int first = e[0] + a[0][0];
    int second = e[1] + a[1][0];

    for (i = 1; i < 4; ++i) {
        int up = min(first + a[0][i], second + t[1][i] + a[0][i]);
        int down = min(second + a[1][i], first + t[0][i] + a[1][i]);

        if (up <= down) {
            path[0][i] = 1;  // Assembly line 1
            first = up;
        } else {
            path[0][i] = 2;  // Assembly line 2
            first = down;
        }

        if (down <= up) {
            path[1][i] = 2;  // Assembly line 2
            second = down;
        } else {
            path[1][i] = 1;  // Assembly line 1
            second = up;
        }
    }

    // Determine the exit path
    if (first + x[0] <= second + x[1]) {
        path[2][3] = 1;  // Exit from assembly line 1
    } else {
        path[2][3] = 2;  // Exit from assembly line 2
    }

    return min(first + x[0], second + x[1]);
}

void printPath(const vector<vector<int>>& path) {
    cout << "Path: ";
    int currentLine = path[2][3];
    for (int i = 3; i >= 1; --i) {
        cout << "Assembly Line " << path[currentLine - 1][i] << " -> ";
        currentLine = path[currentLine - 1][i];
    }
    cout << "Start\n";
}

int main() {
    int a[][4] = { {4, 5, 3, 2},
                   {2, 10, 1, 4} };

    int t[][4] = { {0, 7, 4, 5},
                   {0, 9, 2, 8} };

    int e[] = {10, 12}, x[] = {18, 7};

    vector<vector<int>> path(3, vector<int>(4, 0));

    int minTime = carAssembly(a, t, e, x, path);

    cout << "Minimum Time: " << minTime << endl;
    printPath(path);

    return 0;
}