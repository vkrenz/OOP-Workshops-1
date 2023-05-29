#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> intStack;

    intStack.push(123).push(22).push(333);

    int depth = (int) intStack;
    std::cout << "Int stack depth: " << depth << std::endl;

    intStack.pop();
    std::cout << "Int stack depth: " << depth << std::endl;
    while (!intStack) {
        std::cout << intStack.pop() << std::endl;
    }

    Stack<double> dStack;

    dStack.push(3.4);
    std::cout << "Double stack depth: " << dStack.depth() << std::endl;
    while (!dStack) {
        std::cout << dStack.pop() << std::endl;
    }
}