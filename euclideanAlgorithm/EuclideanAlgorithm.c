//
// Created by evleaps on 06.10.17.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

long j1; //это второе число Безу, да второе
long j2; //первое
char answer[1];//это для проверки Y\n продолжить или не
long *array; //массив для сохранения множителя в матрице расширенного алгоритма Евклида
int  i = 0;//этот костыль счетчик элементов в массиве, блин, не знаю как тут работает array.length и вообще ли он есть

void CoefficientBezu() {
    printf("Эта программа зависимости от введенных значений находит НОД и коэффициенты Безу для уравнения типа ax + by = z \n "
                   "где введенные данные целые положительные числа."
                   "Запустить? Y/n \n");
    scanf("%s", &answer);
   if (strcmp(answer, "Y") == 0 ) {
        work2();
    }
}

/**Это главный метот программы, он будет повторять выполнение всяки раз пока пользователь не введет НЕ 'Y'*/

void work2() {
    long A1 = 0;
    long A2 = 0;

    while (true) {
        printf("Уравнение имеет вид A1x + A2y = A3 \nВведите число A1 \n");
        scanf("%ld", &A1);
        printf("Введите число А2\n");
        scanf("%ld", &A2);

        //Нам важно, что-бы А1 было побольше товарища
        if (A2 > A1) {
            long tmp = A1;
            A1 = A2;
            A2 = tmp;
        }

        int nod = NOD(A1, A2);
        int bezuConfirm = bezu(A1, A2);
        i = 0;

        printf("Для введенных чисел НОД соответствует: %d \n"
                       "Коэффиценты Безу для уравнения ax+by=nod равны %ld и %ld соответственно \n"
                       "Проверка доказывает это: %ld * %ld + %ld * %ld = %d \n\n\n", nod,  j1, j2, A1, j1, A2, j2, bezuConfirm);

        printf("Продолжить выполнение программы?!  Y/n  \n");
        scanf("%s", &answer);
        if (strcmp(answer, "Y") != 0) {
            break;
        }
    }

}

/**Этот метод находит НОД, а еще отправляет множитель в массив, что-бы потом можно было найти костылем любимым Безу
 * Массив динамически расширяется по формуле, что описана в любимой Java в исходниках к работе ArrayList*/
int NOD(long a, long b) {
    int size = 16;
    long tmp;
    array = (long *) malloc(size * sizeof(long));

    while (true) {
        long c = a / b;//нашли множитель и отправили его в массив полежать
        array[i] = c;
        i++;
        if (i==16) {//если размер массива закончился, увеличивем его по формуле ниже
            size = (size * 3) / 2 + 1;
            array = (long *) malloc(size * sizeof(long));
        }

        tmp = b;
        b = a%b;
        if(b == 0) break;
        a = tmp;
    }
    return tmp;
}

/**Простите за названия переменных, я почти индус. Смысл в том, что тут расширенный алгоритм Евклида, постройте его на
 * бумаге и поймете как работает этот местод*/




int bezu(long a, long b) {
    int i1 = 1;
    int i2 = 0;
    int k1 = 0;
    int k2 = 1;

    int l = 0;//это тут только потому, что я не знаю как вызвать array.length или array.size черт бы побрал этот С КОСТЫЛИИИИИ
    for (int g = 0; g < i-1; g++) {
        j1 = i1 - (k1 * array[l]);
        j2 = i2 - (k2 * array[l]);

        i1 = k1;
        i2 = k2;
        k1 = j1;
        k2 = j2;

        l++;
    }

    return a * j1 + b * j2;
}