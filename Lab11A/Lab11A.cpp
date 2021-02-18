#include <iostream>
using namespace std;

//добавить в список элемент с заданным номером



struct STR
{
    int N;
    char* data;
    STR* next;
};

STR* fill(int size)
{
    STR* first, * p = new STR;
    first = NULL;
    cout << "Введите первый элемент: ";
    cin >> p->data;
    first = p;
    for (int i = 2; i <= size; i++)
    {
        STR* h = new STR;
        p->next = h;
        p = p->next;
        cout << "Введите " << i << " элемент: ";
        cin >> p->data;
        p->N = i;
        p->next = NULL;
    }
    return first;
}

int main()
{
    system("chcp 1251>nul");
    int size = -1;
    cout << "Введите количество элементов списка" << endl;
    while (size <= 0)
    {
        cin >> size;
        if (size<=0)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
}

;k