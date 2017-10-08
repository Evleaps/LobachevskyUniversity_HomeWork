#include <stdio.h>
#include <stdbool.h>
#include "searchSquareinCircle/searchSquareInCircle.h"
#include "euclideanAlgorithm/EuclideanAlgorithm.h"
#include "testTimeEuclideanAlgorithm/EuclideanTest.h"

int id;
int main() {
    while (true) {
        printf("\nВНИМАНИЕ! Для запуска программы введите ее номер в консоль. Что-бы выйти введите 0!\n "
                       "Доступные программы: \n"
                       "1  Поиск стороны квадрата по радиусу описанной окружности \n"
                       "2  Нахождение НОД и коэффициентов Безу с помощью алгоритма Евклида \n"
                       "3  Програмка содержит 4 алгоритма Евклида и проверям скорость"
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
            case 3: testEuclidean();
                break;
        }
    }
}