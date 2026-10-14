/*
Practical No. 19
Title: Implement Graph Using Matrix Representation

Exercise:
1. Write a program to display a graph using a matrix.
*/

#include <stdio.h>

#define MAX 20

int main(void)
{
    int graph[MAX][MAX];
    int vertices, edges;
    int i, j, source, destination;

    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &vertices) != 1 || vertices < 1 || vertices > MAX)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    /* Initialize adjacency matrix to zero */
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
            graph[i][j] = 0;
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &edges) != 1 || edges < 0 || edges > vertices * (vertices - 1) / 2)
    {
        printf("Invalid number of edges for an undirected simple graph.\n");
        return 1;
    }

    /* Enter edges for an undirected graph */
    for (i = 0; i < edges; i++)
    {
        printf("Enter edge %d (source destination, vertices numbered 1 to %d): ", i + 1, vertices);
        if (scanf("%d %d", &source, &destination) != 2 ||
            source < 1 || source > vertices ||
            destination < 1 || destination > vertices ||
            source == destination)
        {
            printf("Invalid edge. Please enter two different valid vertices.\n");
            return 1;
        }

        graph[source - 1][destination - 1] = 1;
        graph[destination - 1][source - 1] = 1;
    }

    printf("\nAdjacency Matrix of the Graph:\n   ");
    for (i = 1; i <= vertices; i++)
        printf("%d ", i);

    printf("\n");

    for (i = 0; i < vertices; i++)
    {
        printf("%d: ", i + 1);
        for (j = 0; j < vertices; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    return 0;
}

/*
Sample Output:
Enter number of vertices (1-20): 4
Enter number of edges: 4
Enter edge 1 (source destination, vertices numbered 1 to 4): 1 2
Enter edge 2 (source destination, vertices numbered 1 to 4): 1 3
Enter edge 3 (source destination, vertices numbered 1 to 4): 2 4
Enter edge 4 (source destination, vertices numbered 1 to 4): 3 4

Adjacency Matrix of the Graph:
   1 2 3 4
1: 0 1 1 0
2: 1 0 0 1
3: 1 0 0 1
4: 0 1 1 0

Note:
This program represents an undirected, unweighted graph. A value of 1 means
an edge exists between two vertices; 0 means no edge exists.
Time Complexity: O(V^2) to initialize and display the matrix.
Space Complexity: O(V^2).
*/
