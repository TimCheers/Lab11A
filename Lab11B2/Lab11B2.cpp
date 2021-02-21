#include <iostream>
#include <list>
#include <iterator>
using namespace std;


int main()
{
    system("chcp 1251>nul");
    list<double> STR;
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
    for (int i = 0; i < size; i++)
    {
        double n;
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> n;
        STR.push_back(n);
        cout << endl;
    }
    auto it = STR.begin();
    ++it;
    while(it != STR.end())
    {
        STR.erase(it);
        if ( != STR.end())
        {
            ++it;
            ++it;
        }
    }
    auto it2 = STR.begin();
    for (auto i = STR.begin(); i != STR.end(); i++)
    {
        cout << *i << endl;
    }
    return 0;
}


