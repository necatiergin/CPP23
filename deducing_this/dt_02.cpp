#include <cstdio>

struct Base { 
    void name(this auto&& self) 
    {
        self.impl();
    } 
};

struct A : public Base {
    void impl()
    {
        std::puts("A::impl()"); 
    } 
};

struct B : public Base {
    void impl() 
    {
        std::puts("B::impl()");
    } 
};


int main()
{
    A ax;
    ax.name();
    B bx;
    bx.name();
}
