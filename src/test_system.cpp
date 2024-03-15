#include "../inc/Stackskkk.hpp"


#include <iostream>
#include <functional>


template<typename T>
void checker(const T &result, const T &answer)
{
    std::cout << (result == answer ? "TRUE " : "FALSE ") << std::endl;
}


int counter = 1;
void tester(const std::function<void()> &func)
{
    printf("::::::TEST_%d:::::: ", counter);
    counter++;
    try
    {
        func();
    }
    catch (const char *msg)
    {
        std::cout << "TRUE ";
        std::cout << msg << std::endl;
    }
}


template<typename T>
void PUSHTEST(Stack<T> &stack, const T item)
{
    tester([&]() -> void {stack.push(item); checker(stack.top(), item);});
}

template<typename T>
void POPTEST(Stack<T> &stack, const T item)
{
    tester([&]() -> void {stack.pop(); stack.isempty() ? checker("", "") : checker(stack.top(), item);});
}

template<typename T>
void TOPTEST(const Stack<T> &stack, const T item)
{
    tester([&]() -> void {checker(stack.top(), item);});
}

template<typename T>
void ISEMPTYTEST(const Stack<T> &stack, const bool &answer)
{
    tester([&]() -> void {checker(stack.isempty(), answer);});
}

template<typename T>
void ISEQUALTEST(const Stack<T> &stackleft, const Stack<T> &stackright, const bool &answer)
{
    tester([&]() -> void {checker(stackleft.isequal(stackright), answer);});
}

template<typename T>
void WSIZETEST(const Stack<T> &stack, const int answer)
{
    tester([&]() -> void {checker(stack.wsize(), answer);});
}

template<typename T>
void COPYCTEST(const Stack<T> &stack)
{
    tester([&]() -> void {const Stack<T>& stackcopy(stack); checker(stack.isequal(stackcopy), true);});
}

template<typename T>
void COPYATEST(const Stack<T> &stack)
{
    tester([&]() -> void {const Stack<T>& stackcopy(stack); checker(stack.isequal(stackcopy), true);});
}

template<typename T>
void MOVECTEST(const Stack<T> &stack)
{
    tester([&]() -> void {Stack<T> stacktemp(stack), stackmove(std::move(stacktemp)); checker(stack.isequal(stackmove), true);});
}

template<typename T>
void MOVEATEST(const Stack<T> &stack)
{
    tester([&]() -> void {Stack<T> stacktemp(stack), stackmove = std::move(stacktemp); checker(stack.isequal(stackmove), true);});
}


void intstackchecker()
{
    std::cout << "intstackchecking" << std::endl;
    int something;
    Stack<int> StackDefault, StackEmpty;

    ISEQUALTEST(StackDefault, StackEmpty, true);
    PUSHTEST(StackDefault, 12);
    PUSHTEST(StackDefault, 23);
    PUSHTEST(StackDefault, 34);
    ISEQUALTEST(StackDefault, StackEmpty, false);
    POPTEST(StackDefault, 23);
    POPTEST(StackDefault, 12);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    PUSHTEST(StackDefault, 56);
    PUSHTEST(StackDefault, 78);
    PUSHTEST(StackDefault, 910);
    TOPTEST(StackDefault, 910);
    POPTEST(StackDefault, 78);
    TOPTEST(StackDefault, 78);
    POPTEST(StackDefault, 56);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    TOPTEST(StackDefault, something);
    ISEMPTYTEST(StackDefault, true);
    PUSHTEST(StackDefault, 214);
    ISEMPTYTEST(StackDefault, false);
    PUSHTEST(StackDefault, 421);
    PUSHTEST(StackDefault, 958);
    WSIZETEST(StackDefault, 3);
    PUSHTEST(StackDefault, 58);
    WSIZETEST(StackDefault, 4);
    COPYCTEST(StackDefault);
    COPYATEST(StackDefault);
    MOVECTEST(StackDefault);
    MOVEATEST(StackDefault);

    std::cout << "intstackchecked" << std::endl;
}

