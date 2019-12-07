#include <stdio.h>

int arr[4][4] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 0, 0}};

int degreePerNode(int index)
{
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        sum += arr[index][i];
    }

    return sum;
}

int totalDegree()
{
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        sum += degreePerNode(i);
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
    {
        /* code */
        printf("Degree at node %d is %d\n", i + 1, degreePerNode(i));
    }

    printf("Total degree of the graph is %d\n", totalDegree());
    return 0;
}
