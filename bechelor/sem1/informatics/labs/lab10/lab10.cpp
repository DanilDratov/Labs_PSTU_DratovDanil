#include <iostream> // Подключение потокового ввода-вывода
#include <clocale>  // Подключение локали для корректного вывода кириллицы

using namespace std;

// 1. Функция формирования (выделения памяти и ручного ввода) одномерного динамического массива
int* createArr(int n)
{
    int* arr = new int[n]; // Выделяем динамическую память под n элементов типа int
    cout << "Введите " << n << " элементов массива:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Считываем каждый элемент с клавиатуры
    }
    return arr;
}

// 2. Функция печати элементов массива
void printArr(const int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 3. Функция удаления K элементов, начиная с заданного номера (считаем номера с 1)
int* removeK(int* arr, int& n, int k, int pos)
{
    int start = pos - 1; // Переводим номер элемента (с 1) в индекс (с 0)

    // Проверяем корректность параметров удаления
    if (k <= 0 || start < 0 || start >= n)
    {
        cout << "Удаление пропущено: некорректные K или номер элемента." << endl;
        int* copy = new int[n]; // Создаем копию текущего массива
        for (int i = 0; i < n; i++)
        {
            copy[i] = arr[i];
        }
        return copy;
    }

    // Ограничиваем число удаляемых элементов размером оставшейся части массива
    int delCount = k;
    if (start + delCount > n)
    {
        delCount = n - start;
    }

    int newSize = n - delCount;
    int* res = new int[newSize]; // Формируем новый массив уменьшенного размера

    int idx = 0;
    // Копируем элементы до удаляемого фрагмента
    for (int i = 0; i < start; i++)
    {
        res[idx] = arr[i];
        idx++;
    }
    // Копируем элементы после удаляемого фрагмента
    for (int i = start + delCount; i < n; i++)
    {
        res[idx] = arr[i];
        idx++;
    }

    n = newSize; // Обновляем актуальную длину массива
    return res;
}

// 4. Функция добавления K элементов, начиная с заданного номера (считаем номера с 1)
int* addK(int* arr, int& n, int k, int pos)
{
    int insIdx = pos - 1; // Индекс позиции вставки (от 0 до n)

    // Проверяем корректность параметров вставки
    if (k <= 0 || insIdx < 0 || insIdx > n)
    {
        cout << "Добавление пропущено: некорректные K или номер элемента." << endl;
        int* copy = new int[n]; // Создаем копию текущего массива
        for (int i = 0; i < n; i++)
        {
            copy[i] = arr[i];
        }
        return copy;
    }

    int newSize = n + k;
    int* res = new int[newSize]; // Формируем новый массив увеличенного размера

    // Копируем элементы до точки вставки
    for (int i = 0; i < insIdx; i++)
    {
        res[i] = arr[i];
    }

    // Вводим K новых элементов с клавиатуры
    cout << "Введите " << k << " элементов для добавления:" << endl;
    for (int i = 0; i < k; i++)
    {
        cin >> res[insIdx + i];
    }

    // Переносим оставшиеся элементы после точки вставки
    for (int i = insIdx; i < n; i++)
    {
        res[insIdx + k + (i - insIdx)] = arr[i];
    }

    n = newSize; // Обновляем актуальную длину массива
    return res;
}

// 5. Функция удаления динамического массива и сброса указателя
void deleteArr(int*& arr)
{
    delete[] arr;
    arr = nullptr;
}

int main()
{
    setlocale(LC_ALL, ".UTF8");

    int n = 0;
    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Размер массива должен быть больше 0." << endl;
        return 0;
    }

    // Формируем исходный массив вручную и выводим его
    int* arr = createArr(n);
    cout << "Исходный массив: ";
    printArr(arr, n);

    int k = 0;
    int posDel = 0;
    cout << "Введите K (сколько элементов удалить/добавить): ";
    cin >> k;
    cout << "Введите номер элемента (с 1), с которого удалить K элементов: ";
    cin >> posDel;

    // Удаляем K элементов, формируем новый массив и освобождаем старый
    int* afterDel = removeK(arr, n, k, posDel);
    deleteArr(arr);
    arr = afterDel;

    cout << "Массив после удаления: ";
    printArr(arr, n);

    int posAdd = 0;
    cout << "Введите номер элемента (с 1), начиная с которого добавить K элементов: ";
    cin >> posAdd;

    // Добавляем K элементов, формируем новый массив и освобождаем старый
    int* afterAdd = addK(arr, n, k, posAdd);
    deleteArr(arr);
    arr = afterAdd;

    cout << "Итоговый массив после добавления: ";
    printArr(arr, n);

    // Финальное освобождение динамической памяти
    deleteArr(arr);

    return 0;
}

