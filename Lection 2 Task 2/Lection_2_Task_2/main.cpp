#include <iostream>

using namespace std;

int array_size = 0;

void array_size_init()
{
    cout << "Input array size: ";
    cin >> array_size;
    cout << endl;
}

void max_min_number(int* array)
{
    int max = 0;
    int min = 0;
    int temp = 0;
    for(int index = 0; index < array_size; index ++)
    {
        for(int index = 0; index < array_size - 1; index++)
        {
            if(array[index] > array[index + 1])
            {
                temp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = temp;
            }
        }
    }

    max = array[array_size - 1];
    min = array[0];

    cout << endl << "Max number in array: " << max;
    cout << endl << "Mix number in array: " << min;
}

int main()
{
    array_size_init();
    int array[array_size];

    cout << "Input array elements: ";
    for(int index = 0; index < array_size; index++)
    {
        cin >> array[index];
    }

    max_min_number(array);
    return 0;
}
