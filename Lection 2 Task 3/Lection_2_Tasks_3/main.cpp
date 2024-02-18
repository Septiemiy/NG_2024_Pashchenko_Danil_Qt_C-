#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int *array = new int[1]{};
    int element = 1;
    int index = 0;
    int lenght = 0;
    int main_index = 0;
    int max_element = 0;

    cout << "Input array elements (print '0' to stop input): ";

    while(element != 0)
    {
        cin >> element;
        array[index] = element;
        index++;
        lenght++;
        if(element > max_element)
        {
            max_element = element;
        }
    };

    cout << endl;

    for(int index = 0; index < lenght - 1; index++)
    {
        for(int second_index = max_element; second_index > array[index]; second_index -= 2)
        {
            cout << ' ';
        }
        while(main_index != array[index])
        {
            cout << '*';
            main_index++;
        }
        main_index = 0;
        cout << endl;
    }

    delete[] array;

    return 0;
}
