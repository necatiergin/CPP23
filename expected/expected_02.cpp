// source : Daily bit(e) of C++ | std::expected, monadic interface | by Šimon Tóth | Dec, 2023 | Medium

#include <expected>
#include <system_error>
#include <string>

std::expected<std::string, std::error_condition> read_input();

std::expected<int, std::error_condition> to_int(const std::string& s);
int add_ten(int v);

std::expected<int, std::error_condition> log_error(const std::error_condition& err);

int main()
{
	auto result = read_input()
	.and_then(to_int) // invoked if the expected contains a value
	// the callable has to return a std::expected, but can change
	// the type: std::expected<T,Err> -> std::expected<U,Err>
	.transform(add_ten) // invoked if the expected contains a value
	// the callable can return any type
	// std::expected<T,Err> -> std::expected<U,Err>
	.or_else(log_error); // invoked if the expected contains an error
	// the callable has to return a std::expected, but can change
	// the type: std::expected<V,T> -> std::expected<V,U>
}
