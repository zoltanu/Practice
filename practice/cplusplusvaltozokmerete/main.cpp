#include <iostream>

using namespace std;

int main()
{
    cout << "Az int merete:\t\t" << sizeof(int) << endl;
    cout << "A short merete:\t\t" << sizeof(short) << endl;
    cout << "A long merete:\t\t" << sizeof(long) << endl;
    cout << "A char merete:\t\t" << sizeof(char) << endl;
    cout << "A bool merete:\t\t" << sizeof(bool) << endl;
    cout << "A float merete:\t\t" << sizeof(float) << endl;
    cout << "A double merete:\t" << sizeof(double) << endl;

    int a=5,b=5,c;
    c=a+b;
    ++a;

    return 0;
}
