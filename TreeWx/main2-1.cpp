#include "Functions.h"
#include <iostream>

// A simple class to test 
class MyClass
{
public:
    int value;

    MyClass(int v = 0) : value(v) {}

    bool operator>(const MyClass& other) const
    {
        return value > other.value;
    }

    bool operator==(const MyClass& other) const
    {
        return value == other.value;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj)
    {
        os << obj.value;
        return os;
    }
};





int main() 
{
    //check compare
    std::cout << "correct print is 1 -1 0" << std::endl; 
    std::cout << compare<double>(1.0, 2.5) << std::endl; 
    std::cout << compare<double>(4.5, 2.4) << std::endl; 
    std::cout << compare<double>(4.4, 4.4) << std::endl;

    //check bubbleSort
    std::cout << "correct print is sorted array" << std::endl;
    const int arr_size = 5;
    double doubleArr[arr_size] = { 1000.0, 2.0, 3.4, 17.0, 50.0 };
    bubbleSort<double>(doubleArr, arr_size);
    for (int i = 0; i < arr_size; i++) 
    {
        std::cout << doubleArr[i] << " ";
    }
    std::cout << std::endl;

    //check printArray
    std::cout << "correct print is sorted array" << std::endl;
    printArray<double>(doubleArr, arr_size);
    std::cout << std::endl;


    system("pause");
    return 1;
}