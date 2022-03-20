/*Вы загадали натуральное число пи решили заполнить квадратную таблицу размером n*n
буквами по «диагональному правилу» - клетки, находящиеся на двух самых длинных диагоналях,
должны содержать символ «а». Пустые клетки, соседние с «а»-клетками, нужно заполнить символом
«b», и так далее по алфавиту. Когда придет время заполнять соседей «Z»-клеток, в них нужно записать
символ «а». Напишите программу, которая выведет получившуюся таблицу.
Формат входных данных
Входные данные содержат одно целое число п(1 <n < 100) — высоту и ширину таблицы.*/

#include <iostream>

int Foo(int letter) {
    letter < 26 ? letter = letter : letter = letter - 26;
    return letter;
}

int main()
{
    int N;
    std::cin >> N;
    int middle = N / 2;
    int letter;
    int center;

    char** din_array = new char* [N];
    for (int i = 0; i < N; i++) {
        din_array[i] = new char[N];
    }

    char title[50];
    for (char i = 'a'; i <= 'z'; ++i) {
        title[i - 'a'] = i;
    }

    N % 2 == 0 ? center = middle : center = middle + 1;

    for (int i = 0; i < center; i++) {
        float flag = 1;
        letter = i;
        for (int j = 0; j < center; j++) {
            if (i == j) {
                flag = 0;
                letter = 0;
            }
            din_array[i][j] = title[Foo(letter)];
            flag == 0 ? letter++ : letter--;
        }
    }

    for (int i = 0; i < center; i++) {
        int temp = 0;
        for (int j = center; j < N; j++) {
            din_array[i][j] = din_array[i][middle - 1 - temp];
            temp++;
        }
    }

    int temp = 0;
    for (int i = center; i < N; i++) {
        for (int j = 0; j < N; j++) {
            din_array[i][j] = din_array[middle - 1 - temp][j];
        }
        temp++;
    }

    for (int i = 0; i < N; i++) {
        std::cout << std::endl;
        for (int j = 0; j < N; j++) {
            std::cout << din_array[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        delete[] din_array[i];
    }
    return 0;
}