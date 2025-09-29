#include <expected>
#include <charconv>
#include <string>
#include <string_view>

std::expected<int, std::string>
parse_int(std::string_view sv) 
{
    int value{};
    const char* first = sv.data();
    const char* last = sv.data() + sv.size();
    auto [ptr, ec] = std::from_chars(first, last, value);
    
    if (ec == std::errc{} && ptr == last)
        return value; // success (implicit expected<int,std::string>{value})
    
    return std::unexpected(std::string{ "invalid integer: " } + std::string(sv));
}

void parse() 
{
    if (auto r = parse_int("42")) {    // r.operator bool() called
        int x = r.value();   
        //...
    }
    else {
        const std::string& msg = r.error(); // no-throw access to error
        //...
    }
}
