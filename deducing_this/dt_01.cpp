#include <iostream>

struct Widget {
    void foo(this Widget& self)
    {
        std::cout << "&self = " << &self << '\n';
    }
    
    void bar(this Widget selfcopy)
    {
        std::cout << "&selfcopy = " << &selfcopy << '\n';
    }
};


int main()
{
    Widget x{};

    std::cout << "&x = " << &x << '\n';
    x.foo();
    x.bar();
}

