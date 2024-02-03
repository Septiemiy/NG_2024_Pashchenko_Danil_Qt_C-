#include <iostream>
#include <string>

using namespace std;

int main()
{
    int height;
    cout << "Input the height of the tree: ";
    cin >> height;
    int height_copy = height;

    cout << endl;

    for(int index = 1; index < height * 2; index += 2)
    {
        cout << string(--height_copy, ' ') << string(index, '*') << endl;
    }

    cout << string(--height, ' ') << '*' << endl;
    return 0;
}
