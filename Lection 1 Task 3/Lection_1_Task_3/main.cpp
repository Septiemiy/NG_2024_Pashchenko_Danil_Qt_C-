#include <iostream>

using namespace std;

int main()
{
    int height;
    cout << "Input the height of the tree: ";
    cin >> height;
    int height_copy = height;
    int main_index = 0;

    cout << endl;

    for(int index = 1; index < height * 2; index += 2)
    {
        for(int index = 0; index < height_copy; index++)
        {
            cout << ' ';
        }
        height_copy--;
        while(main_index != index)
        {
            cout << '*';
            main_index++;
        }
        main_index = 0;
        cout << endl;
    }

    do
    {
        cout << ' ';
        main_index++;
    }while(main_index != height);
    cout << '*' << endl;

    return 0;
}
