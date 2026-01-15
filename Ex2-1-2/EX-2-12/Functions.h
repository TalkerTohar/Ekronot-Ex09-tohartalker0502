#pragma once
#include <iostream>

//qeustion 1
template <typename T>
int compare(const T& a, const T& b)
{
    if (a > b)
    {
        return -1;
    }
    if (a == b)
    {
        return 0;
    }
    return 1;
}

//question 2
template <typename T>
void bubbleSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (compare(arr[j], arr[j + 1]) == -1)
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//question 3
template <typename T>
void printArray(const T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}