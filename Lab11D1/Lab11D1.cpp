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
        h->N = i;

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
void delet(STR*& first, int size)
{
    STR* p = first;
    STR* q = new STR;
    first = q;
    for (int i = 0; i < size/2; i++)
    {
        STR* h = new STR;
        q->data = p->data;
        q->N = p->N;
        p = p->next;
        p = p->next;
        if (p==NULL)
        {
            q->next = NULL;
        }
        else
        {
            q->next = h;
        }
        q = q->next;
    }
    if (size % 2 != 0)
    {
        q->data = p->data;
        q->N = p->N;
        q->next = NULL;
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
    delet(first, size);
    cout << "Очередь после обработки:" << endl;
    out(first);
    delete first;
}

