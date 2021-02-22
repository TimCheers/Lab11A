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
    auto pt = STR.end();
    auto qt = STR.begin();
    int n = 2;
    pt--;
    ++it;
    while(it != STR.end())
    {
        if (it != pt)
        {
            if (it!=STR.end())
            {
                STR.erase(it);
                it = STR.begin();
                for (int i = 0; i < n; i++)
                {
                    ++it;
                }
                n++;
            }
        }
        else
        {
            STR.erase(it);
            it = STR.end();
        }
    }
    cout << "Список после обработки:" << endl;
    auto it2 = STR.begin();
    for (auto i = STR.begin(); i != STR.end(); i++)
    {
        cout << *i << endl;
    }
    delete &STR;
    return 0;
}


