#include <expected>
#include <string>
#include <iostream>

// or_else hata tutan bir expected döndürmek zorunda değil

std::expected<int, std::string> get_id(bool ok) 
{
    if (ok)
        return 42;
    
    return std::unexpected("id is missing");
}

int main() 
{
    auto id = get_id(false).or_else([](const std::string& err) {
        std::cout << "get_id failed: " << err << '\n';
        return std::expected<int, std::string>{0}; // fallback value
        });

    std::cout << "id = " << *id << '\n'; 
}
