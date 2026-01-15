#include <iostream>
#include <string>
#include "BSNode.hpp"

int main()
{
    //2 array not sorted
    int intArr[15] = { 7, 2, 9, 1, 5, 8, 3, 6, 4, 0, 9, 2, 5, 1, 7 };
    std::string strArr[15] = {
        "dog", "cat", "apple", "zebra", "banana",
        "lion", "tiger", "ant", "cow", "duck",
        "bee", "horse", "fish", "goat", "elephant"
    };
    for (int i = 0; i < 15; i++)
    {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 15; i++)
    {
        std::cout << strArr[i] << " ";
    }
    std::cout << std::endl;
}