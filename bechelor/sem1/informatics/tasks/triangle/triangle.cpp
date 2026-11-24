#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 101;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) n++;

    int rows = (n + 1) / 2, mid = n / 2;
    char A[MAX][MAX];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            int d = abs(j - mid);
            if (d == i || (i == rows - 1 && d <= i)) A[i][j] = '1';
            else if (d < i) A[i][j] = '0';
            else A[i][j] = ' ';
            cout << A[i][j];
        }
        cout << '\n';
    }
    return 0;
}