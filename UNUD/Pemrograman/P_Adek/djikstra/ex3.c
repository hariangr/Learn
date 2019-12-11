// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// A utility function to print the constructed distance array
int printSolution(int dist[], int prev[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t\t %d \t\t from %d\n", i, dist[i], prev[i]);
    }
}

void printShortestPath(int dist[], int prev[], int goal)
{
    int _from = goal;
    int _road[V];
    int __x = 0;

    while (true)
    {
        printf("%d <- ", _from);
        _road[__x] = _from;
        _from = prev[_from];

        if (_from == -1)
        {
            return;
        }

        __x++;
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int prev[V];

    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    prev[src] = -1;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v])
            {
                if (graph[u][v])
                {
                    if (dist[u] != INT_MAX)
                    {
                        if (dist[u] + graph[u][v] < dist[v])
                        {
                            dist[v] = dist[u] + graph[u][v];
                            prev[v] = u;
                        }
                    }
                }
            }
        }
    }

    // print the constructed distance array
    printSolution(dist, prev);
    printShortestPath(dist, prev, 4);
}

// driver program to test above function
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}