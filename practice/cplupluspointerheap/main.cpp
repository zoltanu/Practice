#include <iostream>

using namespace std;

int main()
{
    int localVariable = 5;
    int *pVariable = &localVariable;
    int *pHeap = new int;

    if (pHeap==NULL)
    {
        cout << "Error, not enough memory" << endl;
        return 1;
    }
    *pHeap = 7;

    cout << "localVariable: " << localVariable << endl;
    cout << "*pVariable: " << *pVariable << endl;
    cout << "*pHeap: " << *pHeap << endl;

    delete pHeap;
    pHeap= new int;

        if (pHeap==NULL)
    {
        cout << "Error, not enough memory" << endl;
        return 1;
    }

    *pHeap = 9;

    cout << "*pHeap: " << *pHeap << endl;
    delete pHeap;
    return 0;
}
