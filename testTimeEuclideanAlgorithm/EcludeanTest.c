//
// Created by evleaps on 09.10.17.
//

#include <printf.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <stdbool.h>




void testEuclidean() {
    char answer[1];//это для проверки Y\n продолжить или не
    printf("Балуемся, смотрим какой алгоритм за какое время отработает. Потом сравним с java. "
                   "Запустить? Y/n \n");
    scanf("%s", &answer);
    if (strcmp(answer, "Y") == 0) {
        work3();
    }
}

void work3() {
    int countMethod = 0;
    unsigned int start_time; // начальное время
    unsigned int end_time; // конечное время
    unsigned int search_time; // искомое время

    countMethod++;
    start_time = clock(); // начальное время
    NOD1(58463256, 6643342222);
    end_time = clock(); // конечное время
    search_time = end_time - start_time; // искомое время
    printf("Искомое время метода %d: %d \n", countMethod, search_time);

    countMethod++;
    start_time = clock(); // начальное время
    NOD2(58463256, 6643342222);
    end_time = clock(); // конечное время
    search_time = end_time - start_time; // искомое время
    printf("Искомое время метода %d: %d \n", countMethod, search_time);

    countMethod++;
    start_time = clock(); // начальное время
    NOD3(58463256, 6643342222);
    end_time = clock(); // конечное время
    search_time = end_time - start_time; // искомое время
    printf("Искомое время метода %d: %d \n", countMethod, search_time);

    countMethod++;
    start_time = clock(); // начальное время
    NOD4(58463256, 6643342222);
    end_time = clock(); // конечное время
    search_time = end_time - start_time; // искомое время
    printf("Искомое время метода %d: %d \n", countMethod, search_time);



}

int NOD1(int a, int b) {

    long *array; //массив для сохранения множителя в матрице расширенного алгоритма Евклида
    int i = 0;
    int size = 16;
    int tmp;
    array = (long *) malloc(size * sizeof(long));

    while (true) {
        int c = a / b;//нашли множитель и отправили его в массив полежать
        array[i] = c;
        i++;
        if (i == 16) {//если размер массива закончился, увеличивем его по формуле ниже
            size = (size * 3) / 2 + 1;
            array = (long *) malloc(size * sizeof(long));
        }

        tmp = b;
        b = a % b;
        if (b == 0) break;
        a = tmp;
    }

    return tmp;
}

int fullEuclidean(int a, int b, int x, int y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = fullEuclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;

    return d;
}



int min(int a, int b) {
    return a > b ? b : a;
}
int NOD2(int a, int b) {
    int nod = 1L;
    for (int i = min(a, b); i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            nod = i;
            break;
        }
    }
    return nod;
}


int NOD3(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    return NOD3(a, b - a);
}


int NOD4(int a, int b) {
    while (a != b) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        b = b - a;
    }
    return a;
}
