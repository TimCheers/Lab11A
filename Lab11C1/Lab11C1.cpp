#include <iostream>
#include <string>
using namespace std;
struct STR
{
	string data;
	STR* prev;
};
STR* fill(int size)
{
    string data;
    STR* top, * p = new STR;
    top = NULL;
    cout << "Введите 1 элемент: ";
    cin >> data;
    p->data = data;
    p->prev = NULL;
    top = p;
    for (int i = 2; i <= size; i++)
    {
        STR* h = new STR;
        cout << "Введите " << i << " элемент: ";
        cin >> data;
        h->data = data;
        h->prev = top;
        top = h;
    }
    return top;
}
void out(STR* top)
{
    if (top == NULL)
    {
        cout << "Стек пуст" << endl;
    }
    else
    {
        STR* p = top;
        while (p != NULL)
        {
            cout << p->data << endl;
            p = p->prev;
        }
    }
}
string Top(STR*& top)
{
    STR* p = top;
    int k = 0;
    while (p != NULL)
    {
        k++;
        p = p->prev;      
    }
    p = top;
    if (k == 1)
    {
        string t = top->data;
        delete p;
        top = NULL;
        return t;
    }
    else
    {
        STR* t = p->prev;
        string u = p->data;
        top = t;
        delete p;
        return u;
    }
}
STR* pu(STR*& top, string A)
{
    STR* h = new STR;
    h->data = A;
    h->prev = top;
    top = h;
    return top;
}
void add(STR* top, STR* st, int No, int size)
{
    string dat;
    for (int i = 0; i < size - No + 1; i++)
    {
        string p = Top(top);
        pu(st, p);
    }
    cout << "Введите новый элемент: ";
    cin >> dat;
    pu(top, dat);
    for (int i = 0; i < size - No + 1; i++)
    {
        string t = Top(st);
        pu(top, t);
    }
}
int main()
{
    system("chcp 1251>nul");
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
    STR* top = fill(size);
    out(top);
    cout << "Введите номер добавляемого элемента: ";
    while (No <= 0 || No >= size + 2)
    {
        cin >> No;
        if (No <= 0 || No >= size + 2)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
    STR* st = new STR;
    add(top, st, No, size);
    return 0;
}

