#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


float radius;
float sootnoshenie;//translitom veselee
char answer[1];//это для проверки Y\n продолжить или не

void searchSquareInCircle() {
    struct param;

    printf("В зависимости от введенного значения это приложение покажет: \n "
                   "отношение радиуса окружности к стороне вписанного в нее квадрата. PS.. оно всегда одинаковое \n"
                   "размер стороны квадрата, это уже полезною\n"
                   "Запустить? Y/n \n");
    scanf("%s", &answer);
    if (strcmp(answer, "Y") == 0 ) {
        work1();
    }
}

void work1() {
    while (true) {
        printf("Введите радиус круга\n");

        scanf("%f", &radius);

        if (radius <= 0) {
            printf("Упс, Лоли, вводи корректные числа!\n");
        } else {
            printf("Вы ввели: %10.3f\n", radius);
            /** выразим сторону квадрата через диагональ*/
            float catet = (2 * radius) / (sqrt(2));

            sootnoshenie = radius / catet;
            printf("Соотношение равно: %10.3f \n "
                           "Размер стороны квадрата: %10.3f \n", sootnoshenie, catet);
        }

        printf("Продолжить выполнение программы?!  Y/n  \n");
        scanf("%s", &answer);
        if (strcmp(answer, "Y") != 0) {
            break;
        }
    }
};

