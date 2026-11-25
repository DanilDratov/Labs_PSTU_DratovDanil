#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 101;

int main() {
    srand(time(0));

    int n;
    cout << "size matrix n: ";
    cin >> n;

    int A[MAX][MAX];

    // 1. Заполняем матрицу случайными числами от 0 до 9
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
        }
    }

    // 2. Выводим исходную матрицу
    cout << "\nfirst matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    // 3. Заменяем на 0 всё, что выше главной (i < j) и выше побочной (i + j < n - 1) диагонали
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j || i + j < n - 1) {
                A[i][j] = 0;
            }
        }
    }

    // 4. Выводим изменённую матрицу
    cout << "\nchanged matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}