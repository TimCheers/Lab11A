#include <iostream>
#include <stack>
#include <string>
using namespace std;
void out(stack<string>str)
{
    int p = str.size();
    if (p==0)
    {
        cout << "Стек пуст!" << endl;
    }
    else
    {
        for (int i = 0; i < p; i++)
        {
            cout << str.top() << "\t";
            str.pop();
        }
    }
    cout << endl;
}
int main()
{
    system("chcp 1251>nul");
    string dat;
    stack<string>str;
    stack<string>str2;
    int size = -1, No = -1;
    cout << "Введите количество элементов стека" << endl;
    while (size <= 0)
    {
        cin >> size;
        if (size <= 0)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
    string a;
    for (int i = 0; i < size; i++)
    {
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> a;
        str.push(a);
    }
    out(str);
    cout << "Введите номер добавляемого элемента: ";
    while (No <= 0 || No >= size + 2)
    {
        cin >> No;
        if (No <= 0 || No >= size + 2)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
    for (int i = 0; i < size - No + 1; i++)
    {
        str2.push(str.top());
        str.pop();
    }
    cout << "Введите новый элемент: ";
    cin >> dat;
    str.push(dat);
    for (int i = 0; i < size - No + 1; i++)
    {
        str.push(str2.top());
        str2.pop();
    }
    out(str);
    return 0;
}
