#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class ShoeSizeEstimator
{
public:
    ShoeSizeEstimator(string shoesize, string category);
    ~ShoeSizeEstimator();

    int MatchingAlgorithm();
    void InchToCentimeter();

private:
    stringstream itsshoesize;
    string unit;
    string itscategory;
    double leglength;
    double womenshoes [9][2];
    double menshoes [9][2];
};

class InputError
{
public:
    InputError(string input):itsinput(input){}
    ~InputError(){}
    virtual void PrintError()
    {
        cout << "Wrong input! Received: " << itsinput << endl;
    }

protected:
    string itsinput;
};

class WrongUnit:public InputError
{
public:
    WrongUnit(string input):InputError(input){}
    ~WrongUnit(){}
    virtual void PrintError()
    {
        cout << InputError::itsinput << " is a unknown unit"  <<endl;
    }
};


class WrongCategory:public InputError
{
public:
    WrongCategory(string input):InputError(input){}
    ~WrongCategory(){}
    virtual void PrintError()
    {
        cout << InputError::itsinput << " is a unknown shoe category"  <<endl;
    }
};

ShoeSizeEstimator::ShoeSizeEstimator(string shoesize, string category)
{
    itsshoesize.str(shoesize);
    itsshoesize >> leglength >> unit;
    itscategory=category;
    transform(unit.begin(), unit.end(), unit.begin(), ::tolower);
    transform(category.begin(), category.end(), category.begin(), ::tolower);


    womenshoes[0][0]=20.2;
    womenshoes[0][1]=0;
    womenshoes[1][0]=21.0;
    womenshoes[1][1]=5;
    womenshoes[2][0]=21.8;
    womenshoes[2][1]=6;
    womenshoes[3][0]=22.6;
    womenshoes[3][1]=7;
    womenshoes[4][0]=23.4;
    womenshoes[4][1]=8;
    womenshoes[5][0]=24.2;
    womenshoes[5][1]=9;
    womenshoes[6][0]=25.0;
    womenshoes[6][1]=10;
    womenshoes[7][0]=25.8;
    womenshoes[7][1]=11;
    womenshoes[8][0]=27.5;
    womenshoes[8][1]=0;

    menshoes[0][0]=23.2;
    menshoes[0][1]=0;
    menshoes[1][0]=24.0;
    menshoes[1][1]=7;
    menshoes[2][0]=24.8;
    menshoes[2][1]=8;
    menshoes[3][0]=25.6;
    menshoes[3][1]=9;
    menshoes[4][0]=26.4;
    menshoes[4][1]=10;
    menshoes[5][0]=27.2;
    menshoes[5][1]=11;
    menshoes[6][0]=28.0;
    menshoes[6][1]=12;
    menshoes[7][0]=28.8;
    menshoes[7][1]=13;
    menshoes[8][0]=30.5;
    menshoes[8][1]=0;

    if (itsshoesize.fail()) //if the stream fails (eg. no number or no letters)
    {
        throw InputError(shoesize);
    }

    if (unit!="in" && unit!="cm")
    {
        throw WrongUnit(this->unit);
    }

    if (category!="w" && category!="m")
    {
        throw WrongCategory(this->itscategory);
    }

}

ShoeSizeEstimator::~ShoeSizeEstimator()
{

}


void ShoeSizeEstimator::InchToCentimeter()
{
    leglength=2.54*leglength;
}

int ShoeSizeEstimator::MatchingAlgorithm()
{
    if (unit=="in")
    {
        InchToCentimeter();
    }

    if (itscategory=="w")
    {
        int i,j;
        if (leglength<womenshoes[0][0] || leglength>(womenshoes[8][0]+0.8))
        {
            return -1;
        }

        for(i=0;i<9;i++)
        {
            if (leglength>womenshoes[i][0])
            {
                j=womenshoes[i][1];
            }
        }
        return j;
    }

        if (itscategory=="m")
    {
        int i,j;
        if (leglength<menshoes[0][0] ||
            leglength>(menshoes[8][0]+0.8))
        {
            return -1;
        }

        for(i=0;i<9;i++)
        {
            if (leglength>menshoes[i][0])
            {
                j=menshoes[i][1];
            }
        }
        return j;
    }
}

int main()
{

    try
    {

    string first, second;
    int k;
    cout << "Foot length (ex: 9.5 in or 24.1 cm): " << endl;
    getline(std::cin,first);
    cout << "W)omens or M)ens: " << endl;
    getline(std::cin,second);
    ShoeSizeEstimator c(first,second);
    k=c.MatchingAlgorithm();

    if (k<0)
    {
        cout << "Your leg is is either too small or too large for our products." << endl;
    }

    if (k==0)
    {
        cout << "We apologize for not carrying your shoe size." << endl;
    }

    if (k>0)
    {
        cout << "Your shoe size is: " << k << endl;
    }

    }

    catch (InputError& theException)
    {
        theException.PrintError();
    }


    return 0;
}
