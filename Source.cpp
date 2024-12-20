#include "Header.h"

void main() {

    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** arr = 0; // матрица смежности
    int* colors = 0; // массив для цветов
    int i, j, rows;
    FILE* file;
    Node** arr_sp = NULL;
    char name[255];
    int choice, rows1, rows2, what, startVertex;
    printf("Курсовая работа\nПо дисциплине: \"Логика и основы алгоритмизации в инженерных задачах\"\nНа тему: \"Реализация алгоритма Дейкстры\"\n\nВыполнил студент группы 23ВВВ1: Жиганов Никита\nПринял: к.т.н. доцент Юрова О.В.\n\n");
    system("PAUSE");
    system("cls");
    do {
        printf("----------Меню-----------\n");
        printf("1. Создать случайный граф\n");
        printf("2. Ввести граф в ручную\n");
        printf("3. Импортировать граф из файла\n");
        printf("4. Сохранить полученные данные\n");
        printf("5. Выполнить алгоритм Дейкстры\n");
        printf("6. Просмотреть граф\n");
        printf("7. Выход\n");
        printf("Выберите действие: ");
        choice = inputNumber();
        switch (choice) {
        case 1: // Создать случайный граф
            printf("Введите количество вершин графа: ");
            scanf("%s", rows);
            arr = (int**)malloc(rows * sizeof(int*));
            if (arr == NULL) {
                printf("Не удалось выделить память!\n");
                break;;
            }
            for (i = 0; i < rows; i++) {
                arr[i] = (int*)malloc(rows * sizeof(int));
            }
            // генерировать случайные значения для матрицы смежности
            for (i = 0; i < rows; i++) {
                for (j = i; j < rows; j++) {
                    if (i == j) {
                        arr[i][j] = 0; // на главной диагонали нули
                    }
                    else {
                        arr[i][j] = rand() % 100; //(-10) + rand() % 21; // случайные значения 0 или 1
                        arr[j][i] = arr[i][j]; // симметрично заполнять значения для неориентированного графа
                    }
                }
            }
            // выводить матрицу смежности на экран
            printf("Матрица смежности для графа:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-4d ", arr[i][j]);
                }
                printf("\n");
            }
            // Выделение памяти для массива списков смежности
            arr_sp = (Node**)malloc(rows * sizeof(Node*));
            if (arr_sp == NULL) {
                printf("Не удалось выделить память!\n");
                return;
            }
            for (i = 0; i < rows; i++) {
                arr_sp[i] = NULL;
            }
            addSp(arr_sp, arr, rows);
            printSp(arr_sp, rows);
            break;
        case 2: // Ввести граф в ручную
            printf("Введите количество вершин графа: ");
            scanf("%s", rows);
            arr = (int**)malloc(rows * sizeof(int*));
            if (arr == NULL) {
                printf("Не удалось выделить память!\n");
                break;
            }
            for (i = 0; i < rows; i++) {
                arr[i] = (int*)malloc(rows * sizeof(int));
            }
            for (i = 0; i < rows; i++) {
                printf("Введите ребра для вершины: %d\n", i + 1);
                for (j = i; j < rows; j++) {
                    if (i == j) {
                        arr[i][j] = 0;
                    }
                    else {
                        printf("Ребро с вершиной (только положительные числа): %d\n", j + 1);
                        scanf("%s", arr[i][j]);
                        if (arr[i][j] < 0) {
                            printf("Алгоритм Дейкстры работает только с положительными числами!");
                            break;
                        }
                        arr[j][i] = arr[i][j];
                    }
                }
            }
            // выводить матрицу смежности на экран
            printf("Матрица смежности для графа:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-4d ", arr[i][j]);
                }
                printf("\n");
            }
            // Выделение памяти для массива списков смежности
            arr_sp = (Node**)malloc(rows * sizeof(Node*));
            if (arr_sp == NULL) {
                printf("Не удалось выделить память!\n");
                return;
            }
            for (i = 0; i < rows; i++) {
                arr_sp[i] = NULL;
            }
            addSp(arr_sp, arr, rows);
            printSp(arr_sp, rows);
            break;
        case 3: // Импротировать граф из файла
            printf("Введите название файла: ");
            scanf("%s", &name);
            if ((file = fopen(name, "r")) == NULL)
            {
                printf("Не удалось открыть файл");
                getchar();
                break;
            }
            fclose(file);
            file = fopen(name, "r");
            fscanf(file, "%d", &rows);
            arr = (int**)malloc(rows * sizeof(int*));
            if (arr == NULL) {
                printf("Не удалось выделить память!\n");
                break;
            }
            for (i = 0; i < rows; i++) {
                arr[i] = (int*)malloc(rows * sizeof(int));
            }
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    fscanf(file, "%d", &arr[i][j]);
                }
            }
            fclose(file);
            // выводить матрицу смежности на экран
            printf("Матрица смежности для графа:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-4d ", arr[i][j]);
                }
                printf("\n");
            }
            // Выделение памяти для массива списков смежности
            arr_sp = (Node**)malloc(rows * sizeof(Node*));
            if (arr_sp == NULL) {
                printf("Не удалось выделить память!\n");
                return;
            }
            for (i = 0; i < rows; i++) {
                arr_sp[i] = NULL;
            }
            addSp(arr_sp, arr, rows);
            printSp(arr_sp, rows);
            break;
        case 4: // Сохранить полученные данные
            if (arr == NULL) {
                printf("Сначала создайте граф!\n");
                break;
            }
            printf("Введите название файла: ");
            scanf("%s", &name);
            if ((file = fopen(name, "w")) == NULL)
            {
                printf("Не удалось открыть файл");
                getchar();
                break;
            }
            fclose(file);
            file = fopen(name, "w");
            fprintf(file, "%d\n", rows);
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    fprintf(file, "%d\n", arr[i][j]);
                }
            }
            fclose(file);
            break;
        case 5: 
            if (arr == NULL) {
                printf("Сначала создайте граф!\n");
                break;
            }
            // Выполнить алгоритм Дейкстры
            if (arr == NULL) {
                printf("Сначала создайте граф!\n");
                break;
            }
            printf("Введите начальную вершину: ");
            scanf("%d", &startVertex);
            startVertex--;
            if (startVertex < 0 || startVertex >= rows) {
                printf("Некорректный номер вершины!\n");
                break;
            }
            dijkstra(arr, startVertex, rows);
            break;
        case 6: // Просмотреть массив
            if (arr == NULL) {
                printf("Сначала создайте граф!\n");
                break;
            }
            // выводить матрицу смежности на экран
            printf("Матрица смежности для графа:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-4d ", arr[i][j]);
                }
                printf("\n");
            }
            printSp(arr_sp, rows);
            break;
        case 7: // Выход
            system("cls");
            printf("До свидания!\n");
            break;
        default:
            printf("Некорректный выбор!\n");
            break;
        }
    } while (choice != 7);
}