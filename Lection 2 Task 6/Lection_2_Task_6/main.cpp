#include <iostream>

using namespace std;

int get_bank_card_number()
{
    int card_number = 0;
    cout << "Input bank card number: ";
    cin >> card_number;
    if(card_number > 10)
        get_bank_card_number();
    return card_number;
}

int update_money()
{
    int money = 0;
    cout << "Input amount of money, which you want to put on the card: ";
    cin >> money;
    return money;
}

int main()
{
    int bank_accounts[10] = {0,0,0,0,0,0,0,0,0,0};

    while(true)
    {
        int card_number = get_bank_card_number();
        bank_accounts[card_number - 1] += update_money();

        cout <<  endl;

        for(int index = 0; index < 10; index++)
        {
            cout << bank_accounts[index] << ' ';
        }

        cout << endl << endl;
    }

    return 0;
}
