#include "Header.h"

void addSp(Node** arr_sp, int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (arr[i][j] != 0) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->inf = j + 1;
                newNode->next = arr_sp[i];
                arr_sp[i] = newNode;
            }
        }
    }
}

void printSp(Node** arr_sp, int rows) {
    for (int i = 0; i < rows; i++) {
        Node* current = arr_sp[i];
        if (current == NULL) {

        }
        else {
            printf("Вершина %d смежна с: ", i + 1);
            while (current != NULL) {
                printf("%d ", current->inf);
                current = current->next;
            }
            printf("\n");
        }
    }
}


int minDistance(int* dist, bool* visited, int rows) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < rows; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

void dijkstra(int** graph, int src, int rows) {
    int* dist = (int*)malloc(rows * sizeof(int)); // Массив для хранения кратчайших расстояний до вершин
    bool* visited = (bool*)malloc(rows * sizeof(bool)); // Массив для отслеживания посещенных вершин

    for (int i = 0; i < rows; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0; // Расстояние до начальной вершины равно 0

    for (int count = 0; count < rows - 1; count++) {
        int u = minDistance(dist, visited, rows); // Находим вершину с минимальным расстоянием
        visited[u] = true;

        for (int v = 0; v < rows; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Кратчайшие расстояния от вершины %d:\n", src + 1);
    for (int i = 0; i < rows; i++)
        printf("Вершина %d -> Расстояние %d\n", i + 1, dist[i]);

    free(dist);
    free(visited);
}