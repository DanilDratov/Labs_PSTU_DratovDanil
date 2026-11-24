#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 101;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        n++; // чтобы был чёткий центр
    }

    int A[MAX][MAX] = {0};
    int mid = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - mid) + abs(j - mid) == mid) {
                A[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) {
                cout << 1;
            } else if (abs(i - mid) + abs(j - mid) < mid) {
                cout << 0;
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}