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
    //create trees and insert elements from arrays
    BSNode<int> intTree(intArr[0]);
    for (int i = 1; i < 15; i++)
    {
        intTree.insert(intArr[i]);
    }
    BSNode<std::string> strTree(strArr[0]);
    for (int i = 1; i < 15; i++)
    {
        strTree.insert(strArr[i]);
    }
    //print trees in order
    std::cout << "\nSorted int array:\n";
    intTree.printNodes();
    std::cout << "\nSorted string array:\n";
    strTree.printNodes();

	return 0;
}