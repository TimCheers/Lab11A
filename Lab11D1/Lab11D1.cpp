#include <iostream>
using namespace std;
struct STR
{
    double data;
    STR* next;
    int N;
};
void fill(int n, STR*& first, STR*& last)
{
    STR* p = new STR;
    double data;
    cout << "Введите 1 элемент: ";
    cin >> data;
    p->data = data;
    p->next = NULL;
    p->N = 1;
    first = p;
    last = p;
    for (int i = 2; i <= n; i++)
    {
        STR* h = new STR;
        cout << "Введите " << i << " элемент: ";
        cin >> data;
        h->data = data;
        p->N = i;
        h->next = NULL;
        p->next = h;
        p = p->next;
    }
}
void out(STR* first)
{
    STR* p = first;
    while (p != NULL)
    {
        cout <<p->N<<") " <<p->data << endl;
        p = p->next;
    }
    cout << endl;
}
void delet(STR*& first)
{
    STR* p = first;
    while (p->next != NULL)
    {
        if (p->next->N % 2 == 0)
        {
            if (p->next->next == NULL)
            {
                p->next = NULL;
            }
            else
            {
                STR* q = p->next;
                p->next = p->next->next;
                delete q;
            }
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
    int size = -1, No = -1;
    STR* first=new STR, * last= new STR;
    cout << "Введите количество элементов очереди" << endl;
    while (size <= 0)
    {
        cin >> size;
        if (size <= 0)
        {
            cout << "Введено некоректное значение" << endl;
        }
    }
    fill(size, first, last);
    out(first);
    delet(first);
    out(first);
}

