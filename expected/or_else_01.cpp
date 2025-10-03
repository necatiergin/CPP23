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

std::expected<double, std::string> bar(int x)
{
	std::cout << "bar(int x) called! x = " << x << '\n';
	if (x % 10 == 6) {
		return std::unexpected{ "bar: last digit can not be 6" };
	}

	return 1.5 * x;
}

std::expected<double, int> baz(const std::string& s)
{
	std::cout << "baz(const string& s) called! s = " << s << '\n';
	
	return std::unexpected{ -1 };
}

int main()
{
	if (auto ex = foo(54).and_then(bar).or_else(baz)) {
		std::cout << "value : "<<  *ex << '\n';
	}
	else {
		std::cout << "error: " << ex.error() << '\n';
	}
}
