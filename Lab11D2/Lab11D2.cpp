#include <iostream>
#include <queue>
using namespace std;
void out(queue<double>STR, int size)
{
    double* arr = new double[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = STR.front();
        cout << STR.front() << "\t";
        STR.pop();
    }
    for (int i = 0; i < size; i++)
    {
        STR.push(arr[i]);
    }
    cout << endl;
    delete[] arr;
}
void delet(queue<double>&STR, int &size)
{
    int n;
    bool f = 0;
    if (size % 2 != 0)
    {
        n = size / 2 + 1;
        f = 1;
    }
    else
    {
        n = size / 2;
    }
    size = n;
    double* arr = new double[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = STR.front();
        STR.pop();
        if (STR.size()!=0)
        {
            STR.pop();
        }
    }
    for (int i = 0; i < size; i++)
    {
        STR.push(arr[i]);
    }
    delete[] arr;
}
int main()
{
    int size = -1, No = -1;
    system("chcp 1251>nul");
    queue<double> STR;
    double data;
    cout << "Введите количество элементов очереди" << endl;
    while (size <= 0)
    {
        cin >> size;
        if (size <= 0)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Введите " << i+1 << " элемент: ";
        cin >> data;
        STR.push(data);
    }
    cout << "Очередь: ";
    out(STR, size);
    cout << endl;
    delet(STR, size);
    cout << "Очередь после обработки: ";
    out(STR, size);
}
