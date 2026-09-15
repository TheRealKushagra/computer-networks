#include <iostream>
using namespace std;

#define MAX 20
#define INF 999

int main()
{
    int n;
    int cost[MAX][MAX];
    int dist[MAX][MAX];
    int nextHop[MAX][MAX];

    cout << "Enter number of routers: ";
    cin >> n;

    // Input cost matrix
    cout << "Enter the cost matrix:" << endl;
    cout << "Enter 999 for no direct connection." << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    // Initialize distance and next hop
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = cost[i][j];

            if (i == j)
            {
                nextHop[i][j] = i;
            }
            else if (cost[i][j] != INF)
            {
                nextHop[i][j] = j;
            }
            else
            {
                nextHop[i][j] = -1;
            }
        }
    }

    // Distance Vector Routing
    bool updated;

    do
    {
        updated = false;

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] != INF &&
                        dist[k][j] != INF &&
                        dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];

                        // First router to take from router i
                        nextHop[i][j] = nextHop[i][k];

                        updated = true;
                    }
                }
            }
        }

    } while (updated);

    // Display final routing tables
    cout << "\nFINAL ROUTING TABLES\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nRouter " << i + 1 << endl;
        cout << "Destination\tCost\tNext Hop" << endl;

        for (int j = 0; j < n; j++)
        {
            cout << j + 1 << "\t\t";

            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";

            if (nextHop[i][j] == -1)
                cout << "-";
            else
                cout << nextHop[i][j] + 1;

            cout << endl;
        }
    }

    return 0;
}