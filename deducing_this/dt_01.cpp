#include <iostream>

struct Nec {
    void foo(this Nec& self)
    {
        std::cout << "&self = " << &self << '\n';
    }

    void bar(this Nec selfcopy)
    {
        std::cout << "&selfcopy = " << &selfcopy << '\n';
    }
};


int main()
{
    Nec x{};

    std::cout << "&x = " << &x << '\n';
    x.foo();
    x.bar();
}
