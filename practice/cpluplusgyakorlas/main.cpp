#include <iostream>

using namespace std;

class Cat
{
public:
    Cat(int initialAge);
    ~Cat();
    int GetAge();
    void SetAge(int age);
    void meow();

private:
    int itsAge;
};

//Írjuk meg mindjárt itt a class után a metódusait.


Cat::Cat(int initialAge)
{
    itsAge=initialAge;
}

Cat::~Cat()
{

}

int Cat::GetAge()
{
    return itsAge;
}

void Cat::SetAge(int age)
{
    itsAge=age;
}

void Cat::meow()
{
    cout << "Meow" << endl;
}

int main()
{
    Cat Bob(5);

    Bob.meow();
    cout << "Now we have a cat called Bob. He is " << Bob.GetAge() << " years old." << endl;
    Bob.meow();

    Bob.SetAge(8);
     cout << "Three years passed and now Bob is " << Bob.GetAge() << " years old." << endl;
    return 0;
}
