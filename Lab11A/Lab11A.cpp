#include <iostream>
#include <string>
using namespace std;
//добавить в список элемент с заданным номером
struct STR
{
    int N;
    string data;
    STR* next;
};
STR* fill(int size, int& k)
{
    STR* first, * p = new STR;
    first = NULL;
    cout << "Введите 1 элемент: ";
    cin >> p->data;
    p->N = 1;
    first = p;
    for (int i = 2; i <= size; i++)
    {
        STR* h = new STR;
        p->next = h; 
        p = p->next;
        cout << "Введите " << i << " элемент: ";
        cin >> p->data;
        p->N = i;
        k++;
        p->next = NULL;
    }
    return first;
}
void out(STR* first)
{
    if (first == NULL)
    {
        cout << "Список пуст!" << endl;
    }
    else
    {
        cout << "№" << endl;
        STR* p = first;
        while (p != NULL)
        {
            cout << p->N << "\t" << p->data << endl;
            p = p->next;
        }
        cout << endl;
    }
}
void add(STR* first, int No)
{
    STR* p = first;
    STR* n = new STR;
    bool f = 0;
    while (p != NULL)
    {
        //if (p->N == 1)
        //{
        //    STR* h = new STR;
        //    p->next = first;
        //    first = h;
        //    cout << "Введите новый элемент элемент: ";
        //    cin >> p->data;
        //    p->N = No;
        //    f = 1;
        //}
        if (p->N == No - 1)
        {
            STR* h = new STR;
            n = p->next;
            p->next = h;
            p = p->next;
            cout << "Введите новый элемент элемент: ";
            cin >> p->data;
            p->next = n;
            p->N = No;
            f = 1;
        }
        p = p->next;
        if (f==true&& p != NULL)
        {
            p->N++;

        }
    }
}
int main()
{
    system("chcp 1251>nul");
    int size = -1, No = -1;
    cout << "Введите количество элементов списка" << endl;
    while (size <= 0)
    {
        cin >> size;
        if (size <= 0)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
    STR* first = fill(size, size);
    out(first);
    cout << "Введите номер добавляемого элемента: ";
    while (No <= 0 || No >= size)
    {
        cin >> No;
        if (No <= 0 || No >= size+1)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
    add(first, No);
    cout << endl << endl;
    out(first);
    return 0;
}
