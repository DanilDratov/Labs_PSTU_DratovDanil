#include <iostream>
#include <string>
#include <limits>
#include <clocale>

using namespace std;

struct Apartment {
    double price;
    int floor;
    double size;
    string street;
};

int main() {

    setlocale(LC_ALL, ".UTF8");

    const int N = 3;
    Apartment v[N];

    for (int i = 0; i < N; i++) {
        cout << "Квартира #" << (i + 1) << "\n";

        cout << "Цена за квартиру: ";
        cin >> v[i].price;

        cout << "Этаж: ";
        cin >> v[i].floor;

        cout << "Площадь квартиры: ";
        cin >> v[i].size;

        // Очищаем остаток строки (перевод '\n') после cin >>, иначе getline прочитает пустую строку
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Улица и номер дома: ";
        getline(cin, v[i].street);

        cout << "\n";
    }

    double target_price;
    cout << "За какую цену вы ищете квартиру: ";
    cin >> target_price;

    bool found = false;
    for (int i = 0; i < N; i++) {
        if (v[i].price == target_price) {
            found = true;
            cout << "\nНайдена квартира:\n";
            cout << "Цена за квартиру: " << v[i].price << "\n";
            cout << "Этаж: " << v[i].floor << "\n";
            cout << "Площадь квартиры: " << v[i].size << "\n";
            cout << "Улица и номер дома: " << v[i].street << "\n";
        }
    }

    if (!found) {
        cout << "\nКвартир с такой ценой не найдено.\n";
    }

    return 0;
}