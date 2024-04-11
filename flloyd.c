#include <stdio.h>
#define nV 4
#define INF 999

void printMatrix(int matrix[][nV]);

void floydWarshall(int graph[][nV]) {
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++) {
        for (j = 0; j < nV; j++) {
            matrix[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < nV; k++) {
        for (i = 0; i < nV; i++) {
            for (j = 0; j < nV; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            if (matrix[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[nV][nV];
    printf("Enter the elements of the %dx%d matrix (Enter INF for infinity):\n", nV, nV);
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == INF) {
                // If the input is INF, replace it with a large value
                graph[i][j] = INF;
            }
        }
    }
    floydWarshall(graph);
    return 0;
}
