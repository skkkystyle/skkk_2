#include "../inc/Stackskkk.hpp"


#include <iostream>


int main()
{
//    printf("haha");
    Stack<int> name;
    name.push(4);
    name.push(6);
//    Stack<int> name1(name);
    std::cout << name.top();
}