//m-coloring 
#include <iostream>
#include <cstring>
using namespace std;

bool isSafe(int v, bool graph[10][10], int color[], int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphcoloringUtil(bool graph[10][10], int m, int color[], int v, int n) {
    if (v == n) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;

            if (graphcoloringUtil(graph, m, color, v + 1, n)) {
                return true;
            }

            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[10][10], int n) {
    int color[n];
    memset(color, 0, sizeof(color)); 

    int m = 1; 
    while (true) {
        if (graphcoloringUtil(graph, m, color, 0, n)) {
            cout << "Solution with " << m << " colors: ";
            for (int i = 0; i < n; i++) {
                cout << color[i] << " ";
            }
            cout << endl;
            return true;
        }
        m++;
    }
    return false;
}
int main() {
    bool graph[10][10] = {
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
    };
    int n = 10; 

    if (!graphColoring(graph, n)) {
        cout << "No solution exists." << endl;
    }
    return 0;
}