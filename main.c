#include <stdio.h>
#include <stdbool.h>
#include "searchSquareinCircle/searchSquareInCircle.h"
#include "euclideanAlgorithm/EuclideanAlgorithm.h"

int id;
int main() {
    while (true) {
        printf("\nВНИМАНИЕ! Для запуска программы введите ее номер в консоль. Что-бы выйти введите 0!\n "
                       "Доступные программы: \n"
                       "1  Поиск стороны квадрата по радиусу описанной окружности \n"
                       "2  Нахождение НОД с помощью алгоритма Евклида \n"
                       "\n");

        scanf("%d", &id);

        switch (id) {
            case 0:

                break;
            case 1:
                searchSquareInCircle();
                break;
            case 2: CoefficientBezu();
                break;
        }
    }
}