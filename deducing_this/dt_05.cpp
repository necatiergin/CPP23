#include <string>
#include <utility>
#include <iostream>

struct Nec {

	std::string str{ "necati ergin" };
	template <typename Self>
	decltype(auto) get(this Self&& s)
	{
		return std::forward<Self>(s).str;
	}
};

int main()
{
	Nec mynec{};

	auto s = std::move(mynec).get();

	std::cout << s.length() << mynec.str.length();
}
