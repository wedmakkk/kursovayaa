#include "Header.h"

void main() {

    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** arr = 0; // ������� ���������
    int* colors = 0; // ������ ��� ������
    int i, j, rows;
    FILE* file;
    Node** arr_sp = NULL;
    char name[255];
    int choice, rows1, rows2, what, startVertex;
    printf("�������� ������\n�� ����������: \"������ � ������ �������������� � ���������� �������\"\n�� ����: \"���������� ��������� ��������\"\n\n�������� ������� ������ 23���1: ������� ������\n������: �.�.�. ������ ����� �.�.\n\n");
    system("PAUSE");
    system("cls");
    do {
        printf("----------����-----------\n");
        printf("1. ������� ��������� ����\n");
        printf("2. ������ ���� � ������\n");
        printf("3. ������������� ���� �� �����\n");
        printf("4. ��������� ���������� ������\n");
        printf("5. ��������� �������� ��������\n");
        printf("6. ����������� ����\n");
        printf("7. �����\n");
        printf("�������� ��������: ");
        choice = inputNumber();
        switch (choice) {
        case 1: // ������� ��������� ����
            printf("������� ���������� ������ �����: ");
            scanf("%s", rows);
            arr = (int**)malloc(rows * sizeof(int*));
            if (arr == NULL) {
                printf("�� ������� �������� ������!\n");
                break;;
            }
            for (i = 0; i < rows; i++) {
                arr[i] = (int*)malloc(rows * sizeof(int));
            }
            // ������������ ��������� �������� ��� ������� ���������
            for (i = 0; i < rows; i++) {
                for (j = i; j < rows; j++) {
                    if (i == j) {
                        arr[i][j] = 0; // �� ������� ��������� ����
                    }
                    else {
                        arr[i][j] = rand() % 100; //(-10) + rand() % 21; // ��������� �������� 0 ��� 1
                        arr[j][i] = arr[i][j]; // ����������� ��������� �������� ��� ������������������ �����
                    }
                }
            }
            // �������� ������� ��������� �� �����
            printf("������� ��������� ��� �����:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-4d ", arr[i][j]);
                }
                printf("\n");
            }
            // ��������� ������ ��� ������� ������� ���������
            arr_sp = (Node**)malloc(rows * sizeof(Node*));
            if (arr_sp == NULL) {
                printf("�� ������� �������� ������!\n");
                return;
            }
            for (i = 0; i < rows; i++) {
                arr_sp[i] = NULL;
            }
            addSp(arr_sp, arr, rows);
            printSp(arr_sp, rows);
            break;
        case 2: // ������ ���� � ������
            printf("������� ���������� ������ �����: ");
            scanf("%s", rows);
            arr = (int**)malloc(rows * sizeof(int*));
            if (arr == NULL) {
                printf("�� ������� �������� ������!\n");
                break;
            }
            for (i = 0; i < rows; i++) {
                arr[i] = (int*)malloc(rows * sizeof(int));
            }
            for (i = 0; i < rows; i++) {
                printf("������� ����� ��� �������: %d\n", i + 1);
                for (j = i; j < rows; j++) {
                    if (i == j) {
                        arr[i][j] = 0;
                    }
                    else {
                        printf("����� � �������� (������ ������������� �����): %d\n", j + 1);
                        scanf("%s", arr[i][j]);
                        if (arr[i][j] < 0) {
                            printf("�������� �������� �������� ������ � �������������� �������!");
                            break;
                        }
                        arr[j][i] = arr[i][j];
                    }
                }
            }
            // �������� ������� ��������� �� �����
            printf("������� ��������� ��� �����:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-4d ", arr[i][j]);
                }
                printf("\n");
            }
            // ��������� ������ ��� ������� ������� ���������
            arr_sp = (Node**)malloc(rows * sizeof(Node*));
            if (arr_sp == NULL) {
                printf("�� ������� �������� ������!\n");
                return;
            }
            for (i = 0; i < rows; i++) {
                arr_sp[i] = NULL;
            }
            addSp(arr_sp, arr, rows);
            printSp(arr_sp, rows);
            break;
        case 3: // ������������� ���� �� �����
            printf("������� �������� �����: ");
            scanf("%s", &name);
            if ((file = fopen(name, "r")) == NULL)
            {
                printf("�� ������� ������� ����");
                getchar();
                break;
            }
            fclose(file);
            file = fopen(name, "r");
            fscanf(file, "%d", &rows);
            arr = (int**)malloc(rows * sizeof(int*));
            if (arr == NULL) {
                printf("�� ������� �������� ������!\n");
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
            // �������� ������� ��������� �� �����
            printf("������� ��������� ��� �����:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-4d ", arr[i][j]);
                }
                printf("\n");
            }
            // ��������� ������ ��� ������� ������� ���������
            arr_sp = (Node**)malloc(rows * sizeof(Node*));
            if (arr_sp == NULL) {
                printf("�� ������� �������� ������!\n");
                return;
            }
            for (i = 0; i < rows; i++) {
                arr_sp[i] = NULL;
            }
            addSp(arr_sp, arr, rows);
            printSp(arr_sp, rows);
            break;
        case 4: // ��������� ���������� ������
            if (arr == NULL) {
                printf("������� �������� ����!\n");
                break;
            }
            printf("������� �������� �����: ");
            scanf("%s", &name);
            if ((file = fopen(name, "w")) == NULL)
            {
                printf("�� ������� ������� ����");
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
                printf("������� �������� ����!\n");
                break;
            }
            // ��������� �������� ��������
            if (arr == NULL) {
                printf("������� �������� ����!\n");
                break;
            }
            printf("������� ��������� �������: ");
            scanf("%d", &startVertex);
            startVertex--;
            if (startVertex < 0 || startVertex >= rows) {
                printf("������������ ����� �������!\n");
                break;
            }
            dijkstra(arr, startVertex, rows);
            break;
        case 6: // ����������� ������
            if (arr == NULL) {
                printf("������� �������� ����!\n");
                break;
            }
            // �������� ������� ��������� �� �����
            printf("������� ��������� ��� �����:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-4d ", arr[i][j]);
                }
                printf("\n");
            }
            printSp(arr_sp, rows);
            break;
        case 7: // �����
            system("cls");
            printf("�� ��������!\n");
            break;
        default:
            printf("������������ �����!\n");
            break;
        }
    } while (choice != 7);
}