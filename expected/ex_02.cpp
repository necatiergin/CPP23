// from cppreference.com

#include <cassert>
#include <expected>
#include <iomanip>
#include <iostream>
#include <string>
 
int main()
{
    using namespace std::string_literals;
 
    std::expected<int, std::string> ex1 = 6;
    assert(*ex1 == 6);
 
    *ex1 = 9;
    assert(*ex1 == 9);
 
    ex1 = std::unexpected("error"s);
    // *ex1 = 13 // UB, ex1 contains "unexpected" value
    assert(ex1.value_or(42) == 42);
 
    std::expected<std::string, bool> ex2 = "Moon"s;
    std::cout << "ex2: " << std::quoted(*ex2) << ", size: " << ex2->size() << '\n';
 
    // You can "take" the contained value by calling operator* on an rvalue to expected
 
    auto taken = *std::move(ex2);
    std::cout << "taken: " << std::quoted(taken) << "\n"
                 "ex2: " << std::quoted(*ex2) << ", size: " << ex2->size() << '\n';
}
