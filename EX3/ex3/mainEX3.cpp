#include <iostream>
#include <string>
#include "BSNode.hpp"

int main()
{
    // א. שני מערכים לא ממוינים בגודל 15
    int intArr[15] = { 7, 2, 9, 1, 5, 8, 3, 6, 4, 0, 9, 2, 5, 1, 7 };
    std::string strArr[15] = {
        "dog", "cat", "apple", "zebra", "banana",
        "lion", "tiger", "ant", "cow", "duck",
        "bee", "horse", "fish", "goat", "elephant"
    };

    // ב. הדפסת המערכים הלא ממוינים
    for (int i = 0; i < 15; i++)
        std::cout << intArr[i] << " ";
    std::cout << std::endl;

    for (int i = 0; i < 15; i++)
        std::cout << strArr[i] << " ";
    std::cout << std::endl;

    // ג. הכנסת המערכים לעצים
    BSNode<int> intTree(intArr[0]);
    for (int i = 1; i < 15; i++)
        intTree.insert(intArr[i]);

    BSNode<std::string> strTree(strArr[0]);
    for (int i = 1; i < 15; i++)
        strTree.insert(strArr[i]);

    // ד. הדפסת המערכים לאחר מיון (in-order)
    std::cout << "\nSorted int array:\n";
    intTree.printNodes();

    std::cout << "\nSorted string array:\n";
    strTree.printNodes();

    return 0;
}