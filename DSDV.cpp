#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

const int INF = 9999;

void displayMatrix(const vector<vector<int>>& matrix, int n) {
    cout << "\n";
    cout << setw(8) << " ";

    for (int i = 0; i < n; i++)
        cout << setw(8) << i;

    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << setw(8) << i;

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INF)
                cout << setw(8) << "INF";
            else
                cout << setw(8) << matrix[i][j];
        }

        cout << "\n";
    }
}

void displayRoutingTables(
    const vector<vector<int>>& distance,
    const vector<vector<int>>& nextHop,
    int n
) {
    for (int source = 0; source < n; source++) {
        cout << "\nRouting Table for Router " << source << "\n";

        cout << setw(15) << "Destination"
             << setw(15) << "Cost"
             << setw(15) << "Next Hop" << "\n";

        cout << string(45, '-') << "\n";

        for (int destination = 0; destination < n; destination++) {
            cout << setw(15) << destination;

            if (distance[source][destination] == INF)
                cout << setw(15) << "INF";
            else
                cout << setw(15) << distance[source][destination];

            if (nextHop[source][destination] == -1)
                cout << setw(15) << "-";
            else
                cout << setw(15) << nextHop[source][destination];

            cout << "\n";
        }
    }
}

int main() {
    int n;

    cout << "==============================================\n";
    cout << " DISTANCE VECTOR ROUTING ALGORITHM\n";
    cout << "==============================================\n";

    cout << "\nEnter number of routers: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> distance(n, vector<int>(n));
    vector<vector<int>> nextHop(n, vector<int>(n));

    cout << "\nEnter the network cost matrix:\n";

    cout << "Enter " << INF
         << " if two routers are not directly connected.\n";

    cout << "Enter 0 for the same router.\n\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Cost[" << i << "][" << j << "]: ";
            cin >> cost[i][j];

            distance[i][j] = cost[i][j];

            if (i == j) {
                distance[i][j] = 0;
                nextHop[i][j] = i;
            }
            else if (cost[i][j] != INF) {
                nextHop[i][j] = j;
            }
            else {
                nextHop[i][j] = -1;
            }
        }
    }

    cout << "\n==============================================\n";
    cout << " INITIAL COST MATRIX\n";
    cout << "==============================================\n";

    displayMatrix(cost, n);

    cout << "\n==============================================\n";
    cout << " INITIAL ROUTING TABLES\n";
    cout << "==============================================\n";

    displayRoutingTables(distance, nextHop, n);

    bool updated;

    do {
        updated = false;

        for (int source = 0; source < n; source++) {
            for (int destination = 0; destination < n; destination++) {
                for (int neighbour = 0; neighbour < n; neighbour++) {

                    if (cost[source][neighbour] != INF &&
                        distance[neighbour][destination] != INF) {

                        int newCost =
                            cost[source][neighbour] +
                            distance[neighbour][destination];

                        if (newCost < distance[source][destination]) {
                            distance[source][destination] = newCost;
                            nextHop[source][destination] = neighbour;
                            updated = true;
                        }
                    }
                }
            }
        }

    } while (updated);

    cout << "\n==============================================\n";
    cout << " FINAL ROUTING TABLES\n";
    cout << "==============================================\n";

    displayRoutingTables(distance, nextHop, n);

    int selectedSource, selectedDestination;

    cout << "\nEnter source router: ";
    cin >> selectedSource;

    cout << "Enter destination router: ";
    cin >> selectedDestination;

    if (distance[selectedSource][selectedDestination] == INF) {
        cout << "\nNo path exists between the selected routers.\n";
    }
    else {
        cout << "\n==============================================\n";
        cout << " SHORTEST PATH\n";
        cout << "==============================================\n";

        cout << "Minimum Cost: "
             << distance[selectedSource][selectedDestination]
             << "\n";

        cout << "Shortest Path: ";

        int current = selectedSource;

        cout << current;

        while (current != selectedDestination) {
            current = nextHop[current][selectedDestination];

            if (current == -1) {
                cout << "\nPath cannot be determined.\n";
                return 0;
            }

            cout << " -> " << current;
        }

        cout << "\n";
    }

    cout << "\n==============================================\n";
    cout << " PROGRAM END\n";
    cout << "==============================================\n";

    return 0;
}