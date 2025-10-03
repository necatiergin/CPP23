#include <expected>
#include <string>
#include <iostream>

std::expected<int, std::string> foo(int x)
{
	std::cout << "foo(int x) called! x = " << x << '\n';
	if (x % 2 == 0)
		return x / 2;

	return std::unexpected{ "foo doesn't accept odd number\n" };
}

int main()
{
	if (auto ex = foo(12))
		std::cout << "value is : " << *ex << '\n';
	else
		std::cout << "error : " << ex.error() << '\n';

	if (auto ex = foo(5))
		std::cout << "value is : " << *ex << '\n';
	else
		std::cout << "error : " << ex.error() << '\n';

}
