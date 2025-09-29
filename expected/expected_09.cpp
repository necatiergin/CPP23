#include <expected>
#include <string>
#include <iostream>

std::expected<int, std::string> get_id(const std::string& s)
{
	if (s.empty())
		return std::unexpected("no id!");

	return 42;
}

int main()
{
	auto name = get_id("ali")
	.transform([](int id) { return "user#" + std::to_string(id); });

	if (name)
		std::cout << *name << '\n';
	else
		std::cout << name.error() << '\n';
}



