#include <iostream>
#include <string>
using namespace std;
struct STR
{
    int N;
    string data;
    STR* next;
};
STR* fill(int size)
{
    cin.ignore();
    STR* first, * p = new STR;
    first = NULL;
    cout << "Введите 1 элемент: ";
    getline(cin, p->data);
    p->N = 1;
    first = p;
    for (int i = 2; i <= size; i++)
    {
        STR* h = new STR;
        p->next = h; 
        p = p->next;
        cout << "Введите " << i << " элемент: ";
        getline(cin, p->data);
        p->N = i;
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
        cout << "№\tСтрока:" << endl;
        STR* p = first;
        while (p != NULL)
        {
            cout << p->N << "\t" << p->data << endl;
            p = p->next;
        }
        cout << endl;
    }
}
void add(STR* first, int No, bool f)
{
    cin.ignore();
    STR* n = new STR;
    STR* a = new STR;
    STR* p = first;
    while (p != NULL)
    {
        if (p->N == No - 1)
        {
            STR* h = new STR;
            n = p->next;
            p->next = h;
            p = p->next;
            cout << "Введите новый элемент элемент: ";
            getline(cin, p->data);
            p->next = n;
            p->N = No;
        }
        p = p->next;
        if (p != NULL && f == true)
        {
            p->N++;
        }
    }
}
int main()
{
    system("chcp 1251>nul");
    int size = -1, No = -1;
    bool f = 0;
    cout << "Введите количество элементов списка" << endl;
    while (size <= 0)
    {
        cin >> size;
        if (size <= 0)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
    STR* first = fill(size);
    out(first);
    cout << "Введите номер добавляемого элемента: ";
    while (No <= 0 || No >= size+2)
    {
        cin >> No;
        if (No <= 0 || No >= size+2)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
    if (No!=size+1)
    {
        f = true;
    }
    if (No==1)
    {
        
        STR* h = new STR;
        h->next = first;
        first = h;
        cout << "Введите новый элемент элемент: ";
        getline(cin, h->data);
        h->N = 1;
    }
    add(first, No, f);
    cout << endl << endl;
    out(first);
    return 0;
}
