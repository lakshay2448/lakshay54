//djikastra
#include <iostream>
#include <climits>

using namespace std;


void SSSP(int n, int v, int** cost) {

    int dist[n];
    bool s[n];

    for (int i = 0; i < n; i++) {
        dist[i] = cost[v][i];
        s[i] = false;
    }

    s[v] = true;

    for (int j = 2; j < n; j++) {
        int minDist = INT_MAX;
        int u = -1;

    for (int i = 0; i < n; i++) {
            if (!s[i] && dist[i] < minDist) {
                u = i;
                minDist = dist[i];
            }
        }

        s[u] = true;

        for (int i = 0; i < n; i++) {
            if (!s[i] && cost[u][i] != INT_MAX && dist[u] + cost[u][i] < dist[i]) {
                dist[i] = dist[u] + cost[u][i];
            }
        }
    }

    cout << "Shortest distances from source " << v << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int n = 6; 
    int** cost = new int*[n];

    for (int i = 0; i < n; ++i) {
        cost[i] = new int[n];
        
        for (int j = 0; j < n; ++j) {
            cost[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    cost[0][1] = 1;
    cost[0][2] = 4;
    cost[1][2] = 5;
    cost[1][3] = 8;
    cost[2][4] = 3;
    cost[3][5] = 4;
    cost[4][3] = 9;
    cost[4][5] = 5;

    int source = 0;

    SSSP(n, source, cost);

    for (int i = 0; i < n; ++i) {
        delete[] cost[i];
    }
    delete[] cost;

    return 0;
}