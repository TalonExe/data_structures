#include <iostream>
#include <string>

#include "array.hpp"
#include "linkedlist.hpp"

int main()
{
    std::cout << "--- Testing CustomArray<int> ---\n";
    MyDS::CustomArray<int> numbers;
    numbers.push_back(5);
    numbers.push_back(10);
    std::cout << "Array size: " << numbers.size() << "\n";
    std::cout << "Element at index 1: " << numbers[1] << "\n\n";

    std::cout << "--- Testing CustomLinkedList<std::string> ---\n";
    MyDS::CustomLinkedList<std::string> list;
    list.push_front("World");
    list.push_front("Hello");
    std::cout << "List size: " << list.size() << "\n";
    std::cout << "Front element: " << list.front() << "\n";
    list.pop_front();
    std::cout << "Front element after pop: " << list.front() << "\n";
    std::cout << "List size: " << list.size() << "\n";

    return 0;
}