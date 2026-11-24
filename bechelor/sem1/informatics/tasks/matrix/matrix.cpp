#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>


using namespace std;

const int MAX = 101;

int main() {
    setlocale(LC_ALL, ".UTF8");
    srand(time(0));

    int rows, cols;
    cout << "Введите количество строк и столбцов: ";
    cin >> rows >> cols;

    int A[MAX][MAX];
    int B[MAX][MAX];

    // 1. Заполняем исходную матрицу случайными числами от 0 до 9
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = rand() % 10;
        }
    }

    // 2. Выводим исходную матрицу
    cout << "\nИсходная матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    // 3. Вариант 1: 0 выше главной диагонали (i < j)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B[i][j] = (i < j) ? 0 : A[i][j];
        }
    }

    cout << "\n0 выше главной диагонали:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << B[i][j] << ' ';
        }
        cout << '\n';
    }

    // 4. Вариант 2: 0 выше побочной диагонали (i + j < cols - 1)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B[i][j] = (i + j < cols - 1) ? 0 : A[i][j];
        }
    }

    cout << "\n0 выше побочной диагонали:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << B[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}