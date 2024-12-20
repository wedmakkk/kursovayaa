#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

typedef struct Node {
    int inf;
    struct Node* next;
}Node;

int inputNumber();
void colorGraph(int** arr, int rows, int* colors);
void addSp(Node** arr_sp, int** arr, int rows);
void printSp(Node** arr_sp, int rows);
void dijkstra(int** graph, int src, int rows);