void doublestackchecker()
{
    std::cout << "doublestackchecking" << std::endl;
    double something;
    Stack<double> StackDefault, StackEmpty;

    ISEQUALTEST(StackDefault, StackEmpty, true);
    PUSHTEST(StackDefault, 12.12);
    PUSHTEST(StackDefault, 23.23);
    PUSHTEST(StackDefault, 34.34);
    ISEQUALTEST(StackDefault, StackEmpty, false);
    POPTEST(StackDefault, 23.23);
    POPTEST(StackDefault, 12.12);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    PUSHTEST(StackDefault, 56.56);
    PUSHTEST(StackDefault, 78.78);
    PUSHTEST(StackDefault, 910.91);
    TOPTEST(StackDefault, 910.91);
    POPTEST(StackDefault, 78.78);
    TOPTEST(StackDefault, 78.78);
    POPTEST(StackDefault, 56.56);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    TOPTEST(StackDefault, something);
    ISEMPTYTEST(StackDefault, true);
    PUSHTEST(StackDefault, 214.);
    ISEMPTYTEST(StackDefault, false);
    PUSHTEST(StackDefault, 421.421);
    PUSHTEST(StackDefault, 958.958);
    WSIZETEST(StackDefault, 3);
    PUSHTEST(StackDefault, 58.58);
    WSIZETEST(StackDefault, 4);
    COPYCTEST(StackDefault);
    COPYATEST(StackDefault);
    MOVECTEST(StackDefault);
    MOVEATEST(StackDefault);

    std::cout << "doublestackchecked" << std::endl;
}

void boolstackchecker()
{
    std::cout << "boolstackchecking" << std::endl;
    bool something;
    Stack<bool> StackDefault, StackEmpty;

    ISEQUALTEST(StackDefault, StackEmpty, true);
    PUSHTEST(StackDefault, true);
    PUSHTEST(StackDefault, false);
    PUSHTEST(StackDefault, true);
    ISEQUALTEST(StackDefault, StackEmpty, false);
    POPTEST(StackDefault, false);
    POPTEST(StackDefault, true);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    PUSHTEST(StackDefault, true);
    PUSHTEST(StackDefault, true);
    PUSHTEST(StackDefault, false);
    TOPTEST(StackDefault, false);
    POPTEST(StackDefault, true);
    TOPTEST(StackDefault, true);
    POPTEST(StackDefault, true);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    TOPTEST(StackDefault, something);
    ISEMPTYTEST(StackDefault, true);
    PUSHTEST(StackDefault, true);
    ISEMPTYTEST(StackDefault, false);
    PUSHTEST(StackDefault, true);
    PUSHTEST(StackDefault, true);
    WSIZETEST(StackDefault, 3);
    PUSHTEST(StackDefault, false);
    WSIZETEST(StackDefault, 4);
    COPYCTEST(StackDefault);
    COPYATEST(StackDefault);
    MOVECTEST(StackDefault);
    MOVEATEST(StackDefault);

    std::cout << "boolstackchecked" << std::endl;
}

void strstackchecker()
{
    std::cout << "strstackchecking" << std::endl;
    std::string something;
    Stack<std::string> StackDefault, StackEmpty;

    std::string str (26, 'f');
    std::string chars (34, 's');
    std::string sequence (18, 'd');

    ISEQUALTEST(StackDefault, StackEmpty, true);
    PUSHTEST(StackDefault, str);
    PUSHTEST(StackDefault, chars);
    PUSHTEST(StackDefault, sequence);
    ISEQUALTEST(StackDefault, StackEmpty, false);
    POPTEST(StackDefault, chars);
    POPTEST(StackDefault, str);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    PUSHTEST(StackDefault, sequence);
    PUSHTEST(StackDefault, chars);
    PUSHTEST(StackDefault, sequence);
    TOPTEST(StackDefault, sequence);
    POPTEST(StackDefault, chars);
    TOPTEST(StackDefault, chars);
    POPTEST(StackDefault, sequence);
    POPTEST(StackDefault, something);
    POPTEST(StackDefault, something);
    TOPTEST(StackDefault, something);
    ISEMPTYTEST(StackDefault, true);
    PUSHTEST(StackDefault, sequence);
    ISEMPTYTEST(StackDefault, false);
    PUSHTEST(StackDefault, str);
    PUSHTEST(StackDefault, something);
    WSIZETEST(StackDefault, 3);
    PUSHTEST(StackDefault, chars);
    WSIZETEST(StackDefault, 4);
    COPYCTEST(StackDefault);
    COPYATEST(StackDefault);
    MOVECTEST(StackDefault);
    MOVEATEST(StackDefault);

    std::cout << "strstackchecked" << std::endl;
}


int main()
{
    intstackchecker();
    doublestackchecker();
    boolstackchecker();
    strstackchecker();
}