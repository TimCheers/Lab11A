#include <iostream>
#include <string>
using namespace std;
struct STR
{
    int N;
    double data;
    STR* next;
    STR* prev;
};
STR* fill(int size)
{
    STR* first, * p = new STR;
    first = NULL;
    cout << "Введите 1 элемент: ";
    cin >> p->data;
    p->N = 1;
    first = p;
    p->next = NULL;
    p->prev = NULL;
    for (int i = 2; i <= size; i++)
    {
        STR* h = new STR;
        STR* q = p;
        p->next = h;
        p = p->next;
        cout << "Введите " << i << " элемент: ";
        cin >> p->data;
        p->N = i;
        p->next = NULL;
        p->prev = q;
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
        cout << "№\tЭлементы" << endl;
        STR* p = first;
        while (p != NULL)
        {
            cout << p->N << "\t" << p->data << endl;
            p = p->next;
        }
        cout << endl;
    }
}
void delet(STR*& first)
{
    STR* p = first;
    while (p->next != NULL)
    {
        if (p->N % 2 == 0)
        {
            
        }
        else
        {
            p = p->next;
        }
    }
}
int main()
{
    system("chcp 1251>nul");
    int size = -1;
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
    delet(first);
    out(first);
    return 0;
}

