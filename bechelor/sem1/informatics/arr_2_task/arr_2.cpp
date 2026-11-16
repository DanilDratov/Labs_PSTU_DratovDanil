#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

int main(){
    setlocale(LC_ALL, ".UTF8");
    int i = 2, sum = 0;
    int a[2][2];

    for (int j = 0; j < 2; j++){
        for (int k = 0; k < i; k++){
            a[j][k] = rand() % 100;
            sum += a[j][k];
        }
    }
    cout << "Сумма элементов массива:" << sum << endl;
    return 0;
}