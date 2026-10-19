#include <iostream>
using namespace std;
int main()
{
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
}