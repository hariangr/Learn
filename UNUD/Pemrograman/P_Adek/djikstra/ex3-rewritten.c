// Implementasi asal
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
// Diubah [Hari Anugrah]

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define JUMLAH_NODE 9

int indexNodeTerdekat(int dist[], bool tabelNodeTerkunjungi[])
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < JUMLAH_NODE; v++)
        if (tabelNodeTerkunjungi[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

void printTabelDijkstra(int dist[], int prev[])
{
    printf("Node \t\t Jarak \t\t Dicapai melalui node\n");
    for (int i = 0; i < JUMLAH_NODE; i++)
    {
        printf("%d \t\t %d \t\t %d\n", i, dist[i], prev[i]);
    }
}

void printRuteTerpendek(int dist[], int prev[], int asal, int goal)
{
    int _from = goal;
    int _road[JUMLAH_NODE];
    int _counter = 0;

    while (true)
    {
        _road[_counter] = _from;
        _from = prev[_from];

        if (_from == -1)
        {
            break;
        }

        _counter++;
    }

    printf("Rute tercepat dari node %d ke %d adalah\n\t", asal, goal);
    for (int i = _counter; i >= 0; i--)
    {
        printf("%d", _road[i]);

        if (i != 0)
        {
            printf(" --> ");
        }
        else if (i == 0)
        {
            printf("\n");
        }
    }
}

void dijkstra(int graph[JUMLAH_NODE][JUMLAH_NODE], int asal, int *tabelJarak, int *tabelNodeSebelumnya)
{
    bool nodeSudahDikunjungi[JUMLAH_NODE];

    for (int i = 0; i < JUMLAH_NODE; i++)
    {
        tabelJarak[i] = INT_MAX;
        nodeSudahDikunjungi[i] = false;
    }

    tabelJarak[asal] = 0;
    tabelNodeSebelumnya[asal] = -1;

    for (int count = 0; count < JUMLAH_NODE - 1; count++)
    {
        int u = indexNodeTerdekat(tabelJarak, nodeSudahDikunjungi);

        nodeSudahDikunjungi[u] = true;

        for (int v = 0; v < JUMLAH_NODE; v++)
        {
            if (!nodeSudahDikunjungi[v])
            {
                if (graph[u][v])
                {
                    if (tabelJarak[u] != INT_MAX)
                    {
                        if (tabelJarak[u] + graph[u][v] < tabelJarak[v])
                        {
                            tabelJarak[v] = tabelJarak[u] + graph[u][v];
                            tabelNodeSebelumnya[v] = u;
                        }
                    }
                }
            }
        }
    }
}

void cariJalanTercepat(int graph[JUMLAH_NODE][JUMLAH_NODE], int asal, int tujuan)
{
    int _tabelJarak[JUMLAH_NODE];
    int _tabelNodeSebelumnya[JUMLAH_NODE];

    dijkstra(graph, asal, &_tabelJarak[0], &_tabelNodeSebelumnya[0]);

    printTabelDijkstra(_tabelJarak, _tabelNodeSebelumnya);
    printf("\n");
    printRuteTerpendek(_tabelJarak, _tabelNodeSebelumnya, asal, tujuan);
}

int main()
{
    int graph[JUMLAH_NODE][JUMLAH_NODE] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                           {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                           {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                           {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                           {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                           {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                           {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                           {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                           {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    int _nodeAsal;
    int _noedTujuan;

    printf("Masukkan node asal? ");
    scanf("%d", &_nodeAsal);
    printf("Masukkan node tujuan? ");
    scanf("%d", &_noedTujuan);

    cariJalanTercepat(graph, _nodeAsal, _noedTujuan);

    return 0;
}