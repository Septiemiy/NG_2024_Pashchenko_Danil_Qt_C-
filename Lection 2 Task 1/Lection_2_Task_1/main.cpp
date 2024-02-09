#include <iostream>

using namespace std;

int array_size = 0;

void array_size_init()
{
    cout << "Input array size: ";
    cin >> array_size;
    cout << endl;
}

void sum_array_numbers(int* array)
{
    int sum = 0;
    for(int index = 0; index < array_size; index++)
    {
        sum += array[index];
    }

    cout << endl << "Sum of the all array numbers: " << sum;
}

void sum_even_array_numbers(int* array)
{
    int sum = 0;
    for(int index = 0; index < array_size; index++)
    {
        if(array[index] % 2 == 0)
            sum += array[index];
    }

    cout << endl << "Sum of the all even number in array: " << sum;
}

void sum_odd_array_numbers(int* array)
{
    int sum = 0;
    for(int index = 0; index < array_size; index++)
    {
        if(array[index] % 2 != 0)
            sum += array[index];
    }

    cout << endl << "Sum of the all odd number in array: " << sum;
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

    sum_array_numbers(array);
    sum_even_array_numbers(array);
    sum_odd_array_numbers(array);

    return 0;
}
