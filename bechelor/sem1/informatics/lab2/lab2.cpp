//ВАРИАНТ 5
#include <iostream>
#include <cmath>
using namespace std;

int main(){

    setlocale(LC_ALL, ".UTF8");


    const double eps = 1e-4; // Точность вычислений (эпсилон)
    
    double sum = 0.0; // Накапливаемая сумма ряда
    int n = 1; // Счетчик (номер члена ряда)

    // Вычисляем первый член ряда a = (-1)^(n-1)/n^n
    double a = pow(-1.0, n - 1) /pow(n, n);

    // Цикл выполняется, пока модуль текущего члена ряда >= eps
    while(abs(a)>= eps){
        sum += a; // Прибавляем текущий член к сумме
        n++; // Переходим к следующему n
        a = pow(-1.0,n - 1) / pow(n, n);// Пересчитываем следующий член ряда
    } 

    // Вывод результатов
    cout << "Сумма ряда: " << sum << endl;
    cout << "Количество членов: " << n - 1 << endl;
    
    return 0;    
}