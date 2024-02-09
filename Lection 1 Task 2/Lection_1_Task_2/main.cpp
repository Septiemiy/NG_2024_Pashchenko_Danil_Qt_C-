#include <iostream>

using namespace std;

int main()
{
    cout << "Input your income: ";
    int income = 0;
    cin >> income;

    if(income < 1000)
    {
        cout << "Work more!";
        return 0;
    }
    if(income > 1000000)
        cout << "Your millionaier!";
    if(income < 1000000)
        cout << "Good job!";

    return 0;
}
