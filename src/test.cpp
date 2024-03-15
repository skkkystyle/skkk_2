#include "../inc/Stackskkk.hpp"


#include <iostream>


#define SIMPLIFY do{DISPLAYING try{line = __LINE__;
#define DISPLAYING printf("::::::TEST_%d:::::: ", counter); counter++;
#define CHECK(x, y) checker(std::to_string(x), std::to_string(y))
#define CATCHER catch(const char *msg){std::cout << msg << "Error in the line " << line << std::endl;}} while (0)


#define ISEQUALTEST(StackCmp, ans) SIMPLIFY CHECK(StackDefault.isequal(StackCmp), ans);} CATCHER
#define PUSHTEST(item) SIMPLIFY StackDefault.push(item); CHECK(StackDefault.top(), item);} CATCHER
#define STRPUSHTEST(item) SIMPLIFY StackDefault.push(item); checker(StackDefault.top(), item);} CATCHER
#define POPTEST SIMPLIFY StackDefault.pop(); CHECK(true, true);} CATCHER
#define TOPTEST(ans) SIMPLIFY CHECK(StackDefault.top(), ans);} CATCHER
#define STRTOPTEST(ans) SIMPLIFY checker(StackDefault.top(), ans);} CATCHER
#define ISEMPTYTEST(ans) SIMPLIFY CHECK(StackDefault.isempty(), ans);} CATCHER
#define WSIZETEST(ans) SIMPLIFY CHECK(StackDefault.wsize(), ans);} CATCHER
#define COPYCTEST(type) SIMPLIFY Stack<type> StackCopyC(StackDefault); CHECK(StackDefault.isequal(StackCopyC), true);} CATCHER
#define COPYATEST(type) SIMPLIFY Stack<type> StackCopyA = StackDefault; CHECK(StackDefault.isequal(StackCopyA), true);} CATCHER
#define MOVECTEST(type) SIMPLIFY Stack<type> StackTemp(StackDefault), StackMoveC(std::move(StackDefault)); CHECK(StackTemp.isequal(StackMoveC), true);} CATCHER
#define MOVEATEST(type) SIMPLIFY Stack<type> copy(StackDefault), StackMoveA = std::move(StackDefault); CHECK(StackDefault.isequal(StackMoveA), true);} CATCHER


int counter = 1, line;
void checker(std::string result, std::string answer)
{
    if (result == answer)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
}


void intstackchecker()
{
    std::cout << "intstackchecking" << std::endl;
    int something;
    Stack<int> StackDefault, StackEmpty;

    ISEQUALTEST(StackEmpty, true);
    PUSHTEST(12);
    PUSHTEST(23);
    PUSHTEST(34);
    ISEQUALTEST(StackEmpty, false);
    POPTEST;
    POPTEST;
    POPTEST;
    POPTEST;
    POPTEST;
    PUSHTEST(56);
    PUSHTEST(78);
    PUSHTEST(910);
    TOPTEST(910);
    POPTEST;
    TOPTEST(78);
    POPTEST;
    POPTEST;
    POPTEST;
    TOPTEST(something);
    ISEMPTYTEST(true);
    PUSHTEST(214);
    ISEMPTYTEST(false);
    PUSHTEST(421);
    PUSHTEST(958);
    WSIZETEST(3);
    PUSHTEST(58);
    WSIZETEST(4);
    COPYCTEST(int);
    COPYATEST(int);
    MOVECTEST(int);
    MOVEATEST(int);
    std::cout << "intstackchecked" << std::endl;
}

void doublestackchecker()
{
    std::cout << "doublestackchecking" << std::endl;
    double something;
    Stack<double> StackDefault, StackEmpty;

    ISEQUALTEST(StackEmpty, true);
    PUSHTEST(12.12);
    PUSHTEST(23.23);
    PUSHTEST(34.34);
    ISEQUALTEST(StackEmpty, false);
    POPTEST;
    POPTEST;
    POPTEST;
    POPTEST;
    POPTEST;
    PUSHTEST(56.56);
    PUSHTEST(78.78);
    PUSHTEST(910.91);
    TOPTEST(910.91);
    POPTEST;
    TOPTEST(78.78);
    POPTEST;
    POPTEST;
    POPTEST;
    TOPTEST(something);
    ISEMPTYTEST(true);
    PUSHTEST(214.);
    ISEMPTYTEST(false);
    PUSHTEST(421.421);
    PUSHTEST(958.958);
    WSIZETEST(3);
    PUSHTEST(58.58);
    WSIZETEST(4);
    COPYCTEST(double);
    COPYATEST(double);
    MOVECTEST(double);
    MOVEATEST(double);
    std::cout << "doublestackchecked" << std::endl;
}

void boolstackchecker()
{
    std::cout << "boolstackchecking" << std::endl;
    bool something;
    Stack<bool> StackDefault, StackEmpty;

    ISEQUALTEST(StackEmpty, true);
    PUSHTEST(true);
    PUSHTEST(false);
    PUSHTEST(true);
    ISEQUALTEST(StackEmpty, false);
    POPTEST;
    POPTEST;
    POPTEST;
    POPTEST;
    POPTEST;
    PUSHTEST(true);
    PUSHTEST(true);
    PUSHTEST(false);
    TOPTEST(false);
    POPTEST;
    TOPTEST(true);
    POPTEST;
    POPTEST;
    POPTEST;
    TOPTEST(something);
    ISEMPTYTEST(true);
    PUSHTEST(false);
    ISEMPTYTEST(false);
    PUSHTEST(true);
    PUSHTEST(true);
    WSIZETEST(3);
    PUSHTEST(false);
    WSIZETEST(4);
    COPYCTEST(bool);
    COPYATEST(bool);
    MOVECTEST(bool);
    MOVEATEST(bool);
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

    ISEQUALTEST(StackEmpty, true);
    STRPUSHTEST(str);
    STRPUSHTEST(chars);
    STRPUSHTEST(sequence);
    ISEQUALTEST(StackEmpty, false);
    POPTEST;
    POPTEST;
    POPTEST;
    POPTEST;
    POPTEST;
    STRPUSHTEST(sequence);
    STRPUSHTEST(chars);
    STRPUSHTEST(sequence);
    STRTOPTEST(sequence);
    POPTEST;
    STRTOPTEST(chars);
    POPTEST;
    POPTEST;
    POPTEST;
    STRTOPTEST(something);
    ISEMPTYTEST(true);
    STRPUSHTEST(sequence);
    ISEMPTYTEST(false);
    STRPUSHTEST(str);
    STRPUSHTEST(something);
    WSIZETEST(3);
    STRPUSHTEST(chars);
    WSIZETEST(4);
    COPYCTEST(std::string);
    COPYATEST(std::string);
    MOVECTEST(std::string);
    MOVEATEST(std::string);
    std::cout << "strstackchecked" << std::endl;
}


int main()
{
    intstackchecker();
    doublestackchecker();
    boolstackchecker();
    strstackchecker();
}
