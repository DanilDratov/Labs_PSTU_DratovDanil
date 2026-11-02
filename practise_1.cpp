#include <iostream>
#include <clocale>
using namespace std;

int main()
/*{
    int x = 5;
    double y = 3.14;

    cout << "Value of x:" << x << "\n"; //5
    cout << "Address of x:" << &x << "\n"; //000000661FB4FEF0
    cout << "Address of y:" << &y << "\n"; //000000661FB4FEF8
    
    
    int num = 42;
    int* ptr = &num; // ptr хранит адрес num

    cout << ptr << "\n"; //Адрес (0x7ffe...)
    cout << *ptr << "\n"; //Значение: 42

    *ptr = 100;//Изменяем значение num через ptr
    cout << num << "\n";//Значение: 100
    

    int a = 255;
    cout << "Before:" << a<< endl;
    int& ref = a;
    ref++;
    cout << "After:" << a;//256
    return 0;   
}*/
{
    setlocale(LC_ALL, ".UTF8");

    cout << "Цикл с i++:\n";
    // i++ сначала отдает старое значение (1), поэтому условие 1 <= 2 верно. 
    // Затем i становится равным 2, и цикл завершается.
    for (int i = 1; i++ <= 2; ) {
        cout << "i = " << i << " ";
    }
    cout << "\n\n";

    cout << "Цикл с ++i:\n";
    // ++i сначала увеличивает i до 2, и сравнивает 2 <= 2 (верно).
    // На второй итерации ++i увеличит i до 3, сравнивает 3 <= 2 (ложь), и цикл завершится.
    for (int i = 1; ++i <= 2; ) {
        cout << "i = " << i << " ";
    }
    cout << endl;
    cout << endl;

    cout << "while i++:\n";
    {
        int i = 1;
        while (i <= 3) {
            cout << i++ << " ";
        }
    }
    cout << "\n\n";

    cout << "while ++i:\n";
    {
        int i = 1;
        while (i <= 3) {
            cout << ++i << " ";
        }
    }
    cout << endl;

    return 0;
